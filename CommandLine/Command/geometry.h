#pragma once
#include "../../CommandLineLib/myCommand.h"
class geometry : public myCommand
{
public:
	geometry();

	void assignment(std::vector<std::string> assign);
	void addTargs(myTarget target);
	void launchCommand() const;
};

