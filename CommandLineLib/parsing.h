#pragma once
#include <vector>
#include "myCommand.h"

class parsing
{
private:
	std::vector<myCommand*> commands;
public:
	void addCommand(myCommand* command);
	void parse(int argc, char* argv[]);
};

