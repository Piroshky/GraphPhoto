#include <limits>
#include <math.h>

#include <GL/gl3w.h>
#include <GLFW/glfw3.h>

#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui_internal.h"
// not included in the builtin imgui math operators for some reason
static inline ImVec2 operator-(const ImVec2& lhs, const float rhs)              { return ImVec2(lhs.x - rhs, lhs.y - rhs); }
static inline ImVec2 operator+(const ImVec2& lhs, const float rhs)              { return ImVec2(lhs.x + rhs, lhs.y + rhs); }

#include "gpnode.h"
#include "gegl_helper.h"

#define STB_IMAGE_IMPLEMENTATION
extern "C" {
#include "stb_image.h"
}

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

#define TOP_CHANNEL ((global_node_editor->num_nodes * 2)+1)

inline int node_foreground(Node n) {
  return n.layer * 2;  
}
inline int node_background(Node n) {
  return (n.layer * 2) - 1;
}

int item_id_count;

//int CreateGeglNode(GeglOperationClass *klass);
int CreateGeglNode(const char *operation);
void CreateLink(NodeProperty *a, NodeProperty *b);
void DrawGeglNode(Node &ui_node);
int CreateCanvasNode();
ImTextureID CreateTexture(const void* data, int width, int height);
  
NodeEditor *global_node_editor = NULL;

void InitializeNodeEditor() {
  IM_ASSERT(global_node_editor == NULL);
  global_node_editor = IM_NEW(NodeEditor)();
  item_id_count = 4;
  
  // Initialize GEGL duh
  initialize_gegl();

  gl3wInit();
  
  global_node_editor->graph = gegl_node_new();
  
  global_node_editor->grid_enabled = true;
  global_node_editor->zoom = 1;
  //global_node_editor->drag_selection = false;
  global_node_editor->mouse_in_canvas = false;
  global_node_editor->num_nodes = 0;

  int canvas_id = CreateCanvasNode();
  // int load_id   = CreateGeglNode("gegl:load");
  // int edge_id   = CreateGeglNode("gegl:edge");
  
  Node *canvas = FindNode(canvas_id);
  

  GeglNode *load    = gegl_node_new_child (global_node_editor->graph,
					   "operation", "gegl:load",
					   NULL);  
  gegl_node_set(load, "path", "./test.jpg", NULL);
  gegl_node_set(canvas->gegl_node, "buffer", &(canvas->gegl_buffer), NULL);

  // GeglNode *edge    = gegl_node_new_child (global_node_editor->graph,
  // 					   "operation", "gegl:edge",
  // 					   NULL);  

  gegl_node_connect_to(load, "output", canvas->gegl_node, "input");
  // gegl_node_connect_to(edge, "output", canvas->gegl_node, "input");
  
  // GeglNode *prod = (gegl_node_get_producer(canvas->gegl_node, "input", NULL));
  // printf("prod %s\n", GEGL_OPERATION_GET_CLASS(gegl_node_get_gegl_operation(prod))->name);

  // prod = (gegl_node_get_producer(prod, "input", NULL));
  // printf("prod %s\n", GEGL_OPERATION_GET_CLASS(gegl_node_get_gegl_operation(prod))->name);
  
  if (gegl_node_get_producer(canvas->gegl_node, "input", NULL)) {  
    gegl_node_process(canvas->gegl_node);
    int h = gegl_buffer_get_height(canvas->gegl_buffer);
    int w = gegl_buffer_get_width(canvas->gegl_buffer);
    canvas->texture_size = ImVec2(w, h);
    int pixels = gegl_buffer_get_pixel_count(canvas->gegl_buffer);
    void *image_data = malloc(pixels * 4 * sizeof(char));
    gegl_buffer_get(canvas->gegl_buffer,
		    NULL,
		    1.0,
		    babl_format ("R'G'B'A u8"),
		    image_data, GEGL_AUTO_ROWSTRIDE,
		    GEGL_ABYSS_NONE);

    canvas->texture = CreateTexture(image_data, w, h);
    canvas->texture_size = ImVec2(w, h);
  }
  

  
}

