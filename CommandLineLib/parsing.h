#pragma once
#include <vector>
#include "myCommand.h"
#include "target.h"

class parsing
{
private:
	std::vector<myCommand> commands;
	target mytargets;
public:
	parsing();
	std::vector<myCommand> getCommands();
	void addCommand(const myCommand& command);
	void parse(int argc, char* argv[]);
};

