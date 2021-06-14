#include <application.h>
#include "utilities/builders.h"
#include "utilities/widgets.h"
#include <imgui_node_editor.h>
#include <gegl.h>


#define IMGUI_DEFINE_MATH_OPERATORS

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <utility>

namespace util = NodeEditor::Utilities;
namespace ed = NodeEditor;

static inline ImRect ImRect_Expanded(const ImRect& rect, float x, float y)
{
    auto result = rect;
    result.Min.x -= x;
    result.Min.y -= y;
    result.Max.x += x;
    result.Max.y += y;
    return result;
}

using ax::Widgets::IconType;

static ed::EditorContext* editor = nullptr;



//extern "C" __declspec(dllimport) short __stdcall GetAsyncKeyState(int vkey);
//extern "C" bool Debug_KeyPress(int vkey)
//{
//    static std::map<int, bool> state;
//    auto lastState = state[vkey];
//    state[vkey] = (GetAsyncKeyState(vkey) & 0x8000) != 0;
//    if (state[vkey] && !lastState)
//        return true;
//    else
//        return false;
//}

enum class PinType {
    GEGL_BUFFER,
    GEGL_COLOR,
    DOUBLE,
    STRING,
    INT,
    // FLOAT,
    BOOLEAN,
    DELEGATE, //@TODO
};

enum class NodeStyle {
  Blueprint,
  Simple,
  Tree,
  Comment,
  Houdini
};

struct Node;
struct Link;

typedef ed::NodeId NodeId;
typedef ed::PinId  PinId;
typedef ed::LinkId LinkId;

typedef ed::PinDirection PinDirection;

struct Pin {
  PinId   ID;
  ::Node*     Node;
  std::string Name;
  PinType     Type;
  PinDirection     Kind;
  std::vector<LinkId> links;

  Pin(int id, const char* name, PinType type):
    ID(id), Node(nullptr), Name(name), Type(type), Kind(PinDirection::INPUT)
  {}
};

struct Link {
  LinkId ID;

  PinId StartPinID;
  PinId EndPinID;

  ImColor Color;

  Link(LinkId id, PinId startPinId, PinId endPinId):
    ID(id), StartPinID(startPinId), EndPinID(endPinId), Color(255, 255, 255)
  {
  }
};

struct Node {
  NodeId ID;
  std::string Name;
  std::vector<Pin> Inputs;
  std::vector<Pin> Outputs;
  ImColor Color;
  NodeStyle Type;
  ImVec2 Size;
  bool is_selected;

  std::string State;
  std::string SavedState;

  Node(int id, const char* name, ImColor color = ImColor(255, 255, 255)):
    ID(id), Name(name), Color(color), Type(NodeStyle::Blueprint), Size(0, 0),
    is_selected(false)
  {
  }
};

static const int            s_PinIconSize = 24;
static std::vector<Node>    s_Nodes;
static std::vector<Link>    s_Links;
static ImTextureID          s_HeaderBackground = nullptr;
//static ImTextureID          s_SampleImage = nullptr;
static ImTextureID          s_SaveIcon = nullptr;
static ImTextureID          s_RestoreIcon = nullptr;
static ImTextureID          s_Test = nullptr;


int testimageWidth;
int testimageHeight;

struct NodeIdLess {
    bool operator()(const NodeId& lhs, const NodeId& rhs) const {
        return lhs.AsPointer() < rhs.AsPointer();
    }
};

static const float          s_TouchTime = 1.0f;
static std::map<NodeId, float, NodeIdLess> s_NodeTouchTime;

static int s_NextId = 1;
static int GetNextId() {
    return s_NextId++;
}

//static NodeId GetNextNodeId()
//{
//    return NodeId(GetNextId());
//}

static LinkId GetNextLinkId()
{
    return LinkId(GetNextId());
}

static void TouchNode(NodeId id)
{
    s_NodeTouchTime[id] = s_TouchTime;
}

static float GetTouchProgress(NodeId id)
{
    auto it = s_NodeTouchTime.find(id);
    if (it != s_NodeTouchTime.end() && it->second > 0.0f)
        return (s_TouchTime - it->second) / s_TouchTime;
    else
        return 0.0f;
}

static void UpdateTouch()
{
    const auto deltaTime = ImGui::GetIO().DeltaTime;
    for (auto& entry : s_NodeTouchTime)
    {
        if (entry.second > 0.0f)
            entry.second -= deltaTime;
    }
}

static Node* FindNode(NodeId id)
{
    for (auto& node : s_Nodes)
        if (node.ID == id)
            return &node;

    return nullptr;
}

static Link* FindLink(LinkId id)
{
    for (auto& link : s_Links)
        if (link.ID == id)
            return &link;

    return nullptr;
}



static Pin* FindPin(PinId id) {
    if (!id)
        return nullptr;

    for (auto& node : s_Nodes) {
      for (auto& pin : node.Inputs) {
	if (pin.ID == id)
	  return &pin;
      }

      for (auto& pin : node.Outputs) {
	if (pin.ID == id)
	  return &pin;
      }
    }

    return nullptr;
}

void delete_link(LinkId link_id) {
  Link *link = FindLink(link_id);
  
  if (link == nullptr) {printf("null link\n");}
  
  Pin *start = FindPin(link->StartPinID);
  Pin *end   = FindPin(link->EndPinID);

  auto id = std::find_if(start->links.begin(), start->links.end(), 
                         [link_id](auto& link) { return link == link_id; });
  if (id != start->links.end()) { //@Todo shouldn't this always find something?
    start->links.erase(id);
  } 

  id = std::find_if(end->links.begin(), end->links.end(), 
		    [link_id](auto& link) { return link == link_id; });
  if (id != end->links.end()) {
    end->links.erase(id);
  } 
  editor->DeleteLink(link_id);
}

void create_link(PinId startPinId, PinId endPinId) {
  LinkId new_link = GetNextId();
  s_Links.emplace_back(new_link, startPinId, endPinId); 
  
  Pin *start = FindPin(startPinId);
  Pin *end   = FindPin(endPinId);

  if (start == nullptr || end == nullptr) {
    fprintf(stderr, "error: tried to create and one or more of the pins is missing\n");
    exit(1);
  }
  start->links.emplace_back(new_link);
  if (!end->links.empty()) {
    printf ("end pin not empty\n");
    for (LinkId link_id : end->links) {
      delete_link(link_id);
    }
  }
  end->links.clear();
  end->links.emplace_back(new_link);    
}



// @TODO lol this is so slow
static bool IsPinLinked(PinId id)
{
    if (!id)
        return false;

    for (auto& link : s_Links)
        if (link.StartPinID == id || link.EndPinID == id)
            return true;

    return false;
}

static bool CanCreateLink(Pin* a, Pin* b) {
  if (!a || !b || a == b || a->Node == b->Node ||
      a->Kind == b->Kind || a->Type != b->Type ||
      b->links.size() != 0)
      return false;
  
  // printf("a: %s links %d\n", a->Name.c_str(), a->links.size());
  // printf("b  %slinks %d\n\n", b->Name.c_str(), b->links.size());

  return true;
}

static void BuildNode(Node* node) {
  for (auto& input : node->Inputs) {
    input.Node = node;
    input.Kind = PinDirection::INPUT;
  }

  for (auto& output : node->Outputs) {
    output.Node = node;
    output.Kind = PinDirection::OUTPUT;
  }
}

#include "prebuilt-gegl-nodes.c"
#include "heartbreak_menu.h"

void BuildNodes() {
  for (auto& node : s_Nodes)  {
    BuildNode(&node);

  }
}

const char* Application_GetName() {
    return "Heart Break Photo Editor";
}

