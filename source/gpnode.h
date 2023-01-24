#pragma once
#include <imgui.h>
#include <vector>

namespace GPNode {

  struct node {
    int     id;
    ImVec2  pos;
    ImRect  size;
    bool    mouse_in_node;

  node(int id)
    : id(id),
      pos({0,0}),
      size(0,0,0,0),
      mouse_in_node(false)
    {}
  };

  struct NodeEditor {
    std::vector<node> node_pool;
  
    node   *current_node;
    ImVec2  canvas_scrolling;
    bool canvas_hovered;
    ImVec2  origin;
    bool    grid_enabled;
    double  zoom;

    std::vector<int> selected_nodes;
    bool    drag_selection;
    ImVec2  drag_start;
    
    ImVec2 screen_space_MousePos;

    //ImDrawList* draw_list;
    int vtx_ix; //  = draw_list->VtxBuffer.size();
    int canvas_clip_rect_ix;
    ImVec2  canvas_p0;
    ImVec2  canvas_p1;
  };
  
  void InitializeNodeEditor();
  void BeginNodeEditor();
  void EndNodeEditor();

  void BeginNode(int node_id);
  void EndNode();

node *GetNode(int node_id);

  extern NodeEditor *global_node_editor;
}
