#include <sstream>
#include <fstream>
#include <cstdint>
#include <cstring>

#include "gpnode.h"

#define GP_FILE_VERSION 1
#define GP_FILE_SIGNATURE "graphphoto"

struct filedata {
  uintmax_t length;
  uintmax_t ix;
  char *data;
};


// #define WRITE_VARIABLE(variable) builder.write(reinterpret_cast<const char*>(&variable), sizeof(variable))

#define WRITE_VARIABLE(builder, variable) write_variable(builder, reinterpret_cast<const char*>(&variable), sizeof(variable))

void write_variable(std::stringstream *builder, const char *var, size_t var_size) {
  builder->write(var, var_size);
}

// Writes the length first, then the string.
// We're going to include the null terminating byte and prepend the size of the string (including the null byte). This just makes things easier.
void write_c_string(std::stringstream *builder, const char *string) {
  uint32_t len = strlen(string) + 1;
  builder->write(reinterpret_cast<const char*>(&len), sizeof(len));
  builder->write(reinterpret_cast<const char*>(string), len);
}

// if (!read_n_bytes_from_filedata(&fd, (std::byte*)&variable, sizeof(variable))) {fprintf(stderr, "Unexpected end of file when trying to read " #variable "\n"); return false;}

void serialize_link(std::stringstream *builder, GPNode::Link *link) {
  WRITE_VARIABLE(builder, link->start_id);
  WRITE_VARIABLE(builder, link->end_id);
}

void serialize_property(std::stringstream *builder, int id) {
  GPNode::NodeProperty *property = GPNode::FindProperty(id);

  WRITE_VARIABLE(builder, id);
  // WRITE_VARIABLE(builder, property->direction);
  write_c_string(builder, property->label);
}

// Gegl pads for all we care are just a number and label
void serialize_gegl_pad(std::stringstream *builder, int property_id) {
  GPNode::NodeProperty *property = GPNode::FindProperty(property_id);
  WRITE_VARIABLE(builder, property->id);
  write_c_string(builder, property->label);
}

void serialize_canvas_node(std::stringstream *builder, GPNode::Node *node) {
  serialize_gegl_pad(builder, node->gegl_input_pads[0]);
}

void serialize_gegl_node(std::stringstream *builder, GPNode::Node *node) {
  // gegl node
  const char *gegl_operation = GEGL_OPERATION_GET_CLASS(gegl_node_get_gegl_operation(node->gegl_node))->name;
  write_c_string(builder, gegl_operation);
  printf("%s\n", gegl_operation);

  // input pads
  uint32_t num_in_pads = node->gegl_input_pads.size();
  WRITE_VARIABLE(builder, num_in_pads);
  for (int id : node->gegl_input_pads) {
    serialize_gegl_pad(builder, id);
  }

  // output pads
  uint32_t num_out_pads = node->gegl_output_pads.size();
  WRITE_VARIABLE(builder, num_out_pads);
  for (int id : node->gegl_output_pads) {
    serialize_gegl_pad(builder, id);
  }
  
  // input properties
  uint32_t num_props = node->input_properties.size();
  WRITE_VARIABLE(builder, num_props);
  for (int id : node->input_properties) {
    serialize_property(builder, id);
  }
  
}

void serialize_node(std::stringstream *builder, GPNode::Node *node) {
  printf("---Serialize Node---\n");
  WRITE_VARIABLE(builder, node->draw_type);
  
  // id
  printf("id %d\n", node->id);
  WRITE_VARIABLE(builder, node->id);

  // pos
  printf("%f, %f\n", node->pos.x, node->pos.y);
  WRITE_VARIABLE(builder, node->pos.x);
  WRITE_VARIABLE(builder, node->pos.y);

  // layer
  printf("%d\n", node->layer);
  WRITE_VARIABLE(builder, node->layer);

  switch (node->draw_type) {
  case GPNode::GEGL:
    return serialize_gegl_node(builder, node);
    break;
  case GPNode::CANVAS:
    return serialize_canvas_node(builder, node);
    break;
  default:
    fprintf(stderr, "Tried to serialize node of unknown type (%d)\n", node->draw_type);
    return;
  }
    
  printf("---END Serialize Node---\n");  
}

void get_whole_file(const char *filename, filedata *fd) {
  std::FILE *fp = std::fopen(filename, "rb");
  if (fp) {
    std::fseek(fp, 0, SEEK_END);
    fd->length = std::ftell(fp);
    char *buffer = new char [fd->length];
    fd->data = buffer;
    std::rewind(fp);
    std::fread(fd->data, 1, fd->length, fp);
    std::fclose(fp);
    fd->ix = 0;    
    return;
  }
  fprintf(stderr, "Failed to open file %s", filename);
  throw(errno);
}