void Application_Initialize() {  
  ed::Config config;
  config.SettingsFile = "Blueprints.json";
    
  config.LoadNodeSettings = [](NodeId nodeId, char* data, void* userPointer) -> size_t
  {
    auto node = FindNode(nodeId);
    if (!node)
      return 0;

    if (data != nullptr)
      memcpy(data, node->State.data(), node->State.size());
    return node->State.size();
  };

    config.SaveNodeSettings = [](NodeId nodeId, const char* data, size_t size, ed::SaveReasonFlags reason, void* userPointer) -> bool
    {
        auto node = FindNode(nodeId);
        if (!node)
            return false;

        node->State.assign(data, size);

        TouchNode(nodeId);

        return true;
    };

    editor = CreateEditor(&config);
    
    
    Node* node;
    node = create_node__gegl_alien_map();      editor->SetNodePosition(node->ID, ImVec2(-252, 220));
    node = create_node__gegl_alien_map();      editor->SetNodePosition(node->ID, ImVec2(-252, 220));
    node = create_node__gegl_alien_map();      editor->SetNodePosition(node->ID, ImVec2(-252, 220));

    editor->NavigateToContent();

    gegl_init(nullptr, nullptr);
    g_object_set (gegl_config (),
		  "application-license", "GPL3",
		  NULL);

    GeglNode *gegl = gegl_node_new ();
    GeglNode *load = gegl_node_new_child (gegl,
					  "operation", "gegl:load",
					  "path", "MyImage01.jpg",
					  NULL);

    GeglNode *over       = gegl_node_new_child (gegl,
						"operation", "gegl:over",
						NULL);
    GeglNode *text       = gegl_node_new_child (gegl,
						"operation", "gegl:text",
						"size", 10.0,
						"color", gegl_color_new ("rgb(1.0,1.0,1.0)"),
						"string", "Hell Yes",
						NULL);

    GeglBuffer *buffer  = NULL;
    // g_autoptr (GeglBuffer) buffer = NULL;

    GeglNode *sink = gegl_node_new_child (gegl,
					  "operation", "gegl:buffer-sink",
					  "buffer", &buffer,
					  NULL);
    
    gegl_node_link_many(load, over, sink, NULL);
    gegl_node_connect_to (text, "output",  over, "aux");
    gegl_node_process(sink);    
    
    testimageHeight = gegl_buffer_get_height(buffer);
    testimageWidth  = gegl_buffer_get_width(buffer);
    int count = gegl_buffer_get_pixel_count(buffer);       

    // printf("w: %d\, h: %d\n", testimageHeight, testimageWidth);

    size_t testsize = count * 4 * sizeof(char);
    printf("testsize %d\n", testsize);
    
    void *data = malloc(testsize);

    if (data == nullptr) {
      printf("MALLOC FAILED!\n");
    } else {
      printf("data %p\n", data);
    }

    gegl_buffer_get (buffer,
		     NULL,
		     1.0,
		     babl_format ("R'G'B'A u8"),
		     data, GEGL_AUTO_ROWSTRIDE,
		     GEGL_ABYSS_NONE);

    // for (int i = 0; i < count ; i += 4) {
    //   ((char *)data)[i] = 255;
    //   ((char *)data)[i+1] = 0;
    //   ((char *)data)[i+2] = 0;
    //   ((char *)data)[i+3] = 255;
    // }

    s_Test = Application_LoadRGBA32(data, testimageWidth, testimageHeight);

    // s_Test             = Application_LoadTexture("MyImage01.jpg");
    // testimageWidth  = Application_GetTextureWidth(s_Test);
    // testimageHeight = Application_GetTextureWidth(s_Test);


    
    BuildNodes();

    // s_Links.push_back(Link(GetNextLinkId(), s_Nodes[5].Outputs[0].ID, s_Nodes[6].Inputs[0].ID));
    // s_Links.push_back(Link(GetNextLinkId(), s_Nodes[5].Outputs[0].ID, s_Nodes[7].Inputs[0].ID));
    // s_Links.push_back(Link(GetNextLinkId(), s_Nodes[14].Outputs[0].ID, s_Nodes[15].Inputs[0].ID));

    s_HeaderBackground = Application_LoadTexture("data/BlueprintBackground.png");
    s_SaveIcon         = Application_LoadTexture("data/ic_save_white_24dp.png");
    s_RestoreIcon      = Application_LoadTexture("data/ic_restore_white_24dp.png");
    
    //auto& io = ImGui::GetIO();
}

void Application_Finalize() {
  auto releaseTexture = [](ImTextureID& id) {
    if (id) {
      Application_DestroyTexture(id);
      id = nullptr;
    }
  };

  releaseTexture(s_RestoreIcon);
  releaseTexture(s_SaveIcon);
  releaseTexture(s_HeaderBackground);

  if (editor) {
    editor->~EditorContext();
    editor = nullptr;
  }
}

static bool Splitter(bool split_vertically, float thickness, float* size1, float* size2, float min_size1, float min_size2, float splitter_long_axis_size = -1.0f)
{
    using namespace ImGui;
    ImGuiContext& g = *GImGui;
    ImGuiWindow* window = g.CurrentWindow;
    ImGuiID id = window->GetID("##Splitter");
    ImRect bb;
    bb.Min = window->DC.CursorPos + (split_vertically ? ImVec2(*size1, 0.0f) : ImVec2(0.0f, *size1));
    bb.Max = bb.Min + CalcItemSize(split_vertically ? ImVec2(thickness, splitter_long_axis_size) : ImVec2(splitter_long_axis_size, thickness), 0.0f, 0.0f);
    return SplitterBehavior(bb, id, split_vertically ? ImGuiAxis_X : ImGuiAxis_Y, size1, size2, min_size1, min_size2, 0.0f);
}


ImColor GetIconColor(PinType type) {
  switch (type)
  {
  default:
  case PinType::GEGL_BUFFER:     return ImColor(255, 255, 255); //white
  case PinType::GEGL_COLOR:      return ImColor(247,  31,  31); //red
  case PinType::DOUBLE:          return ImColor(147, 226,  74); //lime green
  case PinType::STRING:          return ImColor(255, 173,  56); //yellow orange
  case PinType::BOOLEAN:         return ImColor( 56, 146, 255); //blue
  case PinType::INT:             return ImColor(245,  56, 255); //heliotrope 
      
    // case PinType::Object:   return ImColor( 51, 150, 215);
    // case PinType::Function: return ImColor(218,   0, 183);
    // case PinType::Delegate: return ImColor(255,  48,  48);
  }
};

void DrawPinIcon(Pin *pin, bool connected, int alpha)
{
    IconType iconType;
    ImColor  color = GetIconColor(pin->Type);
    color.Value.w = alpha / 255.0f;
    switch (pin->Type)
    {
        case PinType::GEGL_BUFFER:     iconType = IconType::Flow;   break;
        // case PinType::BOOL:     iconType = IconType::Circle; break;
        // case PinType::INT:      iconType = IconType::Circle; break;
        // case PinType::Float:    iconType = IconType::Circle; break;
        // case PinType::String:   iconType = IconType::Circle; break;
        // case PinType::Object:   iconType = IconType::Circle; break;
        // case PinType::Function: iconType = IconType::Circle; break;
        // case PinType::Delegate: iconType = IconType::Square; break;
        default:
	  iconType = IconType::Circle; break;
    }

    ax::Widgets::Icon(ImVec2(s_PinIconSize, s_PinIconSize), iconType, connected, color, ImColor(32, 32, 32, alpha));
};

