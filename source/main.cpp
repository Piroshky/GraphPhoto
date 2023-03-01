// Dear ImGui: standalone example application for GLFW + OpenGL 3, using programmable pipeline
// (GLFW is a cross-platform general purpose library for handling windows, inputs, OpenGL/Vulkan/Metal graphics context creation, etc.)
// If you are new to Dear ImGui, read documentation from the docs/ folder + read the top of imgui.cpp.
// Read online: https://github.com/ocornut/imgui/tree/master/docs
#define IMGUI_DEFINE_MATH_OPERATORS
#include "imgui.h"
#include "imgui_internal.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include "imgui_internal.h"
#include <stdio.h>
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h> // Will drag system OpenGL headers

#include "math.h"

#include "gpnode.h"

// debug libs
#include <string>

// [Win32] Our example includes a copy of glfw3.lib pre-compiled with VS2010 to maximize ease of testing and compatibility with old VS compilers.
// To link with VS2010-era libraries, VS2015+ requires linking with legacy_stdio_definitions.lib, which we do using this pragma.
// Your own project should not be affected, as you are likely to link with a newer binary of GLFW that is adequate for your version of Visual Studio.
#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

struct gui_node {
  int node_id;
  int node_layer;
  ImVec2 node_pos;
  ImVec2 node_size;
};

