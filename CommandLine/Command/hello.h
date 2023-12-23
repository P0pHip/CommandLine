#pragma once
#include "../../CommandLineLib/myCommand.h"

class hello : public myCommand
{
public:
	hello();

	void assignment(std::vector<std::string> assign);
	void addTargs(myTarget target);
	void launchCommand() const;
};

