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

void help::launchCommand(myParsing parser) const 
{
	if (parser.getArgc() < 2) {
		// Afficher l'aide de la ligne de commande
		std::cout << "Usage: monexe [ --help|-h ] Files+" << std::endl;
		std::cout << "Files: Files to compile" << std::endl;
		std::cout << "Options:" << std::endl;
		std::cout << "--help, -h : Print this help" << std::endl;
	}
	else {
		for (const auto& command : parser.getCommands()) {
			std::cout << command->getName() << " " << command->getAlias() << std::endl;
		}
	}
}
