#include "imgui_internal.h"
#include "gpnode.h"



namespace GPNode {

NodeEditor *global_node_editor = NULL;

void InitializeNodeEditor() {
  IM_ASSERT(global_node_editor == NULL);
  global_node_editor = IM_NEW(NodeEditor)();

  global_node_editor->grid_enabled = true;
  global_node_editor->zoom = 1;
}

void BeginNodeEditor() {
  ImGuiIO& io = ImGui::GetIO();
}

void EndNodeEditor() {
  
  // If mouse is NOT down, and over a node, highlight the highest level node
  
  // If mouse is down, and over a node, make the highest level node the selected node

}

node *CreateNode(int node_id) {
  global_node_editor->node_pool.emplace_back(node_id);
  return &global_node_editor->node_pool.back();
}

//// get node from node list, or create node with given id
node *GetNode(int node_id) {
  for (auto& node : global_node_editor->node_pool) {
    if (node.id == node_id) {
      return &node;
    }
  }
  return CreateNode(node_id);
}

void BeginNode(int node_id) {
  node *current_node = GetNode(node_id); //Todo implement
  global_node_editor->current_node = current_node;
  
  ImGui::PushID(current_node->id);
  ImGui::BeginGroup();
}

void EndNode() {
  node *current_node = global_node_editor->current_node;
  ImGuiIO& io = ImGui::GetIO();
  
  ImGui::EndGroup();
  current_node->size    = ImRect(ImGui::GetItemRectMin(), ImGui::GetItemRectMax());
  current_node->hovered = current_node->size.Contains(io.MousePos);

  // Add node background
  global_node_editor->draw_list->AddRectFilled(current_node->size.Min, current_node->size.Max, IM_COL32(100, 0, 100, 150));

  global_node_editor->current_node = NULL;
}

void BeginNodeTitle() {


}
}
