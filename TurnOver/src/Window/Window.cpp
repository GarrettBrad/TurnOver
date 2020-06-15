
#include <iostream>

#include "GLFW/glfw3.h"

#include "imgui/imgui.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl2.h"

#include "Window.h"

#include "Window/GUI/GUI.h"

static GUI* gui = nullptr;

namespace Window
{
	static GLFWwindow* wnd;
	

	GLFWwindow* GetWindow()
	{
		return wnd;
	}

	int Init()
	{
		if (!glfwInit()) return 1;
		

		return 0;
	}

	int CreateWindow()
	{
		wnd = glfwCreateWindow(600, 400, "Turn Over", nullptr, nullptr);

		if (!wnd) return -1;

		glfwMakeContextCurrent(wnd);

		glfwMaximizeWindow(wnd);

		gui = new GUI(wnd);

		return 0;
	}

	int ShouldClose()
	{
		return glfwWindowShouldClose(wnd) || gui->ShouldClose();
	}

	void Run()
	{
		glfwPollEvents();


		gui->Run();

		glfwMakeContextCurrent(wnd);
		glfwSwapBuffers(wnd);
	}

	void Close()
	{

		delete gui;

		glfwTerminate();
	}

}
