//------------------------------------------------------------------------------
// LICENSE
//   This software is dual-licensed to the public domain and under the following
//   license: you are granted a perpetual, irrevocable license to copy, modify,
//   publish, and distribute this file as you see fit.
//
// CREDITS
//   Written by Michal Cichon
//------------------------------------------------------------------------------
# include "builders.h"
# define IMGUI_DEFINE_MATH_OPERATORS
# include <imgui_internal.h>

using NodeEditor::PinDirection;
//------------------------------------------------------------------------------
namespace ed   = NodeEditor;
namespace util = NodeEditor::Utilities;

util::BlueprintNodeBuilder::BlueprintNodeBuilder(ImTextureID texture, int textureWidth, int textureHeight):
    HeaderTextureId(texture),
    HeaderTextureWidth(textureWidth),
    HeaderTextureHeight(textureHeight),
    CurrentNodeId(0),
    CurrentStage(Stage::Invalid)
{
}

void util::BlueprintNodeBuilder::Begin(ed::NodeId id) {
    HeaderMin = HeaderMax = ImVec2();

    // EditorContext *newref = ed::GetEditor();
    ed::GetEditor()->PushStyleVar(StyleVar_NodePadding, ImVec4(8, 4, 8, 8));
    ed::GetEditor()->BeginNode(id);

    ImGui::PushID(id.AsPointer());
    CurrentNodeId = id;

    SetStage(Stage::Begin);
}

void util::BlueprintNodeBuilder::End() {
  SetStage(Stage::End);

  ed::GetEditor()->EndNode();

  if (ImGui::IsItemVisible()) {
    auto alpha = static_cast<int>(255 * ImGui::GetStyle().Alpha);

    auto drawList = ed::GetEditor()->GetNodeBackgroundDrawList(CurrentNodeId);

    const auto halfBorderWidth = ed::GetEditor()->GetStyle().NodeBorderWidth * 0.5f;

    auto headerColor = IM_COL32(0, 0, 0, alpha) | (HeaderColor & IM_COL32(255, 255, 255, 0));
    if (// false && 
	(HeaderMax.x > HeaderMin.x) && (HeaderMax.y > HeaderMin.y) && HeaderTextureId) {
      const auto uv = ImVec2(
	(HeaderMax.x - HeaderMin.x) / (float)(4.0f * HeaderTextureWidth),
	(HeaderMax.y - HeaderMin.y) / (float)(4.0f * HeaderTextureHeight));

      // header background image
      drawList->AddImageRounded(HeaderTextureId,
				HeaderMin - ImVec2(8 - halfBorderWidth, 4 - halfBorderWidth),
				HeaderMax + ImVec2(8 - halfBorderWidth, 0),
				ImVec2(0.0f, 0.0f), uv,
				headerColor,
				ed::GetEditor()->GetStyle().NodeRounding,
				ImDrawCornerFlags_Top);

      auto headerSeparatorMin = ImVec2(HeaderMin.x, HeaderMax.y);
      auto headerSeparatorMax = ImVec2(HeaderMax.x, HeaderMin.y);

      if ((headerSeparatorMax.x > headerSeparatorMin.x) && (headerSeparatorMax.y > headerSeparatorMin.y)) {
	drawList->AddLine(
	  headerSeparatorMin + ImVec2(-(8 - halfBorderWidth), -0.5f),
	  headerSeparatorMax + ImVec2( (8 - halfBorderWidth), -0.5f),
	  ImColor(255, 255, 255, 96 * alpha / (3 * 255)), 1.0f);
      }
    }
  }
  CurrentNodeId = 0;

  ImGui::PopID();
  ed::GetEditor()->PopStyleVar();
  SetStage(Stage::Invalid);
}

void util::BlueprintNodeBuilder::Header(const ImVec4& color) {
  HeaderColor = ImColor(color);
  SetStage(Stage::Header);
}

void util::BlueprintNodeBuilder::EndHeader() {
    SetStage(Stage::Content);
}

void util::BlueprintNodeBuilder::BeginOutputPad(ed::PinId id) {
  SetStage(Stage::Output);
  // ImGui::Spring(0);

  ed::GetEditor()->BeginPin(id);

  ImGui::BeginVertical(id.AsPointer());
  // ImGui::Spring(0);
}

