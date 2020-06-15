#ifndef WINDOW_H
#define WINDOW_H

#include "GLFW/glfw3.h"

namespace Window
{
	int Init();
	int CreateWindow();
	int ShouldClose();
	void Run();
	void Close();

	GLFWwindow* GetWindow();
}

#endif /* WINDOW_H */
