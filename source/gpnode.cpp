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

  //// Save mouse pos
  ImGuiIO& io = ImGui::GetIO();
  global_node_editor->screen_space_MousePos = io.MousePos;
  
  //// Draw the canvas
  ImVec2 canvas_p0 = ImGui::GetCursorScreenPos();      // ImDrawList API uses screen coordinates!
  ImVec2 canvas_sz = ImGui::GetContentRegionAvail();   // Resize canvas to what's available
  if (canvas_sz.x < 50.0f) canvas_sz.x = 50.0f;
  if (canvas_sz.y < 50.0f) canvas_sz.y = 50.0f;
  ImVec2 canvas_p1 = ImVec2(canvas_p0.x + canvas_sz.x, canvas_p0.y + canvas_sz.y);

  global_node_editor->canvas_p0 = canvas_p0;
  global_node_editor->canvas_p1 = canvas_p1;

  // Draw border and background color
  ImDrawList* draw_list = ImGui::GetWindowDrawList();
  draw_list->AddRectFilled(canvas_p0, canvas_p1, IM_COL32(50, 50, 50, 255));
  draw_list->AddRect(canvas_p0, canvas_p1, IM_COL32(255, 255, 255, 255));

  // This will catch our interactions
  ImGui::InvisibleButton("canvas", canvas_sz, ImGuiButtonFlags_MouseButtonLeft | ImGuiButtonFlags_MouseButtonRight);
  //const bool is_hovered = ImGui::IsItemHovered(); // Hovered
  const bool is_active = ImGui::IsItemActive();   // Held

  // Pan (we use a zero mouse threshold when there's no context menu)
  // You may decide to make that threshold dynamic based on whether the mouse is hovering something etc.
  const float mouse_threshold_for_pan = global_node_editor->grid_enabled ? 0.0f : 0.0f;
  if (is_active && ImGui::IsMouseDragging(ImGuiMouseButton_Right, mouse_threshold_for_pan))
  {
    global_node_editor->canvas_scrolling.x += io.MouseDelta.x;
    global_node_editor->canvas_scrolling.y += io.MouseDelta.y;
  }

  ImVec2 origin(canvas_p0.x + global_node_editor->canvas_scrolling.x, canvas_p0.y + global_node_editor->canvas_scrolling.y); // Canvas origin in screen space
  global_node_editor->origin = origin;
  const ImVec2 mouse_widget_pos(io.MousePos.x - canvas_p0.x, io.MousePos.y - canvas_p0.y);
  const ImVec2 mouse_pos_in_canvas((io.MousePos.x - origin.x) / global_node_editor->zoom, (io.MousePos.y - origin.y) / global_node_editor->zoom);
  ImVec2 mpic;
  mpic.y = mouse_pos_in_canvas.y;
  mpic.x = mouse_pos_in_canvas.x;
	    
  io.MousePos = mpic;
  io.MouseDrawCursor = true;

  // Handle canvas global_node_editor->zoom
  if (io.MouseWheel != 0) {
    const double zoom_delta = io.MouseWheel * 0.1;
    const double new_zoom   = global_node_editor->zoom + zoom_delta;
            
    if (new_zoom >= 0.10 && new_zoom < 2.6) {
      // floating point error means you can't do <= 2.5
      // Move origin so that global_node_editor->zoom happens around mouse location
      global_node_editor->zoom = new_zoom;
      global_node_editor->canvas_scrolling.x = mouse_widget_pos.x - (mouse_pos_in_canvas.x * global_node_editor->zoom);
      global_node_editor->canvas_scrolling.y = mouse_widget_pos.y - (mouse_pos_in_canvas.y * global_node_editor->zoom);
      origin.x = canvas_p0.x + global_node_editor->canvas_scrolling.x;
      origin.y = canvas_p0.y + global_node_editor->canvas_scrolling.y;
    }            
  }

  // Context menu (under default mouse threshold)
  ImVec2 drag_delta = ImGui::GetMouseDragDelta(ImGuiMouseButton_Right);
  if (drag_delta.x == 0.0f && drag_delta.y == 0.0f)
    ImGui::OpenPopupOnItemClick("context", ImGuiPopupFlags_MouseButtonRight);
  if (ImGui::BeginPopup("context"))
  {
    if (ImGui::MenuItem("context menu item", NULL, false, true)) { printf("context menu item pressed\n"); }
    ImGui::EndPopup();
  }

  // Draw grid
            
  ImVec2 canvas_clip_p0((canvas_p0.x - origin.x) / global_node_editor->zoom, (canvas_p0.y - origin.y) / global_node_editor->zoom);
  ImVec2 canvas_clip_p1((canvas_p1.x - origin.x) / global_node_editor->zoom, (canvas_p1.y - origin.y) / global_node_editor->zoom);
          
  ImGui::PushClipRect(canvas_clip_p0, canvas_clip_p1, false);
  global_node_editor->canvas_clip_rect_ix = draw_list->CmdBuffer.size() - 1;
          
  if (global_node_editor->grid_enabled)
  {
    const float GRID_STEP = 64.0f * global_node_editor->zoom;
    for (float x = fmodf(global_node_editor->canvas_scrolling.x, GRID_STEP); x < canvas_sz.x; x += GRID_STEP)
      draw_list->AddLine(ImVec2(canvas_p0.x + x, canvas_p0.y), ImVec2(canvas_p0.x + x, canvas_p1.y), IM_COL32(200, 200, 200, 40));
    for (float y = fmodf(global_node_editor->canvas_scrolling.y, GRID_STEP); y < canvas_sz.y; y += GRID_STEP)
      draw_list->AddLine(ImVec2(canvas_p0.x, canvas_p0.y + y), ImVec2(canvas_p1.x, canvas_p0.y + y), IM_COL32(200, 200, 200, 40));
  }

  //// Demo line drawing, keeping for now as reference
  // for (int n = 0; n < points.Size; n += 2)
  //   draw_list->AddLine(ImVec2(origin.x + points[n].x * global_node_editor->zoom , origin.y + points[n].y * global_node_editor->zoom), ImVec2(origin.x + points[n + 1].x * global_node_editor->zoom, origin.y + points[n + 1].y * global_node_editor->zoom), IM_COL32(255, 255, 0, 255), 2.0f);


  ImGui::SetCursorScreenPos({0,0});
  global_node_editor->vtx_ix = draw_list->VtxBuffer.size();
  
}

