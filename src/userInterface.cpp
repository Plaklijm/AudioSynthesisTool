//
// Created by michi on 06/03/2024.
//

#include "userInterface.h"

#include <imgui.h>

void userInterface::showMainMenuBar() {
    if (ImGui::BeginMainMenuBar())
    {
        if (ImGui::BeginMenu("File"))
        {
            if (ImGui::MenuItem("New")) {}
            if (ImGui::MenuItem("Open", "Ctrl+O")) {}
            if (ImGui::MenuItem("Save", "Ctrl+S")) {}

            // Maybe if this functionality is implementable
            //if (ImGui::MenuItem("Save As..")) {}

            ImGui::Separator();

            if (ImGui::MenuItem("Quit", "Alt+F4")) {}
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Edit"))
        {
            if (ImGui::MenuItem("Undo", "CTRL+Z")) {}
            if (ImGui::MenuItem("Redo", "CTRL+Y", false, false)) {}  // Disabled item
            ImGui::Separator();
            if (ImGui::MenuItem("Cut", "CTRL+X")) {}
            if (ImGui::MenuItem("Copy", "CTRL+C")) {}
            if (ImGui::MenuItem("Paste", "CTRL+V")) {}
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Library")) // <-- Append!
        {
            ImGui::BeginChild("child", ImVec2(100, 200), true);
            ImGui::EndChild();
            ImGui::EndMenu();
        }
        if (ImGui::BeginMenu("Settings")) // <-- Append!
        {
            static bool a = true, b = true;
            ImGui::Checkbox("SomeOption", &a);
            ImGui::Checkbox("SomeOption1", &b);
            ImGui::EndMenu();
        }
        ImGui::EndMainMenuBar();
    }
}

void userInterface::showPatch() {
    ImGui::Begin("Window");
    {
        ImGui::Text("Hello, Dear ImGUI!");
    }
    ImGui::End();
}