void util::BlueprintNodeBuilder::BeginInputPad(ed::PinId id) {
  // if (CurrentStage == Stage::Begin)
  //   SetStage(Stage::Content);
    
  // const auto applyPadding = (CurrentStage == Stage::Input);
  SetStage(Stage::Input);
  // if (applyPadding) {
  //   ImGui::Spring(0);
  // }

  ed::GetEditor()->BeginPin(id);

  ImGui::BeginVertical(id.AsPointer());
}

void util::BlueprintNodeBuilder::BeginPad(ed::PinId id) {
  SetStage(Stage::Pad);

  ed::GetEditor()->BeginPin(id);

  ImGui::BeginVertical(id.AsPointer());
}

void util::BlueprintNodeBuilder::Middle() {
  if (CurrentStage == Stage::Begin)
    SetStage(Stage::Content);

  SetStage(Stage::Middle);
}

void util::BlueprintNodeBuilder::EndPad() {  
  ImGui::EndVertical();
  ed::GetEditor()->EndPin();
}

void util::BlueprintNodeBuilder::SetStage(Stage stage) {
  if (stage == CurrentStage)
    return;

  auto oldStage = CurrentStage;
  CurrentStage = stage;

  ImVec2 cursor;
  switch (oldStage)
  {
  case Stage::Begin:
  case Stage::End:
  case Stage::Invalid:
  case Stage::Content:
    break;

  case Stage::Header:
    ImGui::EndHorizontal();
    HeaderMin = ImGui::GetItemRectMin();
    HeaderMax = ImGui::GetItemRectMax();

    // spacing between header and content
    ImGui::Spring(0, ImGui::GetStyle().ItemSpacing.y * 2.0f);
    break;
    
  case Stage::Output:
  case Stage::Input:
  case Stage::Pad:
    ed::GetEditor()->PopStyleVar(2);

    // ImGui::Spring(1, 0);
    ImGui::EndVertical();
    break;

  }
///
  switch (stage)
  {
  case Stage::Begin:
    ImGui::BeginVertical("node", ImVec2(0, 0), 0.0f);
    break;

  case Stage::Header:
    ImGui::BeginHorizontal("header");
    break;

  case Stage::Content:
    // if (oldStage == Stage::Begin)
    //   ImGui::Spring(0);
    ImGui::BeginHorizontal("content");
    // ImGui::Spring(0, 0);
    break;

  case Stage::Input:
    ImGui::BeginVertical("inputs", ImVec2(0, 0), 0.0f);

    ed::GetEditor()->PushStyleVar(ed::StyleVar_PivotAlignment, ImVec2(0, 0.5f));
    ed::GetEditor()->PushStyleVar(ed::StyleVar_PivotSize, ImVec2(0, 0));
    break;

  case Stage::Output:
    // ImGui::BeginVertical("outputs", ImVec2(0, 0), 0.0f);
    ImGui::BeginVertical("outputs", ImVec2(0, 0));

    ed::GetEditor()->PushStyleVar(ed::StyleVar_PivotAlignment, ImVec2(1.0f, 0.5f));
    ed::GetEditor()->PushStyleVar(ed::StyleVar_PivotSize, ImVec2(0, 0));
    break;   

  case Stage::End:
    if (oldStage == Stage::Input)
      ImGui::Spring(1, 0);
    if (oldStage != Stage::Begin) {
      ImGui::EndHorizontal(); //ends the content horizontal
    }
    // ContentMin = ImGui::GetItemRectMin();
    // ContentMax = ImGui::GetItemRectMax();

    ImGui::Spring(0);
    ImGui::EndVertical();
    // node div debug
    // ImGui::GetWindowDrawList()->AddRect(ImGui::GetItemRectMin(),
    // 					ImGui::GetItemRectMax(),
    // 					IM_COL32(255, 0, 255, 255));
    NodeMin = ImGui::GetItemRectMin();
    NodeMax = ImGui::GetItemRectMax();
    break;

  case Stage::Invalid:
    break;
  }

  return;
}