int main(int, char**)
{
    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    // Decide GL+GLSL versions
#if defined(IMGUI_IMPL_OPENGL_ES2)
    // GL ES 2.0 + GLSL 100
    const char* glsl_version = "#version 100";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
#elif defined(__APPLE__)
    // GL 3.2 + GLSL 150
    const char* glsl_version = "#version 150";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // Required on Mac
#else
    // GL 3.0 + GLSL 130
    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    //glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only
#endif

    // Create window with graphics context
    GLFWwindow* window = glfwCreateWindow(1280, 720, "The Heart Break Photo Editor", NULL, NULL);
    if (window == NULL)
        return 1;
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    //io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Load Fonts
    // - If no fonts are loaded, dear imgui will use the default font. You can also load multiple fonts and use ImGui::PushFont()/PopFont() to select them.
    // - AddFontFromFileTTF() will return the ImFont* so you can store it if you need to select the font among multiple.
    // - If the file cannot be loaded, the function will return NULL. Please handle those errors in your application (e.g. use an assertion, or display an error and quit).
    // - The fonts will be rasterized at a given size (w/ oversampling) and stored into a texture when calling ImFontAtlas::Build()/GetTexDataAsXXXX(), which ImGui_ImplXXXX_NewFrame below will call.
    // - Read 'docs/FONTS.md' for more instructions and details.
    // - Remember that in C/C++ if you want to include a backslash \ in a string literal you need to write a double backslash \\ !
    //io.Fonts->AddFontDefault();
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Roboto-Medium.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/Cousine-Regular.ttf", 15.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/DroidSans.ttf", 16.0f);
    //io.Fonts->AddFontFromFileTTF("../../misc/fonts/ProggyTiny.ttf", 10.0f);
    //ImFont* font = io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
    //IM_ASSERT(font != NULL);

    // Our state
    bool show_another_window = false;
    ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

    // Create the NodeEditor
    GPNode::InitializeNodeEditor();

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        // Poll and handle events (inputs, window resize, etc.)
        // You can read the io.WantCaptureMouse, io.WantCaptureKeyboard flags to tell if dear imgui wants to use your inputs.
        // - When io.WantCaptureMouse is true, do not dispatch mouse input data to your main application, or clear/overwrite your copy of the mouse data.
        // - When io.WantCaptureKeyboard is true, do not dispatch keyboard input data to your main application, or clear/overwrite your copy of the keyboard data.
        // Generally you may always pass all inputs to dear imgui, and hide them from your application based on those two flags.
        glfwPollEvents();

        // Start the Dear ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
	ImGui::ShowStackToolWindow();
	ImGui::ShowDemoWindow();
	ImGui::Begin("GraphPhoto");
	ImGui::Text("And this is my text");
	
	if (ImGui::BeginTabBar("##TabBar"))
	{
	if (ImGui::BeginTabItem("Canvas"))
        {
	  static ImVector<ImVec2> points;
	  static ImVec2 scrolling(0.0f, 0.0f);
	  static bool opt_enable_grid = true;
	  static bool opt_enable_context_menu = true;
	  static bool adding_line = false;
	  static ImVec2 mpic(0,0);
	  static bool node_selected = false;
	  static ImVec2 node_pos = ImVec2(300, 300);

	  static double zoom = 1;

	  ImGui::Checkbox("Enable grid", &opt_enable_grid);
	  ImGui::Checkbox("Enable context menu", &opt_enable_context_menu);
	  ImGui::Text("Mouse Left: drag to add lines,\nMouse Right: drag to scroll, click for context menu.");
	  ImGui::Text("Zoom: %.1f", zoom);
	  ImGui::Text("Mouse in canvas (%f, %f)\n", mpic.x, mpic.y);
	  ImGui::Text("scrolling (%f, %f)\n", scrolling.x, scrolling.y);

	  // Using InvisibleButton() as a convenience 1) it will advance the layout cursor and 2) allows us to use IsItemHovered()/IsItemActive()
	  ImVec2 canvas_p0 = ImGui::GetCursorScreenPos();      // ImDrawList API uses screen coordinates!
	  ImVec2 canvas_sz = ImGui::GetContentRegionAvail();   // Resize canvas to what's available
	  if (canvas_sz.x < 50.0f) canvas_sz.x = 50.0f;
	  if (canvas_sz.y < 50.0f) canvas_sz.y = 50.0f;
	  ImVec2 canvas_p1 = ImVec2(canvas_p0.x + canvas_sz.x, canvas_p0.y + canvas_sz.y);

	  // Draw border and background color
	  ImGuiIO& io = ImGui::GetIO();
	  ImDrawList* draw_list = ImGui::GetWindowDrawList();
	  draw_list->AddRectFilled(canvas_p0, canvas_p1, IM_COL32(50, 50, 50, 255));
	  draw_list->AddRect(canvas_p0, canvas_p1, IM_COL32(255, 255, 255, 255));

	  // This will catch our interactions
	  ImGui::InvisibleButton("canvas", canvas_sz, ImGuiButtonFlags_MouseButtonLeft | ImGuiButtonFlags_MouseButtonRight);
	  const bool is_hovered = ImGui::IsItemHovered(); // Hovered
	  const bool is_active = ImGui::IsItemActive();   // Held

	  // Pan (we use a zero mouse threshold when there's no context menu)
	  // You may decide to make that threshold dynamic based on whether the mouse is hovering something etc.
	  const float mouse_threshold_for_pan = opt_enable_context_menu ? 0.0f : 0.0f;
	  if (is_active && ImGui::IsMouseDragging(ImGuiMouseButton_Right, mouse_threshold_for_pan))
	  {
	    scrolling.x += io.MouseDelta.x;
	    scrolling.y += io.MouseDelta.y;
	  }
	  
	  ImVec2 origin(canvas_p0.x + scrolling.x, canvas_p0.y + scrolling.y); // Canvas origin in screen space
	  const ImVec2 mouse_widget_pos(io.MousePos.x - canvas_p0.x, io.MousePos.y - canvas_p0.y);
	  const ImVec2 mouse_pos_in_canvas((io.MousePos.x - origin.x) / zoom, (io.MousePos.y - origin.y) / zoom);
	  mpic.y = mouse_pos_in_canvas.y;
	  mpic.x = mouse_pos_in_canvas.x;
	    
	  ImVec2 screen_space_MousePos     = io.MousePos;
	  io.MousePos = mpic;
	  io.MouseDrawCursor = true;

	  // Handle canvas zoom
	  if (io.MouseWheel != 0) {
	    const double zoom_delta = io.MouseWheel * 0.1;
	    const double new_zoom   = zoom + zoom_delta;
            
	    if (new_zoom >= 0.10 && new_zoom < 2.6) {
	      // floating point error means you can't do <= 2.5
	      // Move origin so that zoom happens around mouse location
	      zoom = new_zoom;
	      scrolling.x = mouse_widget_pos.x - (mouse_pos_in_canvas.x * zoom);
	      scrolling.y = mouse_widget_pos.y - (mouse_pos_in_canvas.y * zoom);
	      origin.x = canvas_p0.x + scrolling.x;
	      origin.y = canvas_p0.y + scrolling.y;
	    }            
	  }

	  // Context menu (under default mouse threshold)
	  ImVec2 drag_delta = ImGui::GetMouseDragDelta(ImGuiMouseButton_Right);
	  if (opt_enable_context_menu && drag_delta.x == 0.0f && drag_delta.y == 0.0f)
	    ImGui::OpenPopupOnItemClick("context", ImGuiPopupFlags_MouseButtonRight);
	  if (ImGui::BeginPopup("context"))
	  {
	    if (adding_line)
	      points.resize(points.size() - 2);
	    adding_line = false;
	    if (ImGui::MenuItem("Remove one", NULL, false, points.Size > 0)) { points.resize(points.size() - 2); }
	    if (ImGui::MenuItem("Remove all", NULL, false, points.Size > 0)) { points.clear(); }
	    ImGui::EndPopup();
	  }
              
	  // Draw grid + all lines in the canvas
            
	  ImVec2 canvas_clip_p0((canvas_p0.x - origin.x) / zoom, (canvas_p0.y - origin.y) / zoom);
	  ImVec2 canvas_clip_p1((canvas_p1.x - origin.x) / zoom, (canvas_p1.y - origin.y) / zoom);
          
	  ImGui::PushClipRect(canvas_clip_p0, canvas_clip_p1, false);
	  int canvas_clip_rect_ix = draw_list->CmdBuffer.size() - 1;
          
	  if (opt_enable_grid)
	  {
	    const float GRID_STEP = 64.0f * zoom;
	    for (float x = fmodf(scrolling.x, GRID_STEP); x < canvas_sz.x; x += GRID_STEP)
	      draw_list->AddLine(ImVec2(canvas_p0.x + x, canvas_p0.y), ImVec2(canvas_p0.x + x, canvas_p1.y), IM_COL32(200, 200, 200, 40));
	    for (float y = fmodf(scrolling.y, GRID_STEP); y < canvas_sz.y; y += GRID_STEP)
	      draw_list->AddLine(ImVec2(canvas_p0.x, canvas_p0.y + y), ImVec2(canvas_p1.x, canvas_p0.y + y), IM_COL32(200, 200, 200, 40));
	  }
	  for (int n = 0; n < points.Size; n += 2)
	    draw_list->AddLine(ImVec2(origin.x + points[n].x * zoom , origin.y + points[n].y * zoom), ImVec2(origin.x + points[n + 1].x * zoom, origin.y + points[n + 1].y * zoom), IM_COL32(255, 255, 0, 255), 2.0f);

	  // Start Canvas
	  static ImRect node_size = ImRect(0,0,0,0);
	  static bool node_hovered = false;

	  if(node_hovered) {
	    //printf("mouse over\n");
            if(io.MouseDown[0]) {
	      //printf("mouse down\n");
	      if (node_selected) {                
		node_pos += io.MouseDelta / zoom;
	      } else {
		node_selected = true;                
              }
	    }
	  }

	  if(node_selected && io.MouseReleased[0]) {
	    printf("node released\n");
	    node_selected = false;
	  }       
	  
	  // Canvas elements are drawn in canvas space, then latter those coordinates are converted to screen space

	  ImDrawListSplitter& splitter = draw_list->_Splitter;

	  splitter.Split(draw_list, 3);

	  // splitter.Split(draw_list, 3);
	  // printf("splitter _Count: %d\n", splitter._Count);
	  
	  ImVec2 start_pos = node_pos;
	  const int vtx_ix = draw_list->VtxBuffer.size();
	  draw_list->ChannelsSetCurrent(2);
	  draw_list->AddRectFilled({0,0}, {500,500}, IM_COL32(100, 0, 0, 255)); //red
	  draw_list->ChannelsSetCurrent(1);
	  draw_list->AddRectFilled({250,250}, {750,750}, IM_COL32(0, 0, 100, 255)); //blue
	  draw_list->ChannelsMerge();

	  // Start Node
	  ImGui::SetCursorScreenPos(start_pos);
	  ImGui::PushID(1);
	  ImGui::BeginGroup();

	  ImGui::Text("This is my test text");
	  ImGui::Text("And this is the next line");
	  ImGui::Text("This here is a whole lot of text I don't know how it will work");
	  ImGui::EndGroup();
          node_size = ImRect(ImGui::GetItemRectMin(), ImGui::GetItemRectMax());
	  node_hovered = node_size.Contains(io.MousePos);

	  //printf("is active? %s\n", ImGui::IsItemActive() ? "yes" : "no");
	  //printf("is focused? %s\n", ImGui::IsItemFocused() ? "yes" : "no");
	  //printf("is focused? %s\n", ImGui::IsItemFocused() ? "yes" : "no");
	  // End Node
          
	  draw_list->AddRectFilled(node_size.Min, node_size.Max, IM_COL32(200, 50, 100, 250));
//	  ImGui::GetForegroundDrawList()->AddRectFilled(node_size.Min, node_size.Max, IM_COL32(00, 50, 200, 100));
	  if(node_hovered) {
	    draw_list->AddRect(node_size.Min, node_size.Max, IM_COL32(0, 255, 0, 255));
	  }


	  // Transform canvas points to screen points
	  int vertices_count = draw_list->VtxBuffer.size() - vtx_ix;
	    
	  ImDrawVert *vert = &draw_list->VtxBuffer[draw_list->VtxBuffer.size() - (vertices_count)];
	  for(int i = 0; i < vertices_count; ++i) {
	    vert->pos.x = vert->pos.x * zoom + origin.x;
	    vert->pos.y = vert->pos.y * zoom + origin.y;
	    vert++;
	  }
	  // printf("vert_count %d\n", vertices_count);

	  // vtx_ix = draw_list->VtxBuffer.size();
	  // printf("after vtx_ix %d\n", vtx_ix);

            
	  ImGui::PopID();

	  ImVec4 &clip_rect = draw_list->CmdBuffer[canvas_clip_rect_ix].ClipRect;

	  clip_rect.x = canvas_p0.x;
	  clip_rect.y = canvas_p0.y;
	  clip_rect.z = canvas_p1.x;
	  clip_rect.w = canvas_p1.y;
	    
	  ImGui::PopClipRect();
	  io.MousePos = screen_space_MousePos;
	  // End Canvas
            
	  ImGui::EndTabItem();
        }
	if (ImGui::BeginTabItem("NodeEditor")) {
	  ImGui::Checkbox("Enable grid", &GPNode::global_node_editor->grid_enabled);
	  ImGui::Text("Zoom: %.1f", GPNode::global_node_editor->zoom);
	  static char intext2[100];
	  static float d = 1.0;
	  ImGui::InputText("Text Input", intext2, IM_ARRAYSIZE(intext2));

	  std::string selected_nodes = "";
	  for (auto a : GPNode::global_node_editor->selected_nodes) {
	    selected_nodes += std::to_string(a);
	    selected_nodes += " ";
	  }
	  ImGui::Text("Selected Nodes: %s", selected_nodes.c_str());
	  
	  GPNode::BeginNodeEditor();
	  
	  GPNode::BeginNode(1);
	  ImGui::Text("This is my test text");
	  ImGui::Text("some more text");
	  ImGui::DragFloat("my float", &d, 0.01f);
	  static char intext[100];
	  ImGui::InputText("Text Input", intext, IM_ARRAYSIZE(intext));
	  GPNode::EndNode();

	  GPNode::BeginNode(2);
	  ImGui::Text("This is my second node");
	  ImGui::Text("some more text");
	  GPNode::EndNode();

	  GPNode::BeginNode(3);
	  ImGui::Text("This is my third node");
	  ImGui::Text("some more text");
	  GPNode::EndNode();
	  
	  GPNode::EndNodeEditor();
	  
	  ImGui::EndTabItem();
	}
	ImGui::EndTabBar();
	}
	ImGui::End();
	
	
        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
