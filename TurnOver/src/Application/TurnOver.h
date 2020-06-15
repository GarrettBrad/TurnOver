#ifndef TURNOVER_H
#define TURNOVER_H

#include <list>
#include "Equipment.h"

// Singleton class for turnover
class TurnOver
{
private:

	std::list<Equipment> m_Equipment;

	int ShouldCloseInter();
	int InitInter();
	void RunInter();

	void SaveNewDataInter(const std::string& equiptmentID, const std::string& workDone, const std::string& workNeeded);
	
	std::list<Equipment>& GetEquipmentInter();

	// Make private for singleton
	TurnOver();
public:

	static int ShouldClose();
	static int Init();
	static void Run();

	static std::list<Equipment>& GetEquipment();

	static void SaveNewData(const std::string& equiptmentID, const std::string& workDone, const std::string& workNeeded);

	static TurnOver* Get();

	~TurnOver();
};

#endif /* TURNOVER_H */
