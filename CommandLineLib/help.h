#pragma once
#include "myCommand.h"
#include "myParsing.h"

class help : public myCommand
{
public:
	help();

	std::string getName() const;
	std::string getAlias() const;
	void assignment(std::vector<std::string> assign) const;	
	void launchCommand(myParsing parser) const;
};

