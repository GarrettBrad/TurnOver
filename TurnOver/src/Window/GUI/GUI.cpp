#include <iostream>

#include <string>

#include "Application/TurnOver.h"

#include "GUI.h"

#include "imgui/imgui.h"
#include "imgui/imgui_stdlib.h"
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl2.h"

bool GUI::m_ShouldClose = false;

static bool show_new_equipment = false;
static bool show_delete_equipment = false;
static bool show_adjust_equip = false;
static bool show_equip_adjust_edit = false;

static std::string current_selected;

void GUI::TopBar()
{
	if (ImGui::BeginMainMenuBar())
	{
		if (ImGui::BeginMenu("File"))
		{
			// Returns true when New Equipment is called
			if (ImGui::MenuItem("New Equipment"))
			{
				show_new_equipment = true;
			}
			if (ImGui::MenuItem("Remove Equipment"))
			{
				show_delete_equipment = true;
			}

			if (ImGui::MenuItem("Exit"))
				m_ShouldClose = true;

			// End the menu
			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("View"))
		{

			ImGui::EndMenu();
		}
		if (ImGui::BeginMenu("Debug"))
		{
			ImGui::MenuItem("This if for development");

			ImGui::EndMenu();
		}
	}

	ImGui::EndMainMenuBar();
}

// Equipment panel
void GUI::Equipments()
{
	std::list<Equipment>& e = TurnOver::GetEquipment();

	ImGuiWindowFlags flags = 0;

	// Adds to a bit map to adjust flags
	 flags |= ImGuiWindowFlags_NoTitleBar;
	 flags |= ImGuiWindowFlags_NoMove;
	 flags |= ImGuiWindowFlags_NoResize;
	 
	 int width, height;
	 glfwGetWindowSize(m_Wnd, &width, &height);

	ImGui::SetNextWindowPos(ImVec2(0, 16), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(300, height), ImGuiCond_FirstUseEver);

	// ImGui::PushStyleVar()

	ImGui::Begin("Equipment", nullptr, flags);
	
	if (ImGui::CollapsingHeader("Equipment ID:"))
	{

		for (std::list<Equipment>::iterator i = e.begin(); i != e.end(); i++)
		{
			if (ImGui::Button(i->id.c_str()))
			{
				current_selected = i->id;
				show_adjust_equip = true;
			}
		}
	}

	ImGui::End();
}

static std::string workDoneInput = "";
static std::string workDoneInputWho = "";
static std::string workNeededInput = "";
static std::string workNeededInputWho = "";
void GUI::EquipmentAdjustment()
{
	std::list<Equipment>& e = TurnOver::GetEquipment();
	std::list<Equipment>::iterator it;

	for (it = e.begin(); it != e.end(); it++)
	{
		if (it->id == current_selected)
			break;
	}

	if (current_selected == "" || it == e.end()) return;

	int width, height;
	glfwGetWindowSize(m_Wnd, &width, &height);

	ImGui::SetNextWindowPos(ImVec2(300, 50), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(400, 500), ImGuiCond_FirstUseEver);

	ImGui::Begin(it->id.c_str());

	ImGui::Text("Work Done:");
	ImGui::TextWrapped(it->WorkDone.c_str());

	ImGui::NewLine();

	ImGui::Text("Work Needed:");
	ImGui::TextWrapped(it->WorkNeeded.c_str());

	if (ImGui::Button("Edit.")) {
		show_equip_adjust_edit = true;
	}

	if (ImGui::Button("Close.")) {
		show_adjust_equip = false;
	}

	ImGui::End();

	// Only show if we are editing
	if (!show_equip_adjust_edit) return;

	ImGui::SetNextWindowPos(ImVec2(400, 75), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(400, 500), ImGuiCond_FirstUseEver);

	ImGui::Begin("Turnover Adjustment");
	
	
	ImGui::Text("Work Done:");
	ImGui::InputTextMultiline("", &workDoneInput);

	ImGui::NewLine();
	ImGui::NewLine();

	ImGui::Text("Work Needed:");
	ImGui::InputTextMultiline("", &workNeededInput);

	ImGui::InputTextWithHint("", "Shift Lead", &workDoneInputWho);

	ImGui::End();
}

void GUI::NewEquipment()
{

}

void GUI::DeleteEquipment()
{

}

void GUI::Run()
{
	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

	TopBar();

	Equipments();

	if (show_adjust_equip)
		EquipmentAdjustment();

	if (show_new_equipment)
		NewEquipment();

	if (show_delete_equipment)
		DeleteEquipment();


	ImGui::Begin("Hello World");
	ImGui::Text("This is some text");
	ImGui::End();




	ImGui::Render();
	int display_w, display_h;
	glfwGetFramebufferSize(m_Wnd, &display_w, &display_h);
	glViewport(0, 0, display_w, display_h);
	glClearColor(0.5f, 0.5f, 0.5f, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT);

	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
}


bool GUI::ShouldClose()
{
	return m_ShouldClose;
}

GUI::GUI(GLFWwindow* wnd)
	: m_Wnd(wnd)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& IO = ImGui::GetIO(); (void)IO;

	ImGui::StyleColorsDark();

	ImGui_ImplGlfw_InitForOpenGL(m_Wnd, true);
	ImGui_ImplOpenGL2_Init();
}

GUI::~GUI()
{
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}