void BeginNodeEditor() {
  ImGuiIO& io = ImGui::GetIO();
  static bool run_once = true;
  
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
	    CreateGeglNode((char*)op.klass->name);
	  }	  
	}
	ImGui::EndMenu();
      }
    }
    ImGui::EndPopup();
  }

  if (run_once) {
    // CreateCanvasNode();
    run_once = false;
  }
  
  global_node_editor->canvas_p0 = canvas_p0;
  global_node_editor->canvas_p1 = canvas_p1;

  // Draw canvas border and background color
  ImDrawList* draw_list = ImGui::GetWindowDrawList();
  draw_list->AddRectFilled(canvas_p0, canvas_p1, IM_COL32(50, 50, 50, 255));
  // draw_list->AddRect(canvas_p0, canvas_p1, IM_COL32(255, 255, 255, 255));

  global_node_editor->mouse_in_canvas = ImGui::IsWindowHovered() || ImGui::IsWindowFocused(); // Hovered
 
  // Pan (we use a zero mouse threshold when there's no context menu)
  // You may decide to make that threshold dynamic based on whether the mouse is hovering something etc.
  const float mouse_threshold_for_pan = global_node_editor->grid_enabled ? 0.0f : 0.0f;
  if (global_node_editor->mouse_in_canvas &&
      global_node_editor->mouse_state == NONE &&
      ImGui::IsMouseDragging(ImGuiMouseButton_Middle, mouse_threshold_for_pan))
  {
    global_node_editor->canvas_scrolling.x += io.MouseDelta.x;
    global_node_editor->canvas_scrolling.y += io.MouseDelta.y;
  }

  ImVec2 origin(canvas_p0.x + global_node_editor->canvas_scrolling.x,
		canvas_p0.y + global_node_editor->canvas_scrolling.y); // Canvas origin in screen space

  const ImVec2 mouse_widget_pos(io.MousePos.x - canvas_p0.x, io.MousePos.y - canvas_p0.y);
  const ImVec2 mouse_pos_in_canvas((io.MousePos.x - origin.x) / global_node_editor->zoom,
				   (io.MousePos.y - origin.y) / global_node_editor->zoom);
  
  global_node_editor->screen_space_MousePos = io.MousePos;
  global_node_editor->mouse_pos_in_canvas   = mouse_pos_in_canvas;
  io.MousePos = mouse_pos_in_canvas;
  io.MouseDrawCursor = true;

  // Handle canvas global_node_editor->zoom
  if (global_node_editor->mouse_in_canvas && io.MouseWheel != 0) {
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


  // Create 2 channels per node, one for background, one for main content.
  // layer numbering starts at 1, channel zero used for canvas background
  //                     
  //                    (one node)
  //           canvas    layer 1   layer 2   ...   layer n    top layer
  // channels    0         1  2     3  4          2n-1  2n    top channel
  //                       ┃  ┃   
  //            background━┛  ┗━foreground
  
  ImDrawListSplitter& splitter = draw_list->_Splitter;
  int num_channels = 2 * global_node_editor->node_pool.size();
  num_channels = (num_channels < 10) ? 10 : num_channels;

  splitter.Split(draw_list, 2 + num_channels);
  
  // Draw grid            
  ImVec2 canvas_clip_p0((canvas_p0.x - origin.x) / global_node_editor->zoom, (canvas_p0.y - origin.y) / global_node_editor->zoom);
  ImVec2 canvas_clip_p1((canvas_p1.x - origin.x) / global_node_editor->zoom, (canvas_p1.y - origin.y) / global_node_editor->zoom);
          
  ImGui::PushClipRect(canvas_clip_p0, canvas_clip_p1, false);
  global_node_editor->canvas_clip_rect_ix = draw_list->CmdBuffer.size() - 1;
          
  if (global_node_editor->grid_enabled) {
    const float GRID_STEP = 64.0f * global_node_editor->zoom;
    for (float x = fmodf(global_node_editor->canvas_scrolling.x, GRID_STEP); x < canvas_sz.x; x += GRID_STEP)
      draw_list->AddLine(ImVec2(canvas_p0.x + x, canvas_p0.y), ImVec2(canvas_p0.x + x, canvas_p1.y), IM_COL32(200, 200, 200, 40));

    for (float y = fmodf(global_node_editor->canvas_scrolling.y, GRID_STEP); y < canvas_sz.y; y += GRID_STEP)
      draw_list->AddLine(ImVec2(canvas_p0.x, canvas_p0.y + y), ImVec2(canvas_p1.x, canvas_p0.y + y), IM_COL32(200, 200, 200, 40));
  }

  ImGui::SetCursorScreenPos({0,0});
  global_node_editor->vtx_ix = draw_list->VtxBuffer.size();

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
      NodeProperty *property = FindProperty(p);
      property->hovered = false;
      float dist = pow(property->pin_pos.x - io.MousePos.x , 2.0) +
	pow(property->pin_pos.y - io.MousePos.y , 2.0);
      if ((dist <= req_dist) && (dist < max_dist)) {
	hovered_node_id = node.id;
	highest_layer   = node.layer;
	hovered_pin_id  = property->id;
      }
    }
    for (int p : node.gegl_input_pads) {
      NodeProperty *property = FindProperty(p);
      property->hovered = false;
      float dist = pow(property->pin_pos.x - io.MousePos.x , 2.0) +
	pow(property->pin_pos.y - io.MousePos.y , 2.0);
      if ((dist <= req_dist) && (dist < max_dist)) {
	hovered_node_id = node.id;
	highest_layer   = node.layer;
	hovered_pin_id  = property->id;
      }
    }
    for (int p : node.gegl_output_pads) {
      NodeProperty *property = FindProperty(p);
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
  
  if (global_node_editor->mouse_in_canvas) {
    if (io.MouseDown[0]) {
      switch(global_node_editor->mouse_state) {
      case NONE: {
	if (hovered_pin_id != -1) {
	  // clicking a pin
	  global_node_editor->mouse_state = CREATE_LINK;
	  global_node_editor->active_node = -1;
	  global_node_editor->active_pin  = hovered_pin_id;
	  
	} else if (hovered_node_id != -1) {
	  // clicking a node selects it
	  if (!NodeSelected(hovered_node_id)) {
	    global_node_editor->selected_nodes.clear();
	    global_node_editor->selected_nodes.push_back(hovered_node_id);
	  }

	  // moves it to the top
	  Node *node = GetNode(hovered_node_id);
	  if (node->layer > 0 && node->layer != global_node_editor->num_nodes) {
	    set_node_to_top_layer(node);
	  }
	  
	  // sets the state to dragging node	  
	  global_node_editor->mouse_state = DRAGGING_NODES;
	  global_node_editor->active_node = hovered_node_id;
	  global_node_editor->active_pin  = -1;
	  
	} else {
	  // clicking on the canvas starts drag selection
	  global_node_editor->mouse_state = DRAG_SELECTION;
	  global_node_editor->drag_start = io.MousePos;

	  global_node_editor->selected_nodes.clear();;
	}
	break;
      }
      case DRAGGING_NODES: {
	ImVec2 drag_amount = io.MouseDelta / global_node_editor->zoom;
	for (int node_id : global_node_editor->selected_nodes) {
	  Node *n = GetNode(node_id);
	  n->pos += drag_amount;
	}	
	break;
      }
      case CREATE_LINK: {
	NodeProperty *p = FindProperty(global_node_editor->active_pin);
	p->hovered = true;
	if (hovered_pin_id != -1) {
	  p = FindProperty(hovered_pin_id);
	  NodeProperty *a = FindProperty(global_node_editor->active_pin);
	  if (a->id != p->id &&
	      a->node_id != p->node_id &&
	      a->direction != p->direction) {
	    p->hovered = true;	    
	  }
	}
	break;
      }
      default:
	// IMGUI_INTERACTION might need to switch to none
	// DRAG_SELECTION -> do nothing
	break;
      }
    } else { // mouse up
      switch(global_node_editor->mouse_state) {
      case NONE: {
	if (hovered_pin_id != -1) {
	  NodeProperty *p = FindProperty(hovered_pin_id);
	  p->hovered = true;
	} else if (hovered_node_id != -1) {
	  Node *node = FindNode(hovered_node_id);
	  node->hovered = true;
	}
	break;
      }
	
      case DRAG_SELECTION: {
	global_node_editor->mouse_state = NONE;
	break;
      }
      case DRAGGING_NODES: {
	global_node_editor->mouse_state = NONE;
	break;
      }
      case CREATE_LINK: {
	if (hovered_pin_id != -1) {
	  NodeProperty *p = FindProperty(hovered_pin_id);
	  p->hovered = true;
	  NodeProperty *a = FindProperty(global_node_editor->active_pin);
	  if (a->id != p->id &&
	      a->node_id != p->node_id &&
	      a->direction != p->direction) {
	    CreateLink(a, p);	    
	  }
	}
	global_node_editor->mouse_state = NONE;
	global_node_editor->active_node = -1;
	global_node_editor->active_pin = -1;
	
	break;
      }
      case IMGUI_INTERACTION:
	// todo
	break;
      }
    }
  } else {
    global_node_editor->mouse_state = NONE;
  }
}

