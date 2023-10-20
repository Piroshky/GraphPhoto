#define IMGUI_DEFINE_MATH_OPERATORS

#include <limits>
#include <math.h>

#include "imgui_internal.h"
#include "gpnode.h"
#include "gegl_helper.h"

#define IMGUI_DEFINE_MATH_OPERATORS

namespace GPNode {

#define ENUM_CASE(x) case x: return #x; break;

const char *mouse_state_string(NodeEditorMouseState s) {
  switch(s) {
    ENUM_CASE(NONE);
    ENUM_CASE(IMGUI_INTERACTION);
    ENUM_CASE(DRAGGING_NODES);
    ENUM_CASE(DRAG_SELECTION);
    ENUM_CASE(CREATE_LINK);
  default:
    return "cpp is bad and you forgot to update the enum stringifizer";
  }
}

#define TOP_CHANNEL (global_node_editor->num_nodes * 2)

inline int node_foreground(node n) {
  return n.layer * 2;  
}
inline int node_background(node n) {
  return (n.layer * 2) - 1;
}

int item_id_count;

int CreateGeglNode(GeglOperationClass *klass);
void DrawGeglNode(node &ui_node);
  
NodeEditor *global_node_editor = NULL;

void InitializeNodeEditor() {
  IM_ASSERT(global_node_editor == NULL);
  global_node_editor = IM_NEW(NodeEditor)();
  item_id_count = 4;
  
  // Initialize GEGL duh
  initialize_gegl();
  
  global_node_editor->graph = gegl_node_new();
  
  global_node_editor->grid_enabled = true;
  global_node_editor->zoom = 1;
  //global_node_editor->drag_selection = false;
  global_node_editor->mouse_in_canvas = false;
  global_node_editor->num_nodes = 0;
}

void BeginNodeEditor() {

  //// Save mouse pos
  ImGuiIO& io = ImGui::GetIO();
  
  //// Draw the canvas
  ImGui::BeginChild("canvas_child_window",
		    ImVec2(0.0f, 0.0f),
		    true,
		    ImGuiWindowFlags_NoMove |
		    ImGuiWindowFlags_NoScrollbar |
		    ImGuiWindowFlags_NoScrollWithMouse);
  
  ImVec2 canvas_p0 = ImGui::GetCursorScreenPos();      // ImDrawList API uses screen coordinates!
  ImVec2 canvas_sz = ImGui::GetContentRegionAvail();   // Resize canvas to what's available
  if (canvas_sz.x < 50.0f) canvas_sz.x = 50.0f;
  if (canvas_sz.y < 50.0f) canvas_sz.y = 50.0f;
  ImVec2 canvas_p1 = ImVec2(canvas_p0.x + canvas_sz.x, canvas_p0.y + canvas_sz.y);
  ImGui::InvisibleButton("canvas_inv_button", canvas_sz, ImGuiButtonFlags_MouseButtonRight);
  ImGui::SetItemAllowOverlap();
  ImGui::SetNextWindowSize({-1, 300}, 0);
  if(ImGui::BeginPopupContextItem("canvas_inv_button", ImGuiMouseButton_Right)) {
    for (auto c : categories) {
      if (ImGui::BeginMenu(c.first.c_str())) {
	for (auto op : c.second.operations) {
	  if (ImGui::MenuItem(op.klass->name, NULL, false, true)) {
	    printf("context menu item pressed\n");

	    CreateGeglNode(op.klass);
	  }	  
	}
	ImGui::EndMenu();
      }

    }

    ImGui::EndPopup();
  }
  
  global_node_editor->canvas_p0 = canvas_p0;
  global_node_editor->canvas_p1 = canvas_p1;

  // Draw canvas border and background color
  ImDrawList* draw_list = ImGui::GetWindowDrawList();
  draw_list->AddRectFilled(canvas_p0, canvas_p1, IM_COL32(50, 50, 50, 255));
  // draw_list->AddRect(canvas_p0, canvas_p1, IM_COL32(255, 255, 255, 255));

  global_node_editor->mouse_in_canvas = ImGui::IsWindowHovered() || ImGui::IsWindowFocused(); // Hovered

  // if (io.MouseDown[ImGuiMouseButton_Middle]) {
  //   printf("middle (%f, %f)\n", io.MouseDelta.x, io.MouseDelta.y);
  //   printf("mouse in canvas %s\n", global_node_editor->mouse_in_canvas ? "true" : "false");
  //   printf("imgui call %s\n",
  // 	   ImGui::IsMouseDragging(ImGuiMouseButton_Middle, 0.0f) ? "true" : "false");
  // }
  // if (io.MouseDown[ImGuiMouseButton_Right]) {
  //   printf("right (%f, %f)\n", io.MouseDelta.x, io.MouseDelta.y);
  //   printf("mouse in canvas %s\n", global_node_editor->mouse_in_canvas ? "true" : "false");
  //   printf("imgui call %s\n",
  // 	   ImGui::IsMouseDragging(ImGuiMouseButton_Right, 0.0f) ? "true" : "false");
  // }

  
  // Pan (we use a zero mouse threshold when there's no context menu)
  // You may decide to make that threshold dynamic based on whether the mouse is hovering something etc.
  const float mouse_threshold_for_pan = global_node_editor->grid_enabled ? 0.0f : 0.0f;
  if (global_node_editor->mouse_in_canvas && ImGui::IsMouseDragging(ImGuiMouseButton_Middle, mouse_threshold_for_pan))
  {
    global_node_editor->canvas_scrolling.x += io.MouseDelta.x;
    global_node_editor->canvas_scrolling.y += io.MouseDelta.y;
  }

  ImVec2 origin(canvas_p0.x + global_node_editor->canvas_scrolling.x, canvas_p0.y + global_node_editor->canvas_scrolling.y); // Canvas origin in screen space

  const ImVec2 mouse_widget_pos(io.MousePos.x - canvas_p0.x, io.MousePos.y - canvas_p0.y);
  const ImVec2 mouse_pos_in_canvas((io.MousePos.x - origin.x) / global_node_editor->zoom, (io.MousePos.y - origin.y) / global_node_editor->zoom);
  ImVec2 mpic;
  mpic.y = mouse_pos_in_canvas.y;
  mpic.x = mouse_pos_in_canvas.x;

  global_node_editor->screen_space_MousePos = io.MousePos;
  global_node_editor->mouse_pos_in_canvas   = mpic;
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
  global_node_editor->origin = origin;



  // Create 2 channels per node, one for background, one for main content
  ImDrawListSplitter& splitter = draw_list->_Splitter;
  int num_channels = 2 * global_node_editor->node_pool.size();
  num_channels = (num_channels < 10) ? 10 : num_channels;

  splitter.Split(draw_list, 1 + num_channels);
  
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

  ImGui::SetCursorScreenPos({0,0});
  global_node_editor->vtx_ix = draw_list->VtxBuffer.size();

  // End drags, IMGUI_INTERACTION mouse state
  if (!io.MouseDown[0] && global_node_editor->mouse_state != NONE
      && global_node_editor->mouse_state != CREATE_LINK) {
    global_node_editor->mouse_state = NONE;
  }
  
  if (io.MouseDown[0] && global_node_editor->mouse_state == NONE && !global_node_editor->selected_nodes.empty()) {
    for (int node_id : global_node_editor->selected_nodes) {
      node *n = GetNode(node_id);
      if (n->mouse_in_node) {
	global_node_editor->mouse_state = DRAGGING_NODES;
	break;
      }
    }
  }
  if (global_node_editor->mouse_state == DRAGGING_NODES) {
    if (io.MouseDown[0] ) {
      ImVec2 drag_amount = io.MouseDelta / global_node_editor->zoom;
      for (int node_id : global_node_editor->selected_nodes) {
	node *n = GetNode(node_id);
	n->pos += drag_amount;
      }
    }
  }
}

void EndNodeEditor() {
  ImGuiIO& io = ImGui::GetIO();

  
  // If mouse is NOT down, and over a node, highlight the highest level node
  
  // If mouse is down, and over a node, make the highest level node the selected node

  ImDrawList* draw_list = ImGui::GetWindowDrawList();
  // ImGuiIO& io = ImGui::GetIO();

  // Determine what is being hovered
  int highest_layer = -1;
  int hovered_node_id = -1;
  int hovered_pin_id  = -1;
  float req_dist = pow(global_node_editor->Style_PinRadius * 1.5, 2.0);
  for (auto& node : global_node_editor->node_pool) {
    node.hovered = false;
    
    if (node.layer < highest_layer) {
      continue;
    }
    
    if (node.mouse_in_node) {
      hovered_node_id = node.id;
      highest_layer   = node.layer;
      hovered_pin_id  = -1;
    }
    
    float max_dist = std::numeric_limits<float>::infinity();
    for (int p : node.input_properties) {
      node_property *property = FindProperty(p);
      property->hovered = false;
      float dist = pow(property->pin_pos.x - io.MousePos.x , 2.0) +
                   pow(property->pin_pos.y - io.MousePos.y , 2.0);
      if ((dist <= req_dist) && (dist < max_dist)) {
	hovered_node_id = node.id;
	highest_layer   = node.layer;
	hovered_pin_id  = property->id;
      }
    }
  }
  
  // set node/pin to be hovered
  for (auto& node : global_node_editor->node_pool) {
    if (hovered_node_id == node.id) {
      if (hovered_pin_id == -1 && global_node_editor->mouse_state == NONE) {
	node.hovered = true;
	break;
      } else if (global_node_editor->mouse_state == NONE ||
		 global_node_editor->mouse_state == CREATE_LINK) {
	for (int p : node.input_properties) {
	  node_property *property = FindProperty(p);
	  if (hovered_pin_id == property->id) {
	    property->hovered = true;
	    if (io.MouseDown[0] && global_node_editor->mouse_state == CREATE_LINK) {
	      global_node_editor->mouse_state = NONE;
	      // CreateLink
	    }
	    break;
	  }
	}
      }      
    }
  }
  
  // Draw outlines, draw Gegl nodes
  for (auto& node : global_node_editor->node_pool) {
    if (node.draw_type == GEGL) {
      DrawGeglNode(node);
    }

    ImDrawList* draw_list = ImGui::GetWindowDrawList();

    // Add node background
    draw_list->ChannelsSetCurrent(node_background(node));
    draw_list->AddRectFilled(node.size.Min,
			     node.size.Max,
			     IM_COL32(100, 0, 100, 255));

    // Add node outline
    // C++ doesn't have named parameters in 2023 A.D. Good GOD what are you doing Stroustrup?
    ImU32 outline_color;
    if (node.hovered) {
      outline_color = IM_COL32(0, 255, 0, 255);
    } else {
      outline_color = IM_COL32(200, 200, 200, 255);      
    }
    draw_list->AddRect(node.size.Min,
		       node.size.Max,
		       outline_color,
		       0.0f, 0, global_node_editor->Style_NodeOutlineWidth);
  }


  // Draw Pins
  for (auto& node : global_node_editor->node_pool) {
    int pin_radius = global_node_editor->Style_PinRadius;    
    ImDrawList* draw_list = ImGui::GetWindowDrawList();

    draw_list->ChannelsSetCurrent(node_background(node));
    
    for (int p : node.input_properties) {
      node_property *property = FindProperty(p);
      ImU32 color;
      // pin is hovered
      if (property->hovered) {
	color = IM_COL32(0, 255, 0, 255);
      } else {
	color = IM_COL32(200, 200, 200, 255);
      }      
      
      draw_list->AddCircleFilled(property->pin_pos, pin_radius ,IM_COL32(50, 50, 50, 255), 16);
      draw_list->AddCircle(property->pin_pos, pin_radius,
			   color,
			   16, global_node_editor->Style_NodeOutlineWidth);      
    }   
  }
  
  // Add outline to hovered nodes
  for (auto& node : global_node_editor->node_pool) {
    if(node.mouse_in_node && global_node_editor->mouse_state == NONE) {

      if (!node.hovered) {
	continue;
      }

      if (io.MouseDown[0] && !NodeSelected(node.id)) {
	global_node_editor->selected_nodes.clear();
	global_node_editor->selected_nodes.push_back(node.id);

	// set node to be top node
	if (node.layer > 0 && node.layer != global_node_editor->num_nodes) {
	  set_node_to_top_layer(&node);
	}	
      }
    }
  }

  // This is how you tell if a DearImgui widget is active apparently.
  // IsAnyItemActive doesn't do what you want, it returns true whenever the mouse is clicked,
  // unless the mouse is over the true window's background.
  if (ImGui::IsMouseClicked(0) && ImGui::IsAnyItemActive()) {
    global_node_editor->mouse_state = IMGUI_INTERACTION;
  }

  // clicking canvas starts drag selection, clears selected_nodes
  bool mouse_in_any_node = (hovered_node_id != -1);
  if (global_node_editor->mouse_in_canvas && io.MouseDown[0]
      && !mouse_in_any_node && global_node_editor->mouse_state == NONE) {
    global_node_editor->mouse_state = DRAG_SELECTION;
    global_node_editor->drag_start = io.MousePos;

    global_node_editor->selected_nodes.clear();
  }

  // clicking a pin creates a new link
  if (global_node_editor->mouse_in_canvas && io.MouseDown[0]
      && hovered_pin_id != -1 && global_node_editor->mouse_state == NONE) {

    global_node_editor->active_node = hovered_node_id;
    global_node_editor->active_pin  = hovered_pin_id;            
    global_node_editor->mouse_state = CREATE_LINK;
  }

  // draw active link
  if (global_node_editor->mouse_state == CREATE_LINK) {
    draw_list->ChannelsSetCurrent(TOP_CHANNEL);

    node *n = FindNode(global_node_editor->active_node);
    if (n == NULL) {
      printf("null node id %d\n", hovered_node_id);
    } else {
    for (int p : n->input_properties) {
      node_property *property = FindProperty(p);
      if (global_node_editor->active_pin == property->id) {
	draw_list->AddLine(property->pin_pos, global_node_editor->mouse_pos_in_canvas,
			   IM_COL32(255, 0, 0, 255), 10);
	break;
      }
    }
    }
    

  }
    
  // draw drag selection @Cleanup
  if (global_node_editor->mouse_state == DRAG_SELECTION) {
    draw_list->ChannelsSetCurrent(TOP_CHANNEL);
    draw_list->AddRectFilled(global_node_editor->drag_start, io.MousePos, IM_COL32(0, 0, 255, 50));
    draw_list->AddRect(global_node_editor->drag_start, io.MousePos, IM_COL32(0, 0, 255, 255));

    
    // create selection box, ImRect Min must be upper left, Max lower right
    ImVec2 UL, LR;
    if (global_node_editor->drag_start.x < io.MousePos.x) {
      UL.x = global_node_editor->drag_start.x;
      LR.x = io.MousePos.x;
    } else {
      UL.x = io.MousePos.x;
      LR.x = global_node_editor->drag_start.x;
    }
    if (global_node_editor->drag_start.y < io.MousePos.y) {
      UL.y = global_node_editor->drag_start.y;
      LR.y = io.MousePos.y;
    } else {
      UL.y = io.MousePos.y;
      LR.y = global_node_editor->drag_start.y;
    }    

    ImRect selection_box = ImRect(UL, LR);

    // add nodes in selection box to selected_nodes
    global_node_editor->selected_nodes.clear();
    for (auto node : global_node_editor->node_pool) {
      if (node.size.Overlaps(selection_box)) {
	global_node_editor->selected_nodes.push_back(node.id);
      }
    }
    
  }

  // draw highlight on selected nodes
  for (int id : global_node_editor->selected_nodes) {
    node *n = GetNode(id); // @Cleanup very stupid n^2 stuff here, just temporary for now
    draw_list->ChannelsSetCurrent(node_foreground(*n));
    draw_list->AddRect(n->size.Min,
		       n->size.Max,
		       IM_COL32(255, 0, 0, 255));
  }

  draw_list->ChannelsMerge();
           
  // Transform canvas points to screen points
  ImVec2 origin = global_node_editor->origin;
  ImVec2 canvas_p0 = global_node_editor->canvas_p0;
  ImVec2 canvas_p1 = global_node_editor->canvas_p1;

  int vertices_count = draw_list->VtxBuffer.size() - global_node_editor->vtx_ix;
  
  // printf("vtx_ix %d\n", global_node_editor->vtx_ix);
  // printf("vtx_size endeditor %d\n\n", draw_list->VtxBuffer.size());
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
  io.MousePos = global_node_editor->screen_space_MousePos;
  
  ImGui::EndChild();
  
}

link *CreateLink(int start_id, int end_id) {
  global_node_editor->link_pool.emplace_back(start_id, end_id);
  global_node_editor->num_links += 1;

  return &global_node_editor->link_pool.back();
}

node *CreateNode(int node_id) {
  global_node_editor->node_pool.emplace_back(node_id);
  global_node_editor->node_pool.back().pos = ImGui::GetCursorScreenPos();
  global_node_editor->num_nodes += 1;
  
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

node_property *FindProperty(int property_id) {
  for (auto& property : global_node_editor->pin_pool) {
    if (property.id == property_id) {
      return &property;
    }
  }
  return NULL;
}

node *FindNode(int node_id) {
  for (auto& node : global_node_editor->node_pool) {
    if (node.id == node_id) {
      return &node;
    }
  }
  return NULL;
}


bool NodeSelected(int node_id) {
  for (auto sn : global_node_editor->selected_nodes) {
    if (sn == node_id) {
      return true;
    }
  }
  return false;
}

void set_node_to_top_layer(node *node) {
  for (auto& n : global_node_editor->node_pool) {
    if (n.layer > node->layer) {
      n.layer -= 1;
    }
  }
  node->layer = global_node_editor->num_nodes;
  printf("num %d\n", global_node_editor->num_nodes);
}

void BeginNode(int node_id) {
  node *current_node = GetNode(node_id); //Todo implement
  global_node_editor->current_node = current_node;

  ImDrawList* draw_list = ImGui::GetWindowDrawList();
  //printf("current_node->layer %d\n", current_node->layer);
  if (current_node->layer == 0) {
    current_node->layer = global_node_editor->node_pool.size();
  }
  draw_list->ChannelsSetCurrent(node_foreground(*current_node));
  
  ImGui::SetCursorScreenPos(current_node->pos);
  // printf("current_node pos: (%f, %f)\n", current_node->pos.x, current_node->pos.y);
  // ImVec2 p = ImGui::GetCursorScreenPos();
  // printf("cursorPos: (%f, %f)\n", p.x, p.y);
  ImGui::PushID(current_node->id);

  ImGui::BeginGroup();
  ImGui::PushItemWidth(100);
}

void EndNode() {
  node *current_node = global_node_editor->current_node;
  ImGuiIO& io = ImGui::GetIO();
  ImGui::PopItemWidth();
  ImGui::EndGroup();
  current_node->size          = ImRect(ImGui::GetItemRectMin()- global_node_editor->Style_NodeMargin,
				       ImGui::GetItemRectMax()+ global_node_editor->Style_NodeMargin);
  current_node->mouse_in_node = current_node->size.Contains(io.MousePos);

  global_node_editor->current_node = NULL;
  ImGui::PopID();
}

void BeginNodeProperty(node_property *property) {
  ImGui::BeginGroup();
  ImGui::PushID(property->id);  
}

void EndNodeProperty(node_property *property) {
  ImGui::PopID();
  ImGui::EndGroup();

  ImVec2 min = ImGui::GetItemRectMin();
  ImVec2 max = ImGui::GetItemRectMax();
  
  property->rect = ImRect(ImGui::GetItemRectMin(), ImGui::GetItemRectMax());
    
  ImVec2 pin_pos = {min.x - (global_node_editor->Style_NodeMargin) + (global_node_editor->Style_NodeOutlineWidth) / 2.0f,
		    min.y + ((max.y - min.y) / 2)};

  property->pin_pos = pin_pos;
}

void DrawGeglNode(node &ui_node) {
  GPNode::BeginNode(ui_node.id);
  ImGui::Text("layer: %d", ui_node.layer);
  ImGui::Text(ui_node.gegl_operation_klass->name);
  ImGui::Separator();
  
  ImGui::Text("Input Pads");
  for (auto p : ui_node.gegl_input_pads) {
    ImGui::Text(p);
  }
  
  ImGui::Text("Input Properties");
  for (int id : ui_node.input_properties) {
    node_property *property = FindProperty(id);
    BeginNodeProperty(property);
    
    if      (g_type_is_a(property->gtype, GEGL_TYPE_PARAM_INT)) {
      ImGui::Text("(INT)  -  %s", property->label);
    }
    else if (g_type_is_a(property->gtype, G_TYPE_DOUBLE)) {
      ImGui::Text("(DOUBLE)  -  %s %s", g_type_name(property->gtype), property->label);
    }
    else if (g_type_is_a(property->gtype, G_TYPE_PARAM_ENUM)) {
      ImGui::Text("(ENUM)  -  %s %s", g_type_name(property->gtype), property->label);
    }
    else {
      ImGui::Text("%s -- %s", g_type_name(property->gtype), property->label);      
    }

    EndNodeProperty(property);
  }

  ImGui::Text("Output Pads");
  for (auto p : ui_node.gegl_output_pads) {
    ImGui::Text(p);
  }
  
  GPNode::EndNode();
}

int CreateGeglNode(GeglOperationClass *klass) {
  GeglNode *gegl_node = gegl_node_new_child(global_node_editor->graph, "operation", klass->name, NULL);
  item_id_count += 1;
  int node_id = item_id_count;
  node *ui_node = CreateNode(node_id);
  ui_node->draw_type = GEGL;
  ui_node->gegl_operation_klass = klass;
  
  // ImVec2 p = ImGui::GetCursorScreenPos();
  printf("Operation name: %s\n", klass->name);
  
  ui_node->pos = global_node_editor->mouse_pos_in_canvas;
      
  // Add input pads
  printf("Input Pads:\n");
  gchar ** input_pads = gegl_node_list_input_pads(gegl_node);
  for (char **c = input_pads; c != NULL && *c != 0; ++c) {
    g_print("\t\t%s\n", *c);
    ui_node->gegl_input_pads.emplace_back(strdup(*c));
  }
  g_strfreev(input_pads);

  // Add output pads
  printf("Output Pads:\n");
  gchar ** output_pads = gegl_node_list_output_pads(gegl_node);
  for (char **c = output_pads; c != NULL && *c != 0; ++c) {
    g_print("\t\t%s\n", *c);
    ui_node->gegl_output_pads.emplace_back(strdup(*c));
  }
  g_strfreev(output_pads);
  
  // Add input properties
  printf("Properties:\n");
  unsigned int n_properties;
  GParamSpec **properties = g_object_class_list_properties((GObjectClass*) klass, &n_properties);
  for (unsigned int j = 0; j < n_properties; ++j) {
    node_property property;
    property.label = strdup(g_param_spec_get_nick(properties[j]));
    property.gtype = G_PARAM_SPEC_TYPE(properties[j]);
    item_id_count += 1;
    property.id = item_id_count;
    property.hovered = false;

    g_print("\t\t %d  %s\n",property.id, g_param_spec_get_name(properties[j]));

    GType parameter_type G_PARAM_SPEC_TYPE(properties[j]);
    if (g_type_is_a(parameter_type, G_TYPE_PARAM_ENUM)) {
      GParamSpecEnum *pspec = G_PARAM_SPEC_ENUM(properties[j]);
      GEnumClass *eclass = pspec->enum_class;

      GEnumValue *value = eclass->values;
      for (uint i = 0; i < eclass->n_values; ++i) {
	printf("\t\t (%d) %s %s\n", value->value, value->value_name, value->value_nick);
	++value;
      }
    }

    global_node_editor->pin_pool.emplace_back(property);
    ui_node->input_properties.emplace_back(property.id);
  }
  g_free(properties); // todo is this right?
  
  // Add output pads (? not sure if they exist)

  // add output properties (? not sure if they exist)

  // select new node
  global_node_editor->selected_nodes.clear();
  global_node_editor->selected_nodes.push_back(ui_node->id);
  
  return 0;
}

}
