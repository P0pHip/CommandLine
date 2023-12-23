#pragma once
#include <vector>
#include "myTarget.h"

class myCommand;

class myParsing
{
private:
	std::vector<myCommand*> commands;
	myTarget mytargets;
	int argc;
	char** argv;
public:
	myParsing(int argc, char* argv[]);
	std::vector<myCommand*> getCommands();
	int getArgc() const;
	char** getArgv();
	void addCommand(myCommand* command);
	
	void parse(); 
	
};

