#include "pch.h"
#include "help.h"
#include <iostream>

help::help():myCommand("--help", "-h",
	"Donne des infos sur les commandes",
	0, false, true), allCommands()
{
}

help::help(std::vector<myCommand*> allcommands): myCommand("--help", "-h",
	"Donne des infos sur les commandes",
	0, false, true), allCommands(allcommands)
{	
}

void help::addAllCommands(std::vector<myCommand*> allComms)
{
	allCommands = allComms;
}

void help::addTargs(myTarget target)
{
	myTargs = target;
}

void help::assignment(std::vector<std::string> assign)
{	
	myArgs = assign;
}

void help::launchCommand() const 
{
	if (myArgs.size() < 2) {
		// Afficher l'aide de la ligne de commande
		std::cout << "Usage: monexe [ --help|-h ] Files+" << std::endl;
		std::cout << "Files: Files to compile" << std::endl;
		std::cout << "Options:" << std::endl;
		std::cout << "--help, -h : Print this help" << std::endl;
	}
	else {
		std::cout << "Help:\n";
		for (const auto& command : allCommands) {			
			std::cout << command->getName() << " " << command->getAlias() 
				<< " la fonction a besoin de " << command->getArgumentNumber()
				<< " arguments, "
				<< command->getDescription() <<std::endl;
		}
	}
}
