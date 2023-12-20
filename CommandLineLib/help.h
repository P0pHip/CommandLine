#pragma once
#include "myCommand.h"
#include "parsing.h"

class help : public myCommand
{
public:
	help();

	void assignment(std::vector<std::string> assign) const;
	void launchCommand() const;
	void launchCommand(parsing parser) const;

};

