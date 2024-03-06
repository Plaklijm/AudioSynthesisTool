//
// Created by michi on 06/03/2024.
//

#include "application.h"

#include "userInterface.h"

#include <GLFW/glfw3.h>
#include <imgui.h>
#include <glad/glad.h>
#include <cstdio>

#include "../vendor/imgui_impl_glfw.h"
#include "../vendor/imgui_impl_opengl3.h"

#define GLSL_VERSION "#version 330"

application::application() {
    isApplicationRunning = 1;
}

void application::initApplication() {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(600, 600, "AudioSynthesisTool",
                                          nullptr, nullptr);
    if (window == nullptr) {
        printf("Could not create GLFW window");
        glfwTerminate();
        isApplicationRunning = -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        printf("Could not initialize GLAD");
        isApplicationRunning = -1;
    }

    ImGui::CreateContext();

    ImGuiIO& io = ImGui::GetIO(); (void)io;
    io.IniFilename = "imgui.ini";
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(GLSL_VERSION);
}

void application::runApplication() {
    isApplicationRunning = !glfwWindowShouldClose(window);
    glfwPollEvents();

    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    ImGui_ImplOpenGL3_NewFrame();
    ImGui_ImplGlfw_NewFrame();
    ImGui::NewFrame();

    userInterface::showMainMenuBar();

    userInterface::showPatch();

    ImGui::Render();
    ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

    glfwSwapBuffers(window);
}

void application::terminateApplication() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();
}