void ShowStyleEditor(bool* show = nullptr) {
    if (!ImGui::Begin("Style", show)) {
        ImGui::End();
        return;
    }

    auto paneWidth = ImGui::GetContentRegionAvailWidth();

    auto& editorStyle = editor->m_Style;
    ImGui::BeginHorizontal("Style buttons", ImVec2(paneWidth, 0), 1.0f);
    ImGui::TextUnformatted("Values");
    ImGui::Spring();
    if (ImGui::Button("Reset to defaults"))
        editorStyle = editor->m_Style;
    ImGui::EndHorizontal();
    ImGui::Spacing();
    ImGui::DragFloat4("Node Padding", &editorStyle.NodePadding.x, 0.1f, 0.0f, 40.0f);
    ImGui::DragFloat("Node Rounding", &editorStyle.NodeRounding, 0.1f, 0.0f, 40.0f);
    ImGui::DragFloat("Node Border Width", &editorStyle.NodeBorderWidth, 0.1f, 0.0f, 15.0f);
    ImGui::DragFloat("Hovered Node Border Width", &editorStyle.HoveredNodeBorderWidth, 0.1f, 0.0f, 15.0f);
    ImGui::DragFloat("Selected Node Border Width", &editorStyle.SelectedNodeBorderWidth, 0.1f, 0.0f, 15.0f);
    ImGui::DragFloat("Pin Rounding", &editorStyle.PinRounding, 0.1f, 0.0f, 40.0f);
    ImGui::DragFloat("Pin Border Width", &editorStyle.PinBorderWidth, 0.1f, 0.0f, 15.0f);
    ImGui::DragFloat("Link Strength", &editorStyle.LinkStrength, 1.0f, 0.0f, 500.0f);
    //ImVec2  SourceDirection;
    //ImVec2  TargetDirection;
    ImGui::DragFloat("Scroll Duration", &editorStyle.ScrollDuration, 0.001f, 0.0f, 2.0f);
    ImGui::DragFloat("Flow Marker Distance", &editorStyle.FlowMarkerDistance, 1.0f, 1.0f, 200.0f);
    ImGui::DragFloat("Flow Speed", &editorStyle.FlowSpeed, 1.0f, 1.0f, 2000.0f);
    ImGui::DragFloat("Flow Duration", &editorStyle.FlowDuration, 0.001f, 0.0f, 5.0f);
    //ImVec2  PivotAlignment;
    //ImVec2  PivotSize;
    //ImVec2  PivotScale;
    //float   PinCorners;
    //float   PinRadius;
    //float   PinArrowSize;
    //float   PinArrowWidth;
    ImGui::DragFloat("Group Rounding", &editorStyle.GroupRounding, 0.1f, 0.0f, 40.0f);
    ImGui::DragFloat("Group Border Width", &editorStyle.GroupBorderWidth, 0.1f, 0.0f, 15.0f);

    ImGui::Separator();

    static ImGuiColorEditFlags edit_mode = ImGuiColorEditFlags_RGB;
    ImGui::BeginHorizontal("Color Mode", ImVec2(paneWidth, 0), 1.0f);
    ImGui::TextUnformatted("Filter Colors");
    ImGui::Spring();
    ImGui::RadioButton("RGB", &edit_mode, ImGuiColorEditFlags_RGB);
    ImGui::Spring(0);
    ImGui::RadioButton("HSV", &edit_mode, ImGuiColorEditFlags_HSV);
    ImGui::Spring(0);
    ImGui::RadioButton("HEX", &edit_mode, ImGuiColorEditFlags_HEX);
    ImGui::EndHorizontal();

    static ImGuiTextFilter filter;
    filter.Draw("", paneWidth);

    ImGui::Spacing();

    ImGui::PushItemWidth(-160);
    for (int i = 0; i < ed::StyleColor_Count; ++i)
    {
        auto name = editor->GetStyleColorName((ed::StyleColor)i);
        if (!filter.PassFilter(name))
            continue;

        ImGui::ColorEdit4(name, &editorStyle.Colors[i].x, edit_mode);
    }
    ImGui::PopItemWidth();

    ImGui::End();
}

