#include "imgui/imgui.h"

#include <GLFW/glfw3.h>

#include "Application/TurnOver.h"

int main()
{
	TurnOver::Init();

	while (!TurnOver::ShouldClose())
		TurnOver::Run();

	delete TurnOver::Get();

	return 0;
}
