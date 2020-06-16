#include <iostream>

#include "TurnOver.h"
#include "Window/Window.h"


// Will init the application
int TurnOver::InitInter()
{
	// Should add error handling but ehh
	if (Window::Init()) return -1;

	if (Window::CreateWindow()) return -1;

	// Temp for testing
	m_Equipment.emplace_back(
		std::string("A0001"),
		std::string("Uninstalled Engine, blah, blah, blah, blah, blah, blah, blah, blah, blah, blach, blah,, blah, blah, blah, blah, blah, blach, blah,, blah, blah, blah, blah, blah, blach, blah,"),
		std::string("KTLS, install, 7 level upon removal, long string. stuff to add, idk, pryometer, lube")
	);
	
	m_Equipment.emplace_back(
		std::string("E0006"),
		std::string("Removed oil pump"),
		std::string("KTLS, install, 7 level upon removal, long string. stuff to add, idk, pryometer, lube")
	);

	return 0;
}
int TurnOver::Init()
{
	return Get()->InitInter();
}

// Returns if the application should close
int TurnOver::ShouldCloseInter()
{
	return Window::ShouldClose();
}
int TurnOver::ShouldClose()
{
	return Get()->ShouldCloseInter();
}

void TurnOver::RunInter()
{
	Window::Run();
}
void TurnOver::Run()
{
	Get()->RunInter();
}

void TurnOver::SaveNewDataInter(const std::string& id, const std::string& done, const std::string& needed)
{
	std::cout << id << "\n\n" << done << "\n\n" << needed << std::endl;
}
void TurnOver::SaveNewData(const std::string& id, const std::string& done, const std::string& needed)
{
	Get()->SaveNewDataInter(id, done, needed);
}

// Gets a list of all equipment active
std::list<Equipment>& TurnOver::GetEquipmentInter()
{
	return m_Equipment;
}
std::list<Equipment>& TurnOver::GetEquipment()
{
	return Get()->GetEquipmentInter();
}

// Returns a pointer to the TurnOver Object
TurnOver* TurnOver::Get()
{
	// Creates a new Turnover Class on the heap as it will be a large object
	static TurnOver* turn = new TurnOver;

	return turn;
}

TurnOver::TurnOver() {}
TurnOver::~TurnOver()
{
	Window::Close();
}


