#ifndef GUI_H
#define GUI_H

#include "GLFW/glfw3.h"

class GUI
{
private:
	static bool m_ShouldClose;
	GLFWwindow* m_Wnd = nullptr;

	void TopBar();
	void Equipments();
	void EquipmentAdjustment();

	void NewEquipment();
	void DeleteEquipment();

public:
	static bool ShouldClose();

	void Run();

	GUI(GLFWwindow* wnd);
	~GUI();
};

#endif /* GUI_H */