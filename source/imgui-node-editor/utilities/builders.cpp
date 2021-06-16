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
    CurrentStage(Stage::Invalid),
    HasHeader(false)
{
}

void util::BlueprintNodeBuilder::Begin(ed::NodeId id) {
    HasHeader  = false;
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
    if ((HeaderMax.x > HeaderMin.x) && (HeaderMax.y > HeaderMin.y) && HeaderTextureId) {
      const auto uv = ImVec2(
	(HeaderMax.x - HeaderMin.x) / (float)(4.0f * HeaderTextureWidth),
	(HeaderMax.y - HeaderMin.y) / (float)(4.0f * HeaderTextureHeight));

      drawList->AddImageRounded(HeaderTextureId,
				HeaderMin - ImVec2(8 - halfBorderWidth, 4 - halfBorderWidth),
				HeaderMax + ImVec2(8 - halfBorderWidth, 0),
				ImVec2(0.0f, 0.0f), uv,
				headerColor, ed::GetEditor()->GetStyle().NodeRounding, 1 | 2);

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

void util::BlueprintNodeBuilder::Header(const ImVec4& color)
{
    HeaderColor = ImColor(color);
    SetStage(Stage::Header);
}

void util::BlueprintNodeBuilder::EndHeader()
{
    SetStage(Stage::Content);
}

// void util::BlueprintNodeBuilder::Input(ed::PinId id) {
//   if (CurrentStage == Stage::Begin)
//     SetStage(Stage::Content);

//   const auto applyPadding = (CurrentStage == Stage::Input);

//   SetStage(Stage::Input);

//   if (applyPadding)
//     ImGui::Spring(0);

//   ed::BeginPin(id, PinDirection::INPUT);

//   ImGui::BeginHorizontal(id.AsPointer());
// }

void util::BlueprintNodeBuilder::BeginOutputPad(ed::PinId id) {
  if (CurrentStage == Stage::Begin)
    SetStage(Stage::Content);
    
  const auto applyPadding = (CurrentStage == Stage::Output);

  SetStage(Stage::Output);

  if (applyPadding)
    ImGui::Spring(0);

  ed::GetEditor()->BeginPin(id, PinDirection::OUTPUT);

  ImGui::BeginHorizontal(id.AsPointer());
}

void util::BlueprintNodeBuilder::BeginInputPad(ed::PinId id) {
  if (CurrentStage == Stage::Begin)
    SetStage(Stage::Content);
    
  const auto applyPadding = (CurrentStage == Stage::Input);

  SetStage(Stage::Input);

  if (applyPadding)
    ImGui::Spring(0);

  ed::GetEditor()->BeginPin(id, PinDirection::INPUT);

  ImGui::BeginHorizontal(id.AsPointer());
}

void util::BlueprintNodeBuilder::Middle()
{
  if (CurrentStage == Stage::Begin)
    SetStage(Stage::Content);

  SetStage(Stage::Middle);
}

void util::BlueprintNodeBuilder::EndPad() {
    ImGui::EndHorizontal();
    ed::GetEditor()->EndPin();
}

bool util::BlueprintNodeBuilder::SetStage(Stage stage)
{
    if (stage == CurrentStage)
        return false;

    auto oldStage = CurrentStage;
    CurrentStage = stage;

    ImVec2 cursor;
    switch (oldStage)
    {
        case Stage::Begin:
            break;

        case Stage::Header:
            ImGui::EndHorizontal();
            HeaderMin = ImGui::GetItemRectMin();
            HeaderMax = ImGui::GetItemRectMax();

            // spacing between header and content
            ImGui::Spring(0, ImGui::GetStyle().ItemSpacing.y * 2.0f);

            break;

        case Stage::Content:
            break;

        case Stage::Input:
	  ed::GetEditor()->PopStyleVar(2);

            ImGui::Spring(1, 0);
            ImGui::EndVertical();

            // #debug
            // ImGui::GetWindowDrawList()->AddRect(
            //     ImGui::GetItemRectMin(), ImGui::GetItemRectMax(), IM_COL32(255, 0, 0, 255));

            break;

        case Stage::Middle:
            ImGui::EndVertical();

            // #debug
            // ImGui::GetWindowDrawList()->AddRect(
            //     ImGui::GetItemRectMin(), ImGui::GetItemRectMax(), IM_COL32(255, 0, 0, 255));

            break;

        case Stage::Output:
	  ed::GetEditor()->PopStyleVar(2);

            ImGui::Spring(1, 0);
            ImGui::EndVertical();

            // #debug
            // ImGui::GetWindowDrawList()->AddRect(
            //     ImGui::GetItemRectMin(), ImGui::GetItemRectMax(), IM_COL32(255, 0, 0, 255));

            break;

        case Stage::End:
            break;

        case Stage::Invalid:
            break;
    }

    switch (stage)
    {
        case Stage::Begin:
            ImGui::BeginVertical("node");
            break;

        case Stage::Header:
            HasHeader = true;

            ImGui::BeginHorizontal("header");
            break;

        case Stage::Content:
            if (oldStage == Stage::Begin)
                ImGui::Spring(0);

            ImGui::BeginHorizontal("content");
            ImGui::Spring(0, 0);
            break;

        case Stage::Input:
            ImGui::BeginVertical("inputs", ImVec2(0, 0), 0.0f);

            ed::GetEditor()->PushStyleVar(ed::StyleVar_PivotAlignment, ImVec2(0, 0.5f));
            ed::GetEditor()->PushStyleVar(ed::StyleVar_PivotSize, ImVec2(0, 0));

            if (!HasHeader)
                ImGui::Spring(1, 0);
            break;

        case Stage::Middle:
            ImGui::Spring(1);
            ImGui::BeginVertical("middle", ImVec2(0, 0), 1.0f);
            break;

        case Stage::Output:
            if (oldStage == Stage::Middle || oldStage == Stage::Input)
                ImGui::Spring(1);
            else
                ImGui::Spring(1, 0);
            ImGui::BeginVertical("outputs", ImVec2(0, 0), 1.0f);

            ed::GetEditor()->PushStyleVar(ed::StyleVar_PivotAlignment, ImVec2(1.0f, 0.5f));
            ed::GetEditor()->PushStyleVar(ed::StyleVar_PivotSize, ImVec2(0, 0));

            if (!HasHeader)
                ImGui::Spring(1, 0);
            break;

        case Stage::End:
            if (oldStage == Stage::Input)
                ImGui::Spring(1, 0);
            if (oldStage != Stage::Begin)
                ImGui::EndHorizontal();
            ContentMin = ImGui::GetItemRectMin();
            ContentMax = ImGui::GetItemRectMax();

            //ImGui::Spring(0);
            ImGui::EndVertical();
            NodeMin = ImGui::GetItemRectMin();
            NodeMax = ImGui::GetItemRectMax();
            break;

        case Stage::Invalid:
            break;
    }

    return true;
}