void EndNodeEditor() {
  
  // If mouse is NOT down, and over a node, highlight the highest level node
  
  // If mouse is down, and over a node, make the highest level node the selected node

  //
           
  // Transform canvas points to screen points
  ImVec2 origin = global_node_editor->origin;
  ImVec2 canvas_p0 = global_node_editor->canvas_p0;
  ImVec2 canvas_p1 = global_node_editor->canvas_p1;
  ImDrawList* draw_list = ImGui::GetWindowDrawList();
  int vertices_count = draw_list->VtxBuffer.size() - global_node_editor->vtx_ix;
  
  //printf("vertices_count %d\n", vertices_count);
  if (vertices_count > 0) {
    ImDrawVert *vert = &draw_list->VtxBuffer[draw_list->VtxBuffer.size() - (vertices_count)];
    for(int i = 0; i < vertices_count; ++i) {
      vert->pos.x = vert->pos.x * global_node_editor->zoom + origin.x;
      vert->pos.y = vert->pos.y * global_node_editor->zoom + origin.y;
      vert++;
    }
  }
  // printf("vert_count %d\n", vertices_count);

  // vtx_ix = draw_list->VtxBuffer.size();
  // printf("after vtx_ix %d\n", vtx_ix);
              

  ImVec4 &clip_rect = draw_list->CmdBuffer[global_node_editor->canvas_clip_rect_ix].ClipRect;

  clip_rect.x = canvas_p0.x;
  clip_rect.y = canvas_p0.y;
  clip_rect.z = canvas_p1.x;
  clip_rect.w = canvas_p1.y;
	    
  ImGui::PopClipRect();


  
  //// Restore mouse position
  ImGuiIO& io = ImGui::GetIO();
  io.MousePos = global_node_editor->screen_space_MousePos;
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
  ImDrawList* draw_list = ImGui::GetWindowDrawList();
  
  ImGui::EndGroup();
  current_node->size    = ImRect(ImGui::GetItemRectMin(), ImGui::GetItemRectMax());
  current_node->hovered = current_node->size.Contains(io.MousePos);

  // Add node background
  draw_list->AddRectFilled(current_node->size.Min, current_node->size.Max, IM_COL32(100, 0, 100, 150));

  global_node_editor->current_node = NULL;
}

void BeginNodeTitle() {


}
}
