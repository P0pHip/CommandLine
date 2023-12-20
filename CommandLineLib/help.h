#pragma once
#include "command.h"

class help : public command
{
public:
	help();
	void assignment(std::vector<std::string> assign) const;
	void launchCommand() const;
};

