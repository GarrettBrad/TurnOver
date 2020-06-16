#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>

struct Equipment
{
	std::string id;
	std::string WorkDone;
	std::string WorkNeeded;

	// Should add move semantics
	Equipment(const std::string& i, const std::string& wd, const std::string& wn)
		: id(i), WorkDone(wd), WorkNeeded(wn)
	{

	}
};

#endif /* EQUIPMENT_H */
