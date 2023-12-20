#include "pch.h"
#include "parsing.h"
#include <stdexcept>

void parsing::addCommand(myCommand* command)
{
	commands.push_back(command);
}

void parsing::parse(int argc, char* argv[])
{
    if (argc < 2) {
        throw std::invalid_argument("Aucune commande sp�cifi�e.");
    }

    for (int i = 1; i < argc; ++i) {
        const std::string arg = argv[i];

        for (const auto& command : commands) {
            // La commande est trouv�e, appelle la fonction de rappel associ�e
            if (command->getName() == arg) {
                if (command->isImediatly()) {
                    command->launchCommand();
                }
            }
            // je sais pas encore

            else {
                throw std::invalid_argument("Commande inconnue : " + arg);
            }
        }
        
    }
}