void save_project(GPNode::NodeEditor *editor) {
  // File Signature & Version
  std::stringstream builder;
  builder << GP_FILE_SIGNATURE;
  uint32_t version = GP_FILE_VERSION;
  builder.write(reinterpret_cast<const char*>(&version), sizeof(version));

  // Editor State
  WRITE_VARIABLE(&builder, GPNode::global_node_editor->item_id_count);
  WRITE_VARIABLE(&builder, GPNode::global_node_editor->canvas_scrolling.x);
  WRITE_VARIABLE(&builder, GPNode::global_node_editor->canvas_scrolling.y);
  WRITE_VARIABLE(&builder, GPNode::global_node_editor->grid_enabled);
  WRITE_VARIABLE(&builder, GPNode::global_node_editor->zoom);
  
  // Nodes
  uint32_t num_nodes = editor->num_nodes;
  WRITE_VARIABLE(&builder, num_nodes);    
  for (GPNode::Node &node : GPNode::global_node_editor->node_pool) {
    serialize_node(&builder, &node);
  }

  // Links
  uint32_t num_links = editor->num_links;
  WRITE_VARIABLE(&builder, num_links);
  for (GPNode::Link &link : GPNode::global_node_editor->link_pool) {
    serialize_link(&builder, &link);
  }  

//
  printf("builder size %ld\n", builder.str().size());
//  
  std::ofstream file;
  file.open("./out.save");
  file << builder.rdbuf();
  printf("builder size %ld\n", builder.str().size());
  file.close();
}

// Copies n bytes from fd->data[ix] to dest, returning false if that
// exceeds the size of fd->data
bool read_n_bytes_from_filedata(filedata *fd, std::byte *dest, uintmax_t n) {
  if (fd->ix + n > fd->length) {
    printf("fd->ix : %ld\nn : %ld\nfd-length : %ld\n", fd->ix, n, fd->length);
    return false;
  }
  
  std::memcpy(dest, &(fd->data[fd->ix]), n);
  fd->ix += n;
  return true;
}

#define GET_VARIABLE(fd, variable) read_n_bytes_from_filedata(fd, (std::byte*)&variable, sizeof(variable))

#define GET_VARIABLE_WARN(fd, variable) if (!read_n_bytes_from_filedata(fd, (std::byte*)&variable, sizeof(variable))) {fprintf(stderr, "Unexpected end of file when trying to read " #variable "\n"); return false;}

char* get_c_string(filedata *fd) {
  uint32_t len;  
  bool success = GET_VARIABLE(fd, len);
  if (!success) {
    fprintf(stderr,"Unexpected end of file\n");
    return NULL;
  }
  char *ret = (char*)malloc(len);
  if (ret != NULL) {
    read_n_bytes_from_filedata(fd, (std::byte*)ret, len);
  }
  return ret;
}

bool read_link(filedata *fd) {
  int start_id, end_id;
  GET_VARIABLE_WARN(fd, start_id);
  GET_VARIABLE_WARN(fd, end_id);
  printf("link (%d, %d)\n", start_id, end_id);
  GPNode::CreateLink(start_id, end_id);
  return true;
}

bool read_canvas_node(filedata *fd) {
  int id;
  GET_VARIABLE_WARN(fd, id);

  ImVec2 pos;
  GET_VARIABLE_WARN(fd, pos.x);
  GET_VARIABLE_WARN(fd, pos.y);

  int layer;
  GET_VARIABLE_WARN(fd, layer);

  int property_id;
  GET_VARIABLE_WARN(fd, property_id);
  printf("CAnvas property id %d\n", property_id);
  char * label = get_c_string(fd);
  free(label); //todo I mean what's the point?
  
  int node_id = GPNode::CreateCanvasNode(id, property_id);
  GPNode::Node *node = GPNode::FindNode(node_id);
  node->pos.x = pos.x;
  node->pos.y = pos.y;
  node->layer = layer;
  node->draw_type = GPNode::CANVAS;

  return true;
}

