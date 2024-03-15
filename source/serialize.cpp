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

void serialize_property(std::stringstream *builder, int id) {
  GPNode::NodeProperty *property = GPNode::FindProperty(id);

  printf("\t%d\n", id);
  WRITE_VARIABLE(builder, id);
  WRITE_VARIABLE(builder, property->direction);
  write_c_string(builder, property->label);

  printf("\t%s\n", property->label);
}


void serialize_node(std::stringstream *builder, GPNode::Node *node) {

  // std::stringstream builder;
  
  printf("---Serialize Node---\n");  
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

  // gegl node
  const char *gegl_operation = GEGL_OPERATION_GET_CLASS(gegl_node_get_gegl_operation(node->gegl_node))->name;
  write_c_string(builder, gegl_operation);
  printf("%s\n", gegl_operation);
  
  // input properties
  printf("num props %ld\n", node->input_properties.size());
  uint32_t num_props = node->input_properties.size();
  WRITE_VARIABLE(builder, num_props);

  for (int id : node->input_properties) {
    serialize_property(builder, id);
  }
  
  char c;
  while (builder.get(c)) {
    printf("%x ", c);
  }
  printf("\n");
  
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
  std::stringstream builder;
  builder << GP_FILE_SIGNATURE;
  uint32_t version = GP_FILE_VERSION;
  builder.write(reinterpret_cast<const char*>(&version), sizeof(version));

  uint32_t num_nodes = editor->num_nodes;
  WRITE_VARIABLE(&builder, num_nodes);
    
  // serealize_node();
  for (uint32_t i = 0; i < num_nodes; ++i) {
    serialize_node
  }
  
  
  std::ofstream file;
  file.open("./out.save");
  file << builder.rdbuf();
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

#define GET_VARIABLE(fd, variable) if (!read_n_bytes_from_filedata(fd, (std::byte*)&variable, sizeof(variable))) {fprintf(stderr, "Unexpected end of file when trying to read " #variable "\n"); return false;}

bool read_node(filedata *fd) {
  int id;
  GET_VARIABLE(fd, id);

  ImVec2 pos;
  GET_VARIABLE(fd, pos.x);
  GET_VARIABLE(fd, pos.y);

  int layer;
  GET_VARIABLE(fd, layer);

  char *gegl_operation;
  get_string(fd, &gegl_operation);

  uint32_t num_props;
  GET_VARIABLE(fd, num_props);
  
  printf("id %d\nx,y %f %f\nlayer %d\n", id, pos.x, pos.y, layer);
  
  return true;
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
  // sizeof(uint32_t)
  uint32_t version;
  GET_VARIABLE(&fd, version);
  if (version != 1) {
    fprintf(stderr, "GraphPhoto save file `%s` uses an unsported version (%d). This application can only read version 1\n", filename, version);
    return false;
  }  
  printf("version %u\n", version);

  uint32_t num_nodes;
  GET_VARIABLE(&fd, num_nodes);
  printf("num_nodes %d\n", num_nodes);

  GPNode::Node *nodes = new GPNode::Node[num_nodes];
  
  for (uint32_t i = 0; i < num_nodes; ++i) {
    if (!read_node(&fd)) {
      return false;
    }    
  }

  // for (uint32_t i = 0; i < num_nodes; ++i) {
  //   printf("id %d\nx %d\ny %d\n\n", nodes[i].id, nodes[i].pos.x, nodes[i].pos.y);
  // }

  
  return true;
}
