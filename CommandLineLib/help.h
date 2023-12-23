#pragma once
#include "myCommand.h"
#include "myParsing.h"

class help : public myCommand
{
private:
	std::vector<myCommand*> allCommands;	
public:
	help();
	help(std::vector<myCommand*> allCommands);

	void addAllCommands(std::vector<myCommand*> allComms);
	void addTargs(myTarget target);
	void assignment(std::vector<std::string> assign);	
	void launchCommand() const;
	
};

