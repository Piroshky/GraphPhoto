#pragma once
#include <imgui.h>
#include <gegl.h>
#include <gegl-plugin.h>
#include <gegl-types.h>
#include <vector>

namespace GPNode {

enum NODE_DRAW_TYPE {CUSTOM, GEGL, CANVAS};
enum PROPERTY_DIRECTION {INPUT, OUTPUT};

struct NodeProperty {
  int     id;
  int     node_id;
  char   *label;
  PROPERTY_DIRECTION direction;
  GType   gtype;
  ImRect  rect;
  ImVec2  pin_pos;
  bool    hovered;
};

struct Node {
  int     id;
  ImVec2  pos;
  ImRect  size;
  int     layer;
  bool    mouse_in_node;
  bool    hovered;

  NODE_DRAW_TYPE draw_type;
  GeglOperationClass *gegl_operation_klass;
  GeglNode *gegl_node;
  GeglBuffer  *gegl_buffer;
  ImTextureID  texture;
  ImVec2       texture_size;
  
  std::vector<int> gegl_input_pads;
  std::vector<int> gegl_output_pads;
  std::vector<int> input_properties;
    
  Node(int id)
    : id(id),
      pos({0,0}),
      size(0,0,0,0),
      layer(0),
      mouse_in_node(false),
      hovered(false),
      draw_type(CUSTOM)
  {}
};

struct Link {
  int start_id;
  int end_id;

  Link(int start_id, int end_id) :
    start_id(start_id),
    end_id(end_id)
  {}
};

enum NodeEditorMouseState {
  NONE,
  IMGUI_INTERACTION,
  DRAGGING_NODES,
  DRAG_SELECTION,
  CREATE_LINK
};

const char *mouse_state_string(NodeEditorMouseState s);

struct NodeEditor {
  std::vector<Node> node_pool;
  std::vector<NodeProperty> pin_pool;
  std::vector<Link> link_pool;
  
  Node   *current_node;
  int     num_nodes;
  int     num_links;
  ImVec2  canvas_scrolling;
  bool    mouse_in_canvas;
  ImVec2  origin;
  bool    grid_enabled;
  double  zoom;    

  NodeEditorMouseState mouse_state;
  std::vector<int> selected_nodes;
  //bool    dragging_selected_nodes; // "dragging" here is not the same drag as below, this is for moving nodes.
  //bool    drag_selection;          // Whereas in these two drag refers to the click and drag selection box.
  ImVec2  drag_start;              //
  int active_node = -1;
  int active_pin = -1;
    
  ImVec2 screen_space_MousePos;
  ImVec2 mouse_pos_in_canvas;

  //ImDrawList* draw_list;
  int vtx_ix; //  = draw_list->VtxBuffer.size();
  int canvas_clip_rect_ix;
  ImVec2  canvas_p0;
  ImVec2  canvas_p1;

  int Style_NodeMargin = 10;
  int Style_NodeOutlineWidth = 2;
  int Style_PinRadius = 5;
    
  GeglNode *graph;
    
};
  
void InitializeNodeEditor();
void BeginNodeEditor();
void EndNodeEditor();

void BeginNode(int node_id);
void EndNode();
void BeginNodeInput(int id);
void EndNodeInput();

NodeProperty *FindProperty(int property_id);
Node *FindNode(int node_id);
Node *GetNode(int node_id);
bool NodeSelected(int node_id);

// Functions that are meant to be mainly internal use snake case.
void set_node_to_top_layer(Node *node);
  
extern NodeEditor *global_node_editor;
}
