#pragma once
#include <imgui.h>
#include <vector>

namespace GPNode {

  struct node {
    int     id;
    ImVec2  pos;
    ImRect  size;
    bool    hovered;

  node(int id)
    : id(id),
      pos({0,0}),
      size(0,0,0,0),
      hovered(false)
    {}
  };

  struct NodeEditor {
    std::vector<node> node_pool;
  
    node   *current_node;
    ImVec2  canvas_scrolling;
    bool    grid_enabled;
    double  zoom;


    ImDrawList* draw_list;
  };
  
  void InitializeNodeEditor();
  void BeginNodeEditor();
  void EndNodeEditor();
  extern NodeEditor *global_node_editor;
}