void ShowLeftPane(float paneWidth) {
    auto& io = ImGui::GetIO();

    ImGui::BeginChild("Selection", ImVec2(paneWidth, 0));

    paneWidth = ImGui::GetContentRegionAvailWidth();

    static bool showStyleEditor = false;
    ImGui::BeginHorizontal("Style Editor", ImVec2(paneWidth, 0));
    ImGui::Spring(0.0f, 0.0f);
    if (ImGui::Button("Zoom to Content"))
        editor->NavigateToContent();
    ImGui::Spring(0.0f);
    if (ImGui::Button("Show Flow"))
    {
        for (auto& link : s_Links)
            editor->Flow(link.ID);
    }
    ImGui::Spring();
    if (ImGui::Button("Edit Style"))
        showStyleEditor = true;
    ImGui::EndHorizontal();

    if (showStyleEditor)
        ShowStyleEditor(&showStyleEditor);

    std::vector<NodeId> selectedNodes;
    std::vector<LinkId> selectedLinks;
    selectedNodes.resize(editor->GetSelectedObjectCount());
    selectedLinks.resize(editor->GetSelectedObjectCount());

    int nodeCount = editor->GetSelectedNodes(selectedNodes.data(), static_cast<int>(selectedNodes.size()));
    int linkCount = editor->GetSelectedLinks(selectedLinks.data(), static_cast<int>(selectedLinks.size()));

    selectedNodes.resize(nodeCount);
    selectedLinks.resize(linkCount);

    int saveIconWidth     = Application_GetTextureWidth(s_SaveIcon);
    int saveIconHeight    = Application_GetTextureWidth(s_SaveIcon);
    int restoreIconWidth  = Application_GetTextureWidth(s_RestoreIcon);
    int restoreIconHeight = Application_GetTextureWidth(s_RestoreIcon);



    ImGui::GetWindowDrawList()->AddRectFilled(
        ImGui::GetCursorScreenPos(),
        ImGui::GetCursorScreenPos() + ImVec2(paneWidth, ImGui::GetTextLineHeight()),
        ImColor(ImGui::GetStyle().Colors[ImGuiCol_HeaderActive]), ImGui::GetTextLineHeight() * 0.25f);
    ImGui::Spacing(); ImGui::SameLine();
    ImGui::TextUnformatted("Nodes");
    ImGui::Indent();
    for (auto& node : s_Nodes)
    {
        ImGui::PushID(node.ID.AsPointer());
        auto start = ImGui::GetCursorScreenPos();

        if (const auto progress = GetTouchProgress(node.ID))
        {
            ImGui::GetWindowDrawList()->AddLine(
                start + ImVec2(-8, 0),
                start + ImVec2(-8, ImGui::GetTextLineHeight()),
                IM_COL32(255, 0, 0, 255 - (int)(255 * progress)), 4.0f);
        }

        // bool isSelected = std::find(selectedNodes.begin(), selectedNodes.end(), node.ID) != selectedNodes.end();
	bool isSelected = node.is_selected;
        if (ImGui::Selectable((node.Name + "##" + std::to_string(reinterpret_cast<uintptr_t>(node.ID.AsPointer()))).c_str(), &isSelected))
        {
            if (io.KeyCtrl)
            {
                if (isSelected)
		  editor->SelectNode(node.ID, true);
                else
		  editor->DeselectNode(node.ID);
            }
            else
	      editor->SelectNode(node.ID, false);

            editor->NavigateToSelection();
        }
        if (ImGui::IsItemHovered() && !node.State.empty()) {
            ImGui::SetTooltip("State: %s", node.State.c_str());
	}

        auto id = std::string("(") + std::to_string(reinterpret_cast<uintptr_t>(node.ID.AsPointer())) + ")";
        auto textSize = ImGui::CalcTextSize(id.c_str(), nullptr);
        auto iconPanelPos = start + ImVec2(
            paneWidth - ImGui::GetStyle().FramePadding.x - ImGui::GetStyle().IndentSpacing - saveIconWidth - restoreIconWidth - ImGui::GetStyle().ItemInnerSpacing.x * 1,
            (ImGui::GetTextLineHeight() - saveIconHeight) / 2);
        ImGui::GetWindowDrawList()->AddText(
            ImVec2(iconPanelPos.x - textSize.x - ImGui::GetStyle().ItemInnerSpacing.x, start.y),
            IM_COL32(255, 255, 255, 255), id.c_str(), nullptr);

        auto drawList = ImGui::GetWindowDrawList();
        ImGui::SetCursorScreenPos(iconPanelPos);
        ImGui::SetItemAllowOverlap();
        if (node.SavedState.empty())
        {
            if (ImGui::InvisibleButton("save", ImVec2((float)saveIconWidth, (float)saveIconHeight)))
                node.SavedState = node.State;

            if (ImGui::IsItemActive())
                drawList->AddImage(s_SaveIcon, ImGui::GetItemRectMin(), ImGui::GetItemRectMax(), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255, 255, 255, 96));
            else if (ImGui::IsItemHovered())
                drawList->AddImage(s_SaveIcon, ImGui::GetItemRectMin(), ImGui::GetItemRectMax(), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255, 255, 255, 255));
            else
                drawList->AddImage(s_SaveIcon, ImGui::GetItemRectMin(), ImGui::GetItemRectMax(), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255, 255, 255, 160));
        }
        else
        {
            ImGui::Dummy(ImVec2((float)saveIconWidth, (float)saveIconHeight));
            drawList->AddImage(s_SaveIcon, ImGui::GetItemRectMin(), ImGui::GetItemRectMax(), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255, 255, 255, 32));
        }

        ImGui::SameLine(0, ImGui::GetStyle().ItemInnerSpacing.x);
        ImGui::SetItemAllowOverlap();
        if (!node.SavedState.empty())
        {
            if (ImGui::InvisibleButton("restore", ImVec2((float)restoreIconWidth, (float)restoreIconHeight)))
            {
                node.State = node.SavedState;
                editor->RestoreNodeState(node.ID);
                node.SavedState.clear();
            }

            if (ImGui::IsItemActive())
                drawList->AddImage(s_RestoreIcon, ImGui::GetItemRectMin(), ImGui::GetItemRectMax(), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255, 255, 255, 96));
            else if (ImGui::IsItemHovered())
                drawList->AddImage(s_RestoreIcon, ImGui::GetItemRectMin(), ImGui::GetItemRectMax(), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255, 255, 255, 255));
            else
                drawList->AddImage(s_RestoreIcon, ImGui::GetItemRectMin(), ImGui::GetItemRectMax(), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255, 255, 255, 160));
        }
        else
        {
            ImGui::Dummy(ImVec2((float)restoreIconWidth, (float)restoreIconHeight));
            drawList->AddImage(s_RestoreIcon, ImGui::GetItemRectMin(), ImGui::GetItemRectMax(), ImVec2(0, 0), ImVec2(1, 1), IM_COL32(255, 255, 255, 32));
        }

        ImGui::SameLine(0, 0);
        ImGui::SetItemAllowOverlap();
        ImGui::Dummy(ImVec2(0, (float)restoreIconHeight));

        ImGui::PopID();
    }
    ImGui::Unindent();

    static int changeCount = 0;

    ImGui::GetWindowDrawList()->AddRectFilled(
        ImGui::GetCursorScreenPos(),
        ImGui::GetCursorScreenPos() + ImVec2(paneWidth, ImGui::GetTextLineHeight()),
        ImColor(ImGui::GetStyle().Colors[ImGuiCol_HeaderActive]), ImGui::GetTextLineHeight() * 0.25f);
    ImGui::Spacing(); ImGui::SameLine();
    ImGui::TextUnformatted("Selection");

    ImGui::BeginHorizontal("Selection Stats", ImVec2(paneWidth, 0));
    ImGui::Text("Changed %d time%s", changeCount, changeCount > 1 ? "s" : "");
    ImGui::Spring();
    if (ImGui::Button("Deselect All"))
      editor->ClearSelection();
    ImGui::EndHorizontal();
    ImGui::Indent();

    for (int i = 0; i < nodeCount; ++i)
      ImGui::Text("Node (%p)", selectedNodes[i].AsPointer());

    for (int i = 0; i < linkCount; ++i)
      ImGui::Text("Link (%p)", selectedLinks[i].AsPointer());
    
    ImGui::Unindent();

    if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_Z)))
        for (auto& link : s_Links)
	  editor->Flow(link.ID);

    // move selection around
    if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_RightArrow))) {
      if (nodeCount == 1 && linkCount == 0) {
	Node* selected = FindNode(selectedNodes[0]);
	for (Pin pin : selected->Outputs) {
	  if (!pin.links.empty()) {
            

	    LinkId top_link;
	    ImVec2 pos(FLT_MAX, FLT_MAX);
	    for (LinkId link : pin.links) {
	      Pin *pin = FindPin(FindLink(link)->EndPinID);
	      ImVec2 cur = editor->GetNodePosition(pin->Node->ID);
	      if (cur.y < pos.y) {
		pos.y = cur.y;
		top_link = link;
	      }
	    }

	    editor->ClearSelection();
	    editor->SelectLink(top_link, true);
	    break;
	  }
	}
      }
      else if (linkCount == 1 && nodeCount == 0) {
	Link* selected = FindLink(selectedLinks[0]);
	Pin*  output   = FindPin(selected->EndPinID);
	if (output && output->Node) {
	  editor->ClearSelection();
	  editor->SelectNode(output->Node->ID, true);
	}
      }
    } 

    // Navigate Left
    else if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_LeftArrow))) {
      if (nodeCount == 1 && linkCount == 0) {
	Node* selected = FindNode(selectedNodes[0]);
	for (Pin pin : selected->Inputs) {
	  if (!pin.links.empty()) {
	    editor->ClearSelection();
	    editor->SelectLink(pin.links[0], true);
	    break;
	  } else {
	  }
	}
      }
      else if (linkCount == 1 && nodeCount == 0) {
	Link* selected = FindLink(selectedLinks[0]);
	Pin*  input    = FindPin(selected->StartPinID);
	if (input && input->Node) {
	  editor->ClearSelection();
	  editor->SelectNode(input->Node->ID, true);
	}
      }
    } 

    // Navigate Down
    else if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_DownArrow))) {
      if (linkCount == 1 && nodeCount == 0) {
	Link *selected = FindLink(selectedLinks[0]);
	Pin  *input    = FindPin(selected->StartPinID);
	Pin  *output   = FindPin(selected->EndPinID);

	ImVec2 pos = editor->GetNodePosition(output->Node->ID);	

	LinkId top_link;
	LinkId bottom_link;
	ImVec2 bottom_pos(FLT_MAX, FLT_MAX);
	ImVec2 start_pos = editor->GetNodePosition(output->Node->ID);
	ImVec2 next_pos(FLT_MAX, FLT_MAX);

	for (LinkId link : input->links) {
	  if (link == selected->ID) {continue;}
	  Pin *pin = FindPin(FindLink(link)->EndPinID);
	  ImVec2 cur = editor->GetNodePosition(pin->Node->ID);
	  if ((cur.y > start_pos.y) && (cur.y < next_pos.y)) {
	    next_pos.y = cur.y;
	    top_link = link;
	  }
	  if (cur.y < bottom_pos.y) {
	    bottom_pos.y = cur.y;
	    bottom_link = link;
	  }
	}
	if (next_pos.y == FLT_MAX) {top_link = bottom_link;}

	editor->ClearSelection();
	editor->SelectLink(top_link, true);
      }
    }

    // Navigate Up
    else if (ImGui::IsKeyPressed(ImGui::GetKeyIndex(ImGuiKey_UpArrow))) {
      if (linkCount == 1 && nodeCount == 0) {
	Link *selected = FindLink(selectedLinks[0]);
	Pin  *input    = FindPin(selected->StartPinID);
	Pin  *output   = FindPin(selected->EndPinID);

	ImVec2 start_pos = editor->GetNodePosition(output->Node->ID);

	LinkId next_link;        
	ImVec2 next_pos(FLT_MIN, FLT_MIN);

	LinkId bottom_link;
	ImVec2 bottom_pos(FLT_MAX, FLT_MAX);

	for (LinkId link : input->links) {
	  if (link == selected->ID) {continue;}

	  Pin   *pin = FindPin(FindLink(link)->EndPinID);
	  ImVec2 cur = editor->GetNodePosition(pin->Node->ID);

	  if ((cur.y < start_pos.y) && (cur.y > next_pos.y)) {
	    next_pos.y = cur.y;
	    next_link = link;
	  }
	  if (cur.y < bottom_pos.y) {
	    bottom_pos.y = cur.y;
	    bottom_link = link;
	  }
	}
	if (next_pos.y == FLT_MIN) {next_link = bottom_link;}

	editor->ClearSelection();
	editor->SelectLink(next_link, true);
      }
    }

    if (editor->HasSelectionChanged())
        ++changeCount;

    ImGui::EndChild();
}

