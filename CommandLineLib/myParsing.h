#pragma once
#include <vector>
#include "myTarget.h"

class myCommand;

class myParsing
{
private:
	std::vector<myCommand*> commands;
	myTarget mytargets;
public:
	myParsing();
	std::vector<myCommand*> getCommands();
	void addCommand(myCommand* command);
	void parse(int argc, char* argv[]);
};

