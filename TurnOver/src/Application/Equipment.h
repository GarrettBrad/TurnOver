#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>

struct Equipment
{
	std::string id;
	std::string WorkDone;
	std::string WorkNeeded;

	Equipment(std::string i, std::string wd, std::string wn)
		: id(i), WorkDone(wd), WorkNeeded(wn)
	{

	}
};

#endif /* EQUIPMENT_H */