void Application_Frame() {
  UpdateTouch();

  auto& io = ImGui::GetIO();

  ImGui::Begin("OpenGL Texture Text");
  ImGui::Text("pointer = %p", s_Test);
  ImGui::Text("size = %d x %d", testimageWidth, testimageHeight);
  ImGui::Image((void*)(intptr_t)s_Test, ImVec2(testimageWidth, testimageHeight));
  ImGui::End();
  
  ImGui::Text("FPS: %.2f (%.2gms)", io.Framerate, io.Framerate ? 1000.0f / io.Framerate : 0.0f);

  //auto& style = ImGui::GetStyle();

  static NodeId contextNodeId      = 0;
  static LinkId contextLinkId      = 0;
  static PinId  contextPinId       = 0;
  static bool createNewNode  = false;
  static Pin* newNodeLinkPin = nullptr;
  static Pin* newLinkPin     = nullptr;

  static float leftPaneWidth  = 400.0f;
  static float rightPaneWidth = 800.0f;
  Splitter(true, 4.0f, &leftPaneWidth, &rightPaneWidth, 50.0f, 50.0f);

  ShowLeftPane(leftPaneWidth - 4.0f);

  ImGui::SameLine(0.0f, 12.0f);

  editor->Begin("Node editor");
  {
    auto cursorTopLeft = ImGui::GetCursorScreenPos();

    util::BlueprintNodeBuilder builder(s_HeaderBackground, Application_GetTextureWidth(s_HeaderBackground), Application_GetTextureHeight(s_HeaderBackground));
    
    // draws the nodes we're interested in.
    for (auto& node : s_Nodes) {
      if (node.Type != NodeStyle::Blueprint && node.Type != NodeStyle::Simple) {
	continue;
      }

      const bool isSimple = node.Type == NodeStyle::Simple;

      bool hasOutputDelegates = false;
      //@TODO: what is this?
      // for (auto& output : node.Outputs)
      //     if (output.Type == PinType::Delegate)
      //         hasOutputDelegates = true;
      

      builder.Begin(node.ID);
      if (!isSimple) {
	builder.Header(node.Color);
	ImGui::Spring(0);
	ImGui::TextUnformatted(node.Name.c_str());
	ImGui::Spring(1);
	ImGui::Dummy(ImVec2(0, 28));
	//@TODO: delegates?
	// if (hasOutputDelegates)
	// {
	//     ImGui::BeginVertical("delegates", ImVec2(0, 28));
	//     ImGui::Spring(1, 0);
	//     for (auto& output : node.Outputs)
	//     {
	//         if (output.Type != PinType::Delegate)
	//             continue;

	//         auto alpha = ImGui::GetStyle().Alpha;
	//         if (newLinkPin && !CanCreateLink(newLinkPin, &output) && &output != newLinkPin)
	//             alpha = alpha * (48.0f / 255.0f);

	//         BeginPin(output.ID, PinDirection::OUTPUT);
	//         PinPivotAlignment(ImVec2(1.0f, 0.5f));
	//         PinPivotSize(ImVec2(0, 0));
	//         ImGui::BeginHorizontal(output.ID.AsPointer());
	//         ImGui::PushStyleVar(ImGuiStyleVar_Alpha, alpha);
	//         if (!output.Name.empty())
	//         {
	//             ImGui::TextUnformatted(output.Name.c_str());
	//             ImGui::Spring(0);
	//         }
	//         DrawPinIcon(output, IsPinLinked(output.ID), (int)(alpha * 255));
	//         ImGui::Spring(0, ImGui::GetStyle().ItemSpacing.x / 2);
	//         ImGui::EndHorizontal();
	//         ImGui::PopStyleVar();
	//         EndPin();

	//         //DrawItemRect(ImColor(255, 0, 0));
	//     }
	//     ImGui::Spring(1, 0);
	//     ImGui::EndVertical();
	//     ImGui::Spring(0, ImGui::GetStyle().ItemSpacing.x / 2);
	// }
	// else
	ImGui::Spring(0);
	builder.EndHeader();
      }

      for (auto& input : node.Inputs) {
	auto alpha = ImGui::GetStyle().Alpha;
	if (newLinkPin && !CanCreateLink(newLinkPin, &input) && &input != newLinkPin)
	  alpha = alpha * (48.0f / 255.0f);

	builder.BeginInputPad(input.ID);
	ImGui::PushStyleVar(ImGuiStyleVar_Alpha, alpha);
	DrawPinIcon(&input, IsPinLinked(input.ID), (int)(alpha * 255));
	ImGui::Spring(0);
	if (!input.Name.empty()) {
	  ImGui::TextUnformatted(input.Name.c_str());
	  ImGui::Spring(0);
	}
	if (input.Type == PinType::BOOLEAN) {
	  ImGui::Button("Hello");
	  ImGui::Spring(0);
	}
	ImGui::PopStyleVar();
	builder.EndPad();
      }
      
      
      if (isSimple) {
	builder.Middle();

	ImGui::Spring(1, 0);
	ImGui::TextUnformatted(node.Name.c_str());
	ImGui::Spring(1, 0);
      }

      for (auto& output : node.Outputs) {
	if (!isSimple && output.Type == PinType::DELEGATE)
	  continue;

	auto alpha = ImGui::GetStyle().Alpha;
	if (newLinkPin && !CanCreateLink(newLinkPin, &output) && &output != newLinkPin)
	  alpha = alpha * (48.0f / 255.0f);

	ImGui::PushStyleVar(ImGuiStyleVar_Alpha, alpha);
	builder.BeginOutputPad(output.ID);
	if (output.Type == PinType::STRING)
	{
	  static char buffer[128] = "Edit Me\nMultiline!";
	  static bool wasActive = false;

	  ImGui::PushItemWidth(100.0f);
	  ImGui::InputText("##edit", buffer, 127);
	  ImGui::PopItemWidth();
	  if (ImGui::IsItemActive() && !wasActive)
	  {
	    editor->EnableShortcuts(false);
	    wasActive = true;
	  }
	  else if (!ImGui::IsItemActive() && wasActive)
	  {
	    editor->EnableShortcuts(true);
	    wasActive = false;
	  }
	  ImGui::Spring(0);
	}
	if (!output.Name.empty())
	{
	  ImGui::Spring(0);
	  ImGui::TextUnformatted(output.Name.c_str());
	}
	ImGui::Spring(0);
	DrawPinIcon(&output, IsPinLinked(output.ID), (int)(alpha * 255));
	ImGui::PopStyleVar();
	builder.EndPad();
      }
      auto drawList = ImGui::GetWindowDrawList();

      builder.End();
    }

    // create tree thing?
    // for (auto& node : s_Nodes) {
    //     if (node.Type != NodeStyle::Tree)
    //         continue;

    //     const float rounding = 5.0f;
    //     const float padding  = 12.0f;

    //     const auto pinBackground = GetStyle().Colors[StyleColor_NodeBg];

    //     PushStyleColor(StyleColor_NodeBg,        ImColor(128, 128, 128, 200));
    //     PushStyleColor(StyleColor_NodeBorder,    ImColor( 32,  32,  32, 200));
    //     // PushStyleColor(StyleColor_PinRect,       ImColor( 60, 180, 255, 150);
    //     PushStyleColor(StyleColor_PinRect,       ImColor( 255, 0, 0, 150));
    //     PushStyleColor(StyleColor_PinRectBorder, ImColor( 60, 180, 255, 150));

    //     PushStyleVar(StyleVar_NodePadding,  ImVec4(0, 0, 0, 0));
    //     PushStyleVar(StyleVar_NodeRounding, rounding);
    //     PushStyleVar(StyleVar_SourceDirection, ImVec2(0.0f,  1.0f));
    //     PushStyleVar(StyleVar_TargetDirection, ImVec2(0.0f, -1.0f));
    //     PushStyleVar(StyleVar_LinkStrength, 0.0f);
    //     PushStyleVar(StyleVar_PinBorderWidth, 1.0f);
    //     PushStyleVar(StyleVar_PinRadius, 5.0f);
    //     BeginNode(node.ID);

    //     ImGui::BeginVertical(node.ID.AsPointer());
    //     ImGui::BeginHorizontal("inputs");
    //     ImGui::Spring(0, padding * 2);

    //     ImRect inputsRect;
    //     int inputAlpha = 200;
    //     if (!node.Inputs.empty())
    //     {
    //             auto& pin = node.Inputs[0];
    //             ImGui::Dummy(ImVec2(0, padding));
    //             ImGui::Spring(1, 0);
    //             inputsRect = ImGui_GetItemRect();

    //             PushStyleVar(StyleVar_PinArrowSize, 10.0f);
    //             PushStyleVar(StyleVar_PinArrowWidth, 10.0f);
    //             PushStyleVar(StyleVar_PinCorners, 12);
    //             BeginPin(pin.ID, PinDirection::INPUT);
    //             PinPivotRect(inputsRect.GetTL(), inputsRect.GetBR());
    //             PinRect(inputsRect.GetTL(), inputsRect.GetBR());
    //             EndPin();
    //             PopStyleVar(3);

    //             if (newLinkPin && !CanCreateLink(newLinkPin, &pin) && &pin != newLinkPin)
    //                 inputAlpha = (int)(255 * ImGui::GetStyle().Alpha * (48.0f / 255.0f));
    //     }
    //     else
    //         ImGui::Dummy(ImVec2(0, padding));

    //     ImGui::Spring(0, padding * 2);
    //     ImGui::EndHorizontal();

    //     ImGui::BeginHorizontal("content_frame");
    //     ImGui::Spring(1, padding);

    //     ImGui::BeginVertical("content", ImVec2(0.0f, 0.0f));
    //     ImGui::Dummy(ImVec2(160, 0));
    //     ImGui::Spring(1);
    //     ImGui::TextUnformatted(node.Name.c_str());
    //     ImGui::Spring(1);
    //     ImGui::EndVertical();
    //     auto contentRect = ImGui_GetItemRect();

    //     ImGui::Spring(1, padding);
    //     ImGui::EndHorizontal();

    //     ImGui::BeginHorizontal("outputs");
    //     ImGui::Spring(0, padding * 2);

    //     ImRect outputsRect;
    //     int outputAlpha = 200;
    //     if (!node.Outputs.empty())
    //     {
    //         auto& pin = node.Outputs[0];
    //         ImGui::Dummy(ImVec2(0, padding));
    //         ImGui::Spring(1, 0);
    //         outputsRect = ImGui_GetItemRect();

    //         PushStyleVar(StyleVar_PinCorners, 3);
    //         BeginPin(pin.ID, PinDirection::OUTPUT);
    //         PinPivotRect(outputsRect.GetTL(), outputsRect.GetBR());
    //         PinRect(outputsRect.GetTL(), outputsRect.GetBR());
    //         EndPin();
    //         PopStyleVar();

    //         if (newLinkPin && !CanCreateLink(newLinkPin, &pin) && &pin != newLinkPin)
    //             outputAlpha = (int)(255 * ImGui::GetStyle().Alpha * (48.0f / 255.0f));
    //     }
    //     else
    //         ImGui::Dummy(ImVec2(0, padding));

    //     ImGui::Spring(0, padding * 2);
    //     ImGui::EndHorizontal();

    //     ImGui::EndVertical();

    //     EndNode();
    //     PopStyleVar(7);
    //     PopStyleColor(4);

    //     auto drawList = GetNodeBackgroundDrawList(node.ID);

    //     //const auto fringeScale = ImGui::GetStyle().AntiAliasFringeScale;
    //     //const auto unitSize    = 1.0f / fringeScale;

    //     //const auto ImDrawList_AddRect = [](ImDrawList* drawList, const ImVec2& a, const ImVec2& b, ImU32 col, float rounding, int rounding_corners, float thickness)
    //     //{
    //     //    if ((col >> 24) == 0)
    //     //        return;
    //     //    drawList->PathRect(a, b, rounding, rounding_corners);
    //     //    drawList->PathStroke(col, true, thickness);
    //     //};

    //     drawList->AddRectFilled(inputsRect.GetTL() + ImVec2(0, 1), inputsRect.GetBR(),
    //         IM_COL32((int)(255 * pinBackground.x), (int)(255 * pinBackground.y), (int)(255 * pinBackground.z), inputAlpha), 4.0f, 12);
    //     //ImGui::PushStyleVar(ImGuiStyleVar_AntiAliasFringeScale, 1.0f);
    //     drawList->AddRect(inputsRect.GetTL() + ImVec2(0, 1), inputsRect.GetBR(),
    //         IM_COL32((int)(255 * pinBackground.x), (int)(255 * pinBackground.y), (int)(255 * pinBackground.z), inputAlpha), 4.0f, 12);
    //     //ImGui::PopStyleVar();
    //     drawList->AddRectFilled(outputsRect.GetTL(), outputsRect.GetBR() - ImVec2(0, 1),
    //         IM_COL32((int)(255 * pinBackground.x), (int)(255 * pinBackground.y), (int)(255 * pinBackground.z), outputAlpha), 4.0f, 3);
    //     //ImGui::PushStyleVar(ImGuiStyleVar_AntiAliasFringeScale, 1.0f);
    //     drawList->AddRect(outputsRect.GetTL(), outputsRect.GetBR() - ImVec2(0, 1),
    //         IM_COL32((int)(255 * pinBackground.x), (int)(255 * pinBackground.y), (int)(255 * pinBackground.z), outputAlpha), 4.0f, 3);
    //     //ImGui::PopStyleVar();
    //     drawList->AddRectFilled(contentRect.GetTL(), contentRect.GetBR(), IM_COL32(24, 64, 128, 200), 0.0f);
    //     //ImGui::PushStyleVar(ImGuiStyleVar_AntiAliasFringeScale, 1.0f);
    //     drawList->AddRect(
    //         contentRect.GetTL(),
    //         contentRect.GetBR(),
    //         IM_COL32(48, 128, 255, 100), 0.0f);
    //     //ImGui::PopStyleVar();
    // }

    // This draws the weird white box tree nodes
    // for (auto& node : s_Nodes) {
    //   if (node.Type != NodeStyle::Houdini) {
    //     continue;
    //   }

          
    //     const float rounding = 10.0f;
    //     const float padding  = 12.0f;


    //     PushStyleColor(StyleColor_NodeBg,        ImColor(229, 229, 229, 200));
    //     PushStyleColor(StyleColor_NodeBorder,    ImColor(125, 125, 125, 200));
    //     // PushStyleColor(StyleColor_PinRect,       ImColor(229, 229, 229, 60));
    //     PushStyleColor(StyleColor_PinRect,       ImColor(229, 0, 0, 60));
    //     PushStyleColor(StyleColor_PinRectBorder, ImColor(125, 125, 125, 60));

    //     const auto pinBackground = GetStyle().Colors[StyleColor_NodeBg];

    //     PushStyleVar(StyleVar_NodePadding,  ImVec4(0, 0, 0, 0));
    //     PushStyleVar(StyleVar_NodeRounding, rounding);
    //     PushStyleVar(StyleVar_SourceDirection, ImVec2(0.0f,  1.0f));
    //     PushStyleVar(StyleVar_TargetDirection, ImVec2(0.0f, -1.0f));
    //     PushStyleVar(StyleVar_LinkStrength, 0.0f);
    //     PushStyleVar(StyleVar_PinBorderWidth, 1.0f);
    //     PushStyleVar(StyleVar_PinRadius, 6.0f);
    //     BeginNode(node.ID);

    //     ImGui::BeginVertical(node.ID.AsPointer());
    //     if (!node.Inputs.empty())
    //     {
    //         ImGui::BeginHorizontal("inputs");
    //         ImGui::Spring(1, 0);

    //         ImRect inputsRect;
    //         int inputAlpha = 200;
    //         for (auto& pin : node.Inputs)
    //         {
    //             ImGui::Dummy(ImVec2(padding, padding));
    //             inputsRect = ImGui_GetItemRect();
    //             ImGui::Spring(1, 0);
    //             inputsRect.Min.y -= padding;
    //             inputsRect.Max.y -= padding;

    //             //PushStyleVar(StyleVar_PinArrowSize, 10.0f);
    //             //PushStyleVar(StyleVar_PinArrowWidth, 10.0f);
    //             PushStyleVar(StyleVar_PinCorners, 15);
    //             BeginPin(pin.ID, PinDirection::INPUT);
    //             PinPivotRect(inputsRect.GetCenter(), inputsRect.GetCenter());
    //             PinRect(inputsRect.GetTL(), inputsRect.GetBR());
    //             EndPin();
    //             //PopStyleVar(3);
    //             PopStyleVar(1);

    //             auto drawList = ImGui::GetWindowDrawList();
    //             drawList->AddRectFilled(inputsRect.GetTL(), inputsRect.GetBR(),
    //                 IM_COL32((int)(255 * pinBackground.x), (int)(255 * pinBackground.y), (int)(255 * pinBackground.z), inputAlpha), 4.0f, 15);
    //             drawList->AddRect(inputsRect.GetTL(), inputsRect.GetBR(),
    //                 IM_COL32((int)(255 * pinBackground.x), (int)(255 * pinBackground.y), (int)(255 * pinBackground.z), inputAlpha), 4.0f, 15);

    //             if (newLinkPin && !CanCreateLink(newLinkPin, &pin) && &pin != newLinkPin)
    //                 inputAlpha = (int)(255 * ImGui::GetStyle().Alpha * (48.0f / 255.0f));
    //         }

    //         //ImGui::Spring(1, 0);
    //         ImGui::EndHorizontal();
    //     }

    //     ImGui::BeginHorizontal("content_frame");
    //     ImGui::Spring(1, padding);

    //     ImGui::BeginVertical("content", ImVec2(0.0f, 0.0f));
    //     ImGui::Dummy(ImVec2(160, 0));
    //     ImGui::Spring(1);
    //     ImGui::PushStyleColor(ImGuiCol_Text, ImVec4(0.0f, 0.0f, 0.0f, 1.0f));
    //     ImGui::TextUnformatted(node.Name.c_str());
    //     ImGui::PopStyleColor();
    //     ImGui::Spring(1);
    //     ImGui::EndVertical();
    //     auto contentRect = ImGui_GetItemRect();

    //     ImGui::Spring(1, padding);
    //     ImGui::EndHorizontal();

    //     if (!node.Outputs.empty())
    //     {
    //         ImGui::BeginHorizontal("outputs");
    //         ImGui::Spring(1, 0);

    //         ImRect outputsRect;
    //         int outputAlpha = 200;
    //         for (auto& pin : node.Outputs)
    //         {
    //             ImGui::Dummy(ImVec2(padding, padding));
    //             outputsRect = ImGui_GetItemRect();
    //             ImGui::Spring(1, 0);
    //             outputsRect.Min.y += padding;
    //             outputsRect.Max.y += padding;

    //             PushStyleVar(StyleVar_PinCorners, 3);
    //             BeginPin(pin.ID, PinDirection::OUTPUT);
    //             PinPivotRect(outputsRect.GetCenter(), outputsRect.GetCenter());
    //             PinRect(outputsRect.GetTL(), outputsRect.GetBR());
    //             EndPin();
    //             PopStyleVar();

    //             auto drawList = ImGui::GetWindowDrawList();
    //             drawList->AddRectFilled(outputsRect.GetTL(), outputsRect.GetBR(),
    //                 IM_COL32((int)(255 * pinBackground.x), (int)(255 * pinBackground.y), (int)(255 * pinBackground.z), outputAlpha), 4.0f, 15);
    //             drawList->AddRect(outputsRect.GetTL(), outputsRect.GetBR(),
    //                 IM_COL32((int)(255 * pinBackground.x), (int)(255 * pinBackground.y), (int)(255 * pinBackground.z), outputAlpha), 4.0f, 15);


    //             if (newLinkPin && !CanCreateLink(newLinkPin, &pin) && &pin != newLinkPin)
    //                 outputAlpha = (int)(255 * ImGui::GetStyle().Alpha * (48.0f / 255.0f));
    //         }

    //         ImGui::EndHorizontal();
    //     }

    //     ImGui::EndVertical();

    //     EndNode();
    //     PopStyleVar(7);
    //     PopStyleColor(4);

    //     auto drawList = GetNodeBackgroundDrawList(node.ID);

    //     //const auto fringeScale = ImGui::GetStyle().AntiAliasFringeScale;
    //     //const auto unitSize    = 1.0f / fringeScale;

    //     //const auto ImDrawList_AddRect = [](ImDrawList* drawList, const ImVec2& a, const ImVec2& b, ImU32 col, float rounding, int rounding_corners, float thickness)
    //     //{
    //     //    if ((col >> 24) == 0)
    //     //        return;
    //     //    drawList->PathRect(a, b, rounding, rounding_corners);
    //     //    drawList->PathStroke(col, true, thickness);
    //     //};

    //     //drawList->AddRectFilled(inputsRect.GetTL() + ImVec2(0, 1), inputsRect.GetBR(),
    //     //    IM_COL32((int)(255 * pinBackground.x), (int)(255 * pinBackground.y), (int)(255 * pinBackground.z), inputAlpha), 4.0f, 12);
    //     //ImGui::PushStyleVar(ImGuiStyleVar_AntiAliasFringeScale, 1.0f);
    //     //drawList->AddRect(inputsRect.GetTL() + ImVec2(0, 1), inputsRect.GetBR(),
    //     //    IM_COL32((int)(255 * pinBackground.x), (int)(255 * pinBackground.y), (int)(255 * pinBackground.z), inputAlpha), 4.0f, 12);
    //     //ImGui::PopStyleVar();
    //     //drawList->AddRectFilled(outputsRect.GetTL(), outputsRect.GetBR() - ImVec2(0, 1),
    //     //    IM_COL32((int)(255 * pinBackground.x), (int)(255 * pinBackground.y), (int)(255 * pinBackground.z), outputAlpha), 4.0f, 3);
    //     ////ImGui::PushStyleVar(ImGuiStyleVar_AntiAliasFringeScale, 1.0f);
    //     //drawList->AddRect(outputsRect.GetTL(), outputsRect.GetBR() - ImVec2(0, 1),
    //     //    IM_COL32((int)(255 * pinBackground.x), (int)(255 * pinBackground.y), (int)(255 * pinBackground.z), outputAlpha), 4.0f, 3);
    //     ////ImGui::PopStyleVar();
    //     //drawList->AddRectFilled(contentRect.GetTL(), contentRect.GetBR(), IM_COL32(24, 64, 128, 200), 0.0f);
    //     //ImGui::PushStyleVar(ImGuiStyleVar_AntiAliasFringeScale, 1.0f);
    //     //drawList->AddRect(
    //     //    contentRect.GetTL(),
    //     //    contentRect.GetBR(),
    //     //    IM_COL32(48, 128, 255, 100), 0.0f);
    //     //ImGui::PopStyleVar();
    // }

    // Draws the comments
    // for (auto& node : s_Nodes) {
    //     if (node.Type != NodeStyle::Comment)
    //         continue;

    //     const float commentAlpha = 0.75f;

    //     ImGui::PushStyleVar(ImGuiStyleVar_Alpha, commentAlpha);
    //     PushStyleColor(StyleColor_NodeBg, ImColor(255, 255, 255, 64));
    //     PushStyleColor(StyleColor_NodeBorder, ImColor(255, 255, 255, 64));
    //     BeginNode(node.ID);
    //     ImGui::PushID(node.ID.AsPointer());
    //     ImGui::BeginVertical("content");
    //     ImGui::BeginHorizontal("horizontal");
    //     ImGui::Spring(1);
    //     ImGui::TextUnformatted(node.Name.c_str());
    //     ImGui::Spring(1);
    //     ImGui::EndHorizontal();
    //     Group(node.Size);
    //     ImGui::EndVertical();
    //     ImGui::PopID();
    //     EndNode();
    //     PopStyleColor(2);
    //     ImGui::PopStyleVar();

    //     if (BeginGroupHint(node.ID))
    //     {
    //         //auto alpha   = static_cast<int>(commentAlpha * ImGui::GetStyle().Alpha * 255);
    //         auto bgAlpha = static_cast<int>(ImGui::GetStyle().Alpha * 255);

    //         //ImGui::PushStyleVar(ImGuiStyleVar_Alpha, commentAlpha * ImGui::GetStyle().Alpha);

    //         auto min = GetGroupMin();
    //         //auto max = GetGroupMax();

    //         ImGui::SetCursorScreenPos(min - ImVec2(-8, ImGui::GetTextLineHeightWithSpacing() + 4));
    //         ImGui::BeginGroup();
    //         ImGui::TextUnformatted(node.Name.c_str());
    //         ImGui::EndGroup();

    //         auto drawList = GetHintBackgroundDrawList();

    //         auto hintBounds      = ImGui_GetItemRect();
    //         auto hintFrameBounds = ImRect_Expanded(hintBounds, 8, 4);

    //         drawList->AddRectFilled(
    //             hintFrameBounds.GetTL(),
    //             hintFrameBounds.GetBR(),
    //             IM_COL32(255, 255, 255, 64 * bgAlpha / 255), 4.0f);

    //         drawList->AddRect(
    //             hintFrameBounds.GetTL(),
    //             hintFrameBounds.GetBR(),
    //             IM_COL32(255, 255, 255, 128 * bgAlpha / 255), 4.0f);

    //         //ImGui::PopStyleVar();
    //     }
    //     EndGroupHint();
    // }

    // draw links
    for (auto& link : s_Links)
      editor->LLink(link.ID, link.StartPinID, link.EndPinID, link.Color, 2.0f);


    if (!createNewNode) {
      if (editor->BeginCreate(ImColor(255, 255, 255), 2.0f))
      {
	auto showLabel = [](const char* label, ImColor color)
	{
	  ImGui::SetCursorPosY(ImGui::GetCursorPosY() - ImGui::GetTextLineHeight());
	  auto size = ImGui::CalcTextSize(label);

	  auto padding = ImGui::GetStyle().FramePadding;
	  auto spacing = ImGui::GetStyle().ItemSpacing;

	  ImGui::SetCursorPos(ImGui::GetCursorPos() + ImVec2(spacing.x, -spacing.y));

	  auto rectMin = ImGui::GetCursorScreenPos() - padding;
	  auto rectMax = ImGui::GetCursorScreenPos() + size + padding;

	  auto drawList = ImGui::GetWindowDrawList();
	  drawList->AddRectFilled(rectMin, rectMax, color, size.y * 0.15f);
	  ImGui::TextUnformatted(label);
	};

	PinId startPinId = 0, endPinId = 0;
	if (editor->QueryNewLink(&startPinId, &endPinId)) {
	  auto startPin = FindPin(startPinId);
	  auto endPin   = FindPin(endPinId);

	  newLinkPin = startPin ? startPin : endPin;
	  if (startPin->Kind == PinDirection::INPUT)
	  {
	    std::swap(startPin, endPin);
	    std::swap(startPinId, endPinId);
	  }
	  if (startPin && endPin) {
	    if (endPin == startPin)
	    {
	      editor->RejectNewItem(ImColor(255, 0, 0), 2.0f);
	    }            
	    else if (endPin->Kind == startPin->Kind)
	    {
	      showLabel("x Incompatible Pin Kind", ImColor(45, 32, 32, 180));
	      editor->RejectNewItem(ImColor(255, 0, 0), 2.0f);
	    }
            
	    //else if (endPin->Node == startPin->Node)
	    //{
	    //    showLabel("x Cannot connect to self", ImColor(45, 32, 32, 180));
	    //    RejectNewItem(ImColor(255, 0, 0), 1.0f);
	    //}
	    else if (endPin->Type != startPin->Type)
	    {	     
	      showLabel("x Incompatible Pin Type", ImColor(45, 32, 32, 180));
	      editor->RejectNewItem(ImColor(255, 128, 128), 1.0f);
	    }
	    else
	    {
	      showLabel("+ Create Link", ImColor(32, 45, 32, 180));
	      if (editor->AcceptNewItem(ImColor(128, 255, 128), 4.0f)) {
		create_link(startPinId, endPinId);
		s_Links.back().Color = GetIconColor(startPin->Type);
	      }
	    }
	  }
	}

	PinId pinId = 0;
	if (editor->QueryNewNode(&pinId))
	{
	  newLinkPin = FindPin(pinId);
	  if (newLinkPin)
	    showLabel("+ Create Node", ImColor(32, 45, 32, 180));

	  if (editor->AcceptNewItem())
	  {
	    createNewNode  = true;
	    newNodeLinkPin = FindPin(pinId);
	    newLinkPin = nullptr;
	    editor->Suspend();
	    ImGui::OpenPopup("Create New Node");
	    editor->Resume();
	  }
	}
      }
      else
	newLinkPin = nullptr;

      editor->EndCreate();


      // Tell Editor which links can be deleted
      if (editor->BeginDelete()) {
	LinkId linkId = 0;
	while (editor->QueryDeletedLink(&linkId)){
	  if (editor->AcceptDeletedItem()) {
	    auto id = std::find_if(s_Links.begin(), s_Links.end(), [linkId](auto& link) { return link.ID == linkId; });
	    if (id != s_Links.end()) {
	      delete_link(linkId);
	      s_Links.erase(id);
              
	    }
	  }
	}

	NodeId nodeId = 0;
	while (editor->QueryDeletedNode(&nodeId))
	{
	  if (editor->AcceptDeletedItem())
	  {
	    auto id = std::find_if(s_Nodes.begin(), s_Nodes.end(), [nodeId](auto& node) { return node.ID == nodeId; });
	    if (id != s_Nodes.end())
	      s_Nodes.erase(id);
	  }
	}
      }
      editor->EndDelete();
    }

    ImGui::SetCursorScreenPos(cursorTopLeft);
  }

# if 1
  auto openPopupPosition = ImGui::GetMousePos();
  editor->Suspend();
  if (editor->ShowNodeContextMenu(&contextNodeId))
    ImGui::OpenPopup("Node Context Menu");
  else if (editor->ShowPinContextMenu(&contextPinId))
    ImGui::OpenPopup("Pin Context Menu");
  else if (editor->ShowLinkContextMenu(&contextLinkId))
    ImGui::OpenPopup("Link Context Menu");
  else if (editor->ShowBackgroundContextMenu())
  {
    ImGui::OpenPopup("Create New Node");
    newNodeLinkPin = nullptr;
  }
  editor->Resume();

  editor->Suspend();
  ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, ImVec2(8, 8));
  if (ImGui::BeginPopup("Node Context Menu"))
  {
    auto node = FindNode(contextNodeId);

    ImGui::TextUnformatted("Node Context Menu");
    ImGui::Separator();
    if (node)
    {
      ImGui::Text("ID: %p", node->ID.AsPointer());
      ImGui::Text("Type: %s", node->Type == NodeStyle::Blueprint ? "Blueprint" : (node->Type == NodeStyle::Tree ? "Tree" : "Comment"));
      ImGui::Text("Inputs: %d", (int)node->Inputs.size());
      ImGui::Text("Outputs: %d", (int)node->Outputs.size());
    }
    else
      ImGui::Text("Unknown node: %p", contextNodeId.AsPointer());
    ImGui::Separator();
    if (ImGui::MenuItem("Delete"))
      editor->DeleteNode(contextNodeId);
    ImGui::EndPopup();
  }

  if (ImGui::BeginPopup("Pin Context Menu"))
  {
    auto pin = FindPin(contextPinId);

    ImGui::TextUnformatted("Pin Context Menu");
    ImGui::Separator();
    if (pin)
    {
      ImGui::Text("ID: %p", pin->ID.AsPointer());
      if (pin->Node)
	ImGui::Text("Node: %p", pin->Node->ID.AsPointer());
      else
	ImGui::Text("Node: %s", "<none>");
    }
    else
      ImGui::Text("Unknown pin: %p", contextPinId.AsPointer());

    ImGui::EndPopup();
  }

  if (ImGui::BeginPopup("Link Context Menu")) {
    auto link = FindLink(contextLinkId);

    ImGui::TextUnformatted("Link Context Menu");
    ImGui::Separator();
    if (link) {
      ImGui::Text("ID: %p", link->ID.AsPointer());
      ImGui::Text("From: %p", link->StartPinID.AsPointer());
      ImGui::Text("To: %p", link->EndPinID.AsPointer());
    }
    else
      ImGui::Text("Unknown link: %p", contextLinkId.AsPointer());
    ImGui::Separator();
    if (ImGui::MenuItem("Delete"))
      editor->DeleteLink(contextLinkId);
    ImGui::EndPopup();
  }

  if (ImGui::BeginPopup("Create New Node")) {
    auto newNodePostion = openPopupPosition;
    //ImGui::SetCursorScreenPos(ImGui::GetMousePosOnOpeningCurrentPopup());

    //auto drawList = ImGui::GetWindowDrawList();
    //drawList->AddCircleFilled(ImGui::GetMousePosOnOpeningCurrentPopup(), 10.0f, 0xFFFF00FF);

    Node* node = nullptr;
    // if (ImGui::BeginMenu("render")) {
    //   if (ImGui::MenuItem("gegl:rectangle"))
    // 	node = create_node__gegl_alien_map();
    //   ImGui::EndMenu();
    // }

    node = show_all_category_menus();
    Node *ret = nullptr;


    if (node) {
      BuildNodes();

      createNewNode = false;

      editor->SetNodePosition(node->ID, newNodePostion);

      if (auto startPin = newNodeLinkPin) {
	auto& pins = (startPin->Kind == PinDirection::INPUT) ? node->Outputs :
	  node->Inputs;

	for (auto& pin : pins) {
	  if (CanCreateLink(startPin, &pin)) {
	    auto endPin = &pin;
	    if (startPin->Kind == PinDirection::INPUT)
	      std::swap(startPin, endPin); //@Todo what does this even do? as in why?

	    create_link(startPin->ID, endPin->ID);
	    s_Links.back().Color = GetIconColor(startPin->Type);

	    break;
	  }
	}
      }
    }

    ImGui::EndPopup();
  }
  else
    createNewNode = false;
  ImGui::PopStyleVar();
  editor->Resume();
# endif

/*
  cubic_bezier_t c;
  c.p0 = pointf(100, 600);
  c.p1 = pointf(300, 1200);
  c.p2 = pointf(500, 100);
  c.p3 = pointf(900, 600);

  auto drawList = ImGui::GetWindowDrawList();
  auto offset_radius = 15.0f;
  auto acceptPoint = [drawList, offset_radius](const bezier_subdivide_result_t& r)
  {
  drawList->AddCircle(to_imvec(r.point), 4.0f, IM_COL32(255, 0, 255, 255));

  auto nt = r.tangent.normalized();
  nt = pointf(-nt.y, nt.x);

  drawList->AddLine(to_imvec(r.point), to_imvec(r.point + nt * offset_radius), IM_COL32(255, 0, 0, 255), 1.0f);
  };

  drawList->AddBezierCurve(to_imvec(c.p0), to_imvec(c.p1), to_imvec(c.p2), to_imvec(c.p3), IM_COL32(255, 255, 255, 255), 1.0f);
  cubic_bezier_subdivide(acceptPoint, c);
*/

  editor->End();


  //ImGui::ShowTestWindow();
  //ImGui::ShowMetricsWindow();
}