bool read_gegl_node(filedata *fd) {
  int id;
  GET_VARIABLE_WARN(fd, id);

  ImVec2 pos;
  GET_VARIABLE_WARN(fd, pos.x);
  GET_VARIABLE_WARN(fd, pos.y);

  int layer;
  GET_VARIABLE_WARN(fd, layer);

  printf("-----\n\tid %d\n\tx,y %f %f\n\tlayer %d\n", id, pos.x, pos.y, layer);
  
  char *gegl_operation = get_c_string(fd);
  if (!gegl_operation) { return false; }
  printf("gegl_operation %s\n", gegl_operation);

  
  int node_id = GPNode::CreateGeglNode(gegl_operation, id);
  GPNode::Node *node = GPNode::FindNode(node_id);
  node->pos.x = pos.x;
  node->pos.y = pos.y;
  node->layer = layer;
  node->draw_type = GPNode::GEGL;

  // Read input pads
  uint32_t num_in_pads;
  GET_VARIABLE_WARN(fd, num_in_pads);
  printf("num_in_pads %d\n", num_in_pads);  
  for (uint32_t i = 0; i < num_in_pads; ++i) {
    int property_id;
    GET_VARIABLE_WARN(fd, property_id);
    char *label = get_c_string(fd);
    GPNode::SetPropertyId(&(node->gegl_input_pads), label, property_id);
  }

  // Read output pads
  uint32_t num_out_pads;
  GET_VARIABLE_WARN(fd, num_out_pads);
  printf("num_out_pads %d\n", num_out_pads);  
  for (uint32_t i = 0; i < num_out_pads; ++i) {
    int property_id;
    GET_VARIABLE_WARN(fd, property_id);
    char *label = get_c_string(fd);
    GPNode::SetPropertyId(&(node->gegl_output_pads), label, property_id);
  }
  
  // Read input properties
  uint32_t num_props;
  GET_VARIABLE_WARN(fd, num_props);
  printf("num_props %d\n", num_props);  
  for (uint32_t i = 0; i < num_props; ++i) {
    int property_id; 
    GET_VARIABLE_WARN(fd, property_id);
    printf("\tid %d\n", property_id);

    // GPNode::PROPERTY_DIRECTION dir;
    // GET_VARIABLE_WARN(fd, dir); 
 
    char *label = get_c_string(fd);
    if (!label) return false;
    printf("\tlabel %s\n", label);
    GPNode::SetPropertyId(&(node->input_properties), label, property_id);
  }
  return true;
}

bool read_node(filedata *fd) {
  GPNode::NODE_DRAW_TYPE draw_type;
  GET_VARIABLE_WARN(fd, draw_type);

  switch (draw_type) {
  case GPNode::GEGL:
    return read_gegl_node(fd);
    break;
  case GPNode::CANVAS:
    return read_canvas_node(fd);
    break;
  default:
    fprintf(stderr, "unknown node type in save file (%d)\n", draw_type);
    return false;
  }
}

bool open_project(const char *filename) {
  filedata fd{0,0,0};
  get_whole_file(filename, &fd);
  printf("File length: %ld\n", fd.length);

  // Read File Signature
  char signature[] = GP_FILE_SIGNATURE;
  uintmax_t sig_len = sizeof(signature) - 1;
  if (sig_len > fd.length) {
    fprintf(stderr, "File `%s` is not large enough to be a GraphPhoto save file\n", filename);
    return false;
  }  
  int ret = strncmp(fd.data, signature, sig_len);
  if (ret != 0) {
    fprintf(stderr, "File `%s` is not a GraphPhoto save file (%d)\n", filename, ret);
    return false;
  }
  fd.ix += sig_len;
  
  // Read File Version
  uint32_t version;
  GET_VARIABLE_WARN(&fd, version);
  if (version != 1) {
    fprintf(stderr, "GraphPhoto save file `%s` uses an unsported version (%d). This application can only read version 1\n", filename, version);
    return false;
  }  
  printf("version %u\n", version);

  // Read Editor State
  GET_VARIABLE_WARN(&fd, GPNode::global_node_editor->item_id_count);
  GET_VARIABLE_WARN(&fd, GPNode::global_node_editor->canvas_scrolling.x);
  GET_VARIABLE_WARN(&fd, GPNode::global_node_editor->canvas_scrolling.y);
  GET_VARIABLE_WARN(&fd, GPNode::global_node_editor->grid_enabled);
  GET_VARIABLE_WARN(&fd, GPNode::global_node_editor->zoom);

  // Read nodes
  uint32_t num_nodes;
  GET_VARIABLE_WARN(&fd, num_nodes);
  printf("num_nodes %d\n", num_nodes);  
  for (uint32_t i = 0; i < num_nodes; ++i) {
    if (!read_node(&fd)) {
      return false;
    }    
  }

  // Read links
  uint32_t num_links;
  GET_VARIABLE_WARN(&fd, num_links);
  printf("num_links %d\n", num_links);  
  for (uint32_t i = 0; i < num_links; ++i) {
    if (!read_link(&fd)) {
      return false;
    }    
  }

  return true;
}
