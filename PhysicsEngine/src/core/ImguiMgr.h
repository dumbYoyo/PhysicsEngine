#pragma once

#include <GLFW/glfw3.h>
#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_glfw.h>

void InitImgui(GLFWwindow* window);
void StartFrameImgui();
void EndFrameImgui();
void DestroyImgui();