void EndNodeEditor() {
  ImGuiIO& io = ImGui::GetIO();   
  ImDrawList* draw_list = ImGui::GetWindowDrawList();
  
  // Draw outlines, draw Gegl nodes
  for (auto& node : global_node_editor->node_pool) {
    if (node.draw_type == GEGL || node.draw_type == CANVAS) {
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

  // This is how you tell if a DearImgui widget is active apparently.
  // IsAnyItemActive doesn't do what you want, it returns true whenever the mouse is clicked,
  // unless the mouse is over the true window's background.
  if (ImGui::IsMouseClicked(0) && ImGui::IsAnyItemActive()) {
    global_node_editor->mouse_state = IMGUI_INTERACTION;
  }

  // draw highlight on selected nodes
  for (int id : global_node_editor->selected_nodes) {
    Node *n = GetNode(id); // @Cleanup very stupid n^2 stuff here, just temporary for now
    draw_list->ChannelsSetCurrent(node_foreground(*n));
    draw_list->AddRect(n->size.Min,
		       n->size.Max,
		       IM_COL32(255, 0, 0, 255));
  }
  
  // Draw Pins
  for (auto& node : global_node_editor->node_pool) {
    int pin_radius = global_node_editor->Style_PinRadius;    
    ImDrawList* draw_list = ImGui::GetWindowDrawList();

    draw_list->ChannelsSetCurrent(node_foreground(node));
    
    for (int p : node.input_properties) {
      NodeProperty *property = FindProperty(p);
      ImU32 outline_color;
      if (property->hovered) {
	outline_color = IM_COL32(0, 255, 0, 255);
      } else {
	outline_color = IM_COL32(200, 200, 200, 255);
      }

      ImU32 interior_color;
      if (property->links > 0) {
	interior_color = IM_COL32(0, 0, 255, 255);
      } else {
	interior_color = IM_COL32(50, 50, 50, 255);
      }
      
      draw_list->AddCircleFilled(property->pin_pos,
				 pin_radius,
				 interior_color,
				 16);
      draw_list->AddCircle(property->pin_pos,
			   pin_radius,
			   outline_color,
			   16,
			   global_node_editor->Style_NodeOutlineWidth);      
    }

    for (int p : node.gegl_input_pads) {
      NodeProperty *property = FindProperty(p);
      ImU32 color;
      if (property->hovered) {
	color = IM_COL32(0, 255, 0, 255);
      } else {
	color = IM_COL32(200, 200, 200, 255);
      }

      ImU32 interior_color;
      if (property->links > 0) {
	interior_color = IM_COL32(0, 0, 255, 255);
      } else {
	interior_color = IM_COL32(50, 50, 50, 255);
      }

      draw_list->AddRectFilled(property->pin_pos - pin_radius,
			       property->pin_pos + pin_radius,
			       interior_color, 0, 0);

      draw_list->AddRect(property->pin_pos - pin_radius,
			 property->pin_pos + pin_radius,
			 color,
			 0,
			 0,
			 2);      
    }
    for (int p : node.gegl_output_pads) {
      NodeProperty *property = FindProperty(p);
      ImU32 color;
      if (property->hovered) {
	color = IM_COL32(0, 255, 0, 255);
      } else {
	color = IM_COL32(200, 200, 200, 255);
      }
      ImU32 interior_color;
      if (property->links > 0) {
	interior_color = IM_COL32(0, 0, 255, 255);
      } else {
	interior_color = IM_COL32(50, 50, 50, 255);
      }

      draw_list->AddRectFilled(property->pin_pos - pin_radius,
			       property->pin_pos + pin_radius,
			       interior_color, 0, 0);

      draw_list->AddRect(property->pin_pos - pin_radius,
			 property->pin_pos + pin_radius,
			 color,
			 0,
			 0,
			 2);      
    }
  }
  

  // draw active link
  if (global_node_editor->mouse_state == CREATE_LINK) {
    draw_list->ChannelsSetCurrent(TOP_CHANNEL);

    NodeProperty *p = FindProperty(global_node_editor->active_pin);
    draw_list->AddLine(p->pin_pos, global_node_editor->mouse_pos_in_canvas,
		       IM_COL32(255, 0, 0, 255), 10);    
  }

  // draw links
  draw_list->ChannelsSetCurrent(0);
  for (Link l : global_node_editor->link_pool) {
    NodeProperty *start = FindProperty(l.start_id);
    NodeProperty *end = FindProperty(l.end_id);
    draw_list->AddLine(start->pin_pos, end->pin_pos, IM_COL32(0, 0, 255, 255), 10);
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

  draw_list->ChannelsMerge();
           
  // Transform canvas points to screen points
  ImVec2 origin = global_node_editor->origin;
  ImVec2 canvas_p0 = global_node_editor->canvas_p0;
  ImVec2 canvas_p1 = global_node_editor->canvas_p1;

  int vertices_count = draw_list->VtxBuffer.size() - global_node_editor->vtx_ix;
  
  if (vertices_count > 0) {
    ImDrawVert *vert = &draw_list->VtxBuffer[draw_list->VtxBuffer.size() - (vertices_count)];
    for(int i = 0; i < vertices_count; ++i) {
      vert->pos.x = vert->pos.x * global_node_editor->zoom + origin.x;
      vert->pos.y = vert->pos.y * global_node_editor->zoom + origin.y;
      vert++;
    }
  }
  
  ImVec4 &clip_rect = draw_list->CmdBuffer[global_node_editor->canvas_clip_rect_ix].ClipRect;

  clip_rect.x = canvas_p0.x;
  clip_rect.y = canvas_p0.y;
  clip_rect.z = canvas_p1.x;
  clip_rect.w = canvas_p1.y;
	    
  ImGui::PopClipRect();
  
  //// Restore mouse position
  io.MousePos = global_node_editor->screen_space_MousePos;
  
  ImGui::EndChild();

  // Draw image display windows
  for (auto& ui_node : global_node_editor->node_pool) {
    if (ui_node.draw_type == CANVAS) {
      ImGui::Begin("Canvas");
      //ImGui::Text("%f, %f", ui_node.texture_size.x, ui_node.texture_size.y);
      ImGui::Image((void*)(intptr_t)ui_node.texture, ui_node.texture_size);
      ImGui::End();
    }
  }
  
}

bool create_gegl_link(NodeProperty *a, NodeProperty *b) {
  Node *start = FindNode(a->node_id);
  Node *end   = FindNode(b->node_id);

  printf("trying to create gegl link between %s (%s) and %s (%s)\n",
	 GEGL_OPERATION_GET_CLASS(gegl_node_get_gegl_operation(start->gegl_node))->name, a->label,
	 GEGL_OPERATION_GET_CLASS(gegl_node_get_gegl_operation(end->gegl_node))->name, b->label);
  
  bool ret = gegl_node_connect(start->gegl_node, a->label,
			      end->gegl_node,   b->label);

  printf("ret %s\n", ret ? "succeed" : "fail");
  return ret;
}

void CreateLink(NodeProperty *a, NodeProperty *b) {  
  if (a->direction == INPUT) {
    std::swap(a, b);
    printf("swapping\n");
  }  

  if (g_type_is_a(a->gtype, g_type_from_name("GeglPad"))) {
    if (!create_gegl_link(a, b)) {
      printf("failed to create gegl link\n");
      return;
    }
  }

  Link *link = global_node_editor->link_pool.request();
  *link = {a->id, b->id};
  global_node_editor->num_links += 1;
  a->links += 1;
  b->links += 1;
}

Node *CreateNode(int node_id) {
  Node *new_node = global_node_editor->node_pool.request();
  new_node->id = node_id;
  new_node->pos = {0,0};
  global_node_editor->num_nodes += 1;
  new_node->layer = global_node_editor->num_nodes;

  return new_node;
}

//// get node from node list, or create node with given id
Node *GetNode(int node_id) {
  for (auto& node : global_node_editor->node_pool) {
    if (node.id == node_id) {
      return &node;
    }
  }
  return CreateNode(node_id);
}

NodeProperty *FindProperty(int property_id) {
  for (auto& property : global_node_editor->pin_pool) {
    if (property.id == property_id) {
      return &property;
    }
  }
  return NULL;
}

Node *FindNode(int node_id) {
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

void set_node_to_top_layer(Node *node) {
  for (auto& n : global_node_editor->node_pool) {
    if (n.layer > node->layer) {
      n.layer -= 1;
    }
  }
  node->layer = global_node_editor->num_nodes;
}

void BeginNode(int node_id) {
  Node *current_node = GetNode(node_id); //Todo implement
  global_node_editor->current_node = current_node;

  ImDrawList* draw_list = ImGui::GetWindowDrawList();
  if (current_node->layer == 0) {
    current_node->layer = global_node_editor->node_pool.size();
  }
  draw_list->ChannelsSetCurrent(node_foreground(*current_node));
  
  ImGui::SetCursorScreenPos(current_node->pos);
  ImGui::PushID(current_node->id);

  //printf("\nstart\n");
  ImGui::BeginGroup();
  // ImGuiWindow* window = ImGui::GetCurrentWindow();
  // window->Pos = current_node->pos;
  ImGui::PushItemWidth(100);
}

void EndNode() {
  Node *current_node = global_node_editor->current_node;
  ImGuiIO& io = ImGui::GetIO();
  ImGui::PopItemWidth();
  ImGui::EndGroup();
  current_node->size = ImRect(ImGui::GetItemRectMin()- global_node_editor->Style_NodeMargin,
			      ImGui::GetItemRectMax()+ global_node_editor->Style_NodeMargin);
  current_node->mouse_in_node = current_node->size.Contains(io.MousePos);

  global_node_editor->current_node = NULL;
  ImGui::PopID();
}

void BeginNodeProperty(NodeProperty *property) {
  ImGui::BeginGroup();
  ImGui::PushID(property->id);
}

// returns width, currently used to calculate indent for output pads for right-alignment
float EndNodeProperty(NodeProperty *property, bool input_p) {
  ImGui::PopID();
  ImGui::EndGroup();

  ImVec2 min = ImGui::GetItemRectMin();
  ImVec2 max = ImGui::GetItemRectMax();
  
  property->rect = ImRect(ImGui::GetItemRectMin(), ImGui::GetItemRectMax());

  ImVec2 pin_pos;
  if (input_p) {
    pin_pos = {min.x - (global_node_editor->Style_NodeMargin) + (global_node_editor->Style_NodeOutlineWidth) / 2.0f,
	       min.y + ((max.y - min.y) / 2)};
  } else {
    pin_pos = {max.x + (global_node_editor->Style_NodeMargin) + (global_node_editor->Style_NodeOutlineWidth) / 2.0f,
      min.y + ((max.y - min.y) / 2)};
  }   

  property->pin_pos = pin_pos;
  return max.x - min.x;
}

float EndOutputProperty(NodeProperty *property) {
  return EndNodeProperty(property, false);
}

float EndInputProperty(NodeProperty *property) {
  return EndNodeProperty(property, true);
}


// To right-align the output pads we keep track of the max width and use that
// to calculate an indent for the output label(s? GEGL only ever has one output per node).
void DrawGeglNode(Node &ui_node) {
  float width = 0;
  GPNode::BeginNode(ui_node.id);

  ImGuiWindow* window = ImGui::GetCurrentWindow();
  // printf("window Pos.x: %f | window Size.x: %f\n", window->Pos.x, window->Size.x);
  // printf(N"ode   pos: %f, %f\n\n", ui_node.pos.x, ui_node.pos.y);
    
  ImGui::Text("layer: %d", ui_node.layer);
  if (ui_node.draw_type == CANVAS) {
    ImGui::Text("Canvas");
  } else {
    // ImGui::Text(ui_node.gegl_operation_klass->name);
    ImGui::Text(GEGL_OPERATION_GET_CLASS(gegl_node_get_gegl_operation(ui_node.gegl_node))->name);
  }
  // ImGui::Separator();
  
  ImGui::Text("Input Pads");
  for (int pad_id : ui_node.gegl_input_pads) {
    NodeProperty *property = FindProperty(pad_id);

    BeginNodeProperty(property);
    ImGui::Text(property->label);
    float w = EndInputProperty(property);
    if (w > width) {
      width = w;
    }
  }
  
  ImGui::Text("Input Properties");
  for (int id : ui_node.input_properties) {
    NodeProperty *property = FindProperty(id);
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

    float w = EndInputProperty(property);
    if (w > width) {
      width = w;
    }    
  }

  if (!ui_node.gegl_output_pads.empty()) {
    ImGui::Spacing();
    ImGui::Text("Output Pads");
  }

  for (auto pad_id : ui_node.gegl_output_pads) {
    NodeProperty *property = FindProperty(pad_id);

    
    BeginNodeProperty(property);
    
    float text_width = ImGui::CalcTextSize(property->label).x;
    ImGui::Indent(width - text_width);    
    ImGui::TextUnformatted(property->label);

    EndOutputProperty(property);
  }
  
  GPNode::EndNode();
}

// void DrawCanvasNode(Node &ui_node) {
//   GPNode::BeginNode(ui_node.id);
//   ImGui::Text("layer: %d", ui_node.layer);
  
//   GPNode::EndNode();
// }

ImTextureID CreateTexture(const void* data, int width, int height) {
  // global_node_editor->textures.resize(global_node_editor->textures.size() + 1);
  // ImTextureID& texture = global_node_editor->textures.back();

  ImTextureID texture;
  GLuint texture_id;
  // Upload texture to graphics system
  glGenTextures(1, &texture_id);
  glBindTexture(GL_TEXTURE_2D, texture_id);
  
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

  // texture.Width  = width;
  // texture.Height = height;

  // return reinterpret_cast<ImTextureID>(static_cast<std::intptr_t>(texture.TextureID));
  texture = (void *)(intptr_t)texture_id;
  return texture;
}

int CreateCanvasNode() {

  item_id_count += 1;
  int node_id = item_id_count;
  Node *ui_node = CreateNode(node_id);

  printf("canvas node layer %d\n", ui_node->layer);
  
  GeglNode *sink = gegl_node_new_child(global_node_editor->graph,
				       "operation", "gegl:buffer-sink",
				       "buffer",    &(ui_node->gegl_buffer), NULL);
  ui_node->gegl_node = sink;
  ui_node->draw_type = CANVAS;

  NodeProperty *property = global_node_editor->pin_pool.request();
  property->direction = INPUT;
  property->node_id = node_id;
  property->label = strdup("input");
  property->gtype = g_type_from_name("GeglPad");
  item_id_count += 1;
  property->id = item_id_count;
  property->hovered = false;
  property->links = 0;

  ui_node->gegl_input_pads.emplace_back(property->id);
  
  // temp texture testing
  // int image_width = 0;
  // int image_height = 0;
  // unsigned char* image_data = stbi_load("./test.jpg", &image_width, &image_height, NULL, 4);
  // if (image_data == NULL)
  //   printf("could not load image\n");

  // ui_node->texture = CreateTexture(image_data, image_width, image_height);
  // ui_node->texture_size = ImVec2(image_width, image_height);

  return node_id;
}

// int CreateGeglNode(char *operation) {

// }

int CreateGeglNode(const char *operation) {
  GeglNode *gegl_node = gegl_node_new_child(global_node_editor->graph, "operation", operation, NULL);
  item_id_count += 1;
  int node_id = item_id_count;
  Node *ui_node = CreateNode(node_id);
  ui_node->draw_type = GEGL;
  ui_node->gegl_node = gegl_node;
//  ui_node->gegl_operation_klass = klass;
  
  printf("Operation name: %s\n", operation);
  
  ui_node->pos = global_node_editor->mouse_pos_in_canvas;
      
  // Add input pads
  printf("Input Pads:\n");
  gchar ** input_pads = gegl_node_list_input_pads(gegl_node);
  for (char **c = input_pads; c != NULL && *c != 0; ++c) {

    NodeProperty *property = global_node_editor->pin_pool.request();
    property->direction = INPUT;
    property->node_id = node_id;
    property->label = strdup(*c);
    property->gtype = g_type_from_name("GeglPad");
    item_id_count += 1;
    property->id = item_id_count;
    property->hovered = false;
    property->links = 0;

    ui_node->gegl_input_pads.emplace_back(property->id);
    
    g_print("\t\t%s\n", *c);
  }
  g_strfreev(input_pads);

  // Add output pads
  printf("Output Pads:\n");
  gchar ** output_pads = gegl_node_list_output_pads(gegl_node);
  for (char **c = output_pads; c != NULL && *c != 0; ++c) {

    NodeProperty *property = global_node_editor->pin_pool.request();
    property->direction = OUTPUT;
    property->node_id = node_id;
    property->label = strdup(*c);
    property->gtype = g_type_from_name("GeglPad");
    item_id_count += 1;
    property->id = item_id_count;
    property->hovered = false;
    property->links = 0;

    ui_node->gegl_output_pads.emplace_back(property->id);
    
    g_print("\t\t%s\n", *c);   
  }
  g_strfreev(output_pads);
  
  // Add input properties
  printf("Properties:\n");
  unsigned int n_properties;
  GeglOperationClass *klass = GEGL_OPERATION_GET_CLASS(gegl_node_get_gegl_operation(ui_node->gegl_node));
  GParamSpec **properties = g_object_class_list_properties((GObjectClass*) klass, &n_properties);
  for (unsigned int j = 0; j < n_properties; ++j) {

    NodeProperty *property = global_node_editor->pin_pool.request();
    property->direction = INPUT;
    property->node_id = node_id;
    property->label = strdup(g_param_spec_get_nick(properties[j]));
    property->gtype = G_PARAM_SPEC_TYPE(properties[j]);
    item_id_count += 1;
    property->id = item_id_count;
    property->hovered = false;
    property->links = 0;

    g_print("\t\t %d  %s\n",property->id, g_param_spec_get_name(properties[j]));

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

    ui_node->input_properties.emplace_back(property->id);
  }
  g_free(properties); // todo is this right?
  
  // select new node
  global_node_editor->selected_nodes.clear();
  global_node_editor->selected_nodes.push_back(ui_node->id);
  
  return node_id;
}

}
