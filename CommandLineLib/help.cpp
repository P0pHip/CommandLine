#include "pch.h"
#include "help.h"
#include <iostream>

help::help(): myCommand("--help", "-h",
	"Donne des infos sur les commandes",
	0, false, true)
{	
}

void help::assignment(std::vector<std::string> assign) const
{	
	std::cout << assign[0];
}

void help::launchCommand() const
{
	std::cout << "coucou";
}

void help::launchCommand(parsing parser) const
{
	for (const auto& command : parser.getCommands()) {
		std::cout << command->getName() << " " << command->getAlias() << std::endl;
	}
}


