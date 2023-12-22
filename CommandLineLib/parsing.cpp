#include "pch.h"
#include "parsing.h"
#include <stdexcept>

parsing::parsing() :mytargets(), commands()
{
}

std::vector<myCommand> parsing::getCommands()
{
    return commands;
}

void parsing::addCommand(const myCommand& command)
{
	commands.push_back(command);
}

void parsing::parse(int argc, char* argv[])
{
    if (argc < 2) {
        throw std::invalid_argument("Aucune commande spécifiée.");
    }
    
    // recherche des cibles 
    std::vector<std::string> vTargets;
    std::string argTarg;
    bool isTarg = false;

    for (int i = argc; i > 2; --i) {
        const std::string arg = argv[i];
        if (arg.find('.') != std::string::npos) {
            vTargets.push_back(arg);
            isTarg = true;
        }
        else argTarg = arg; break;
    }
    std::string descTarget = "les cibles sont des fichiers du meme type que:"+argTarg+"\n";
    mytargets = target(vTargets, descTarget, isTarg);
    // les cibles on été trouvés


    // On passe a la recherche des commandes
    for (int i = 1; i < argc; ++i) {
        const std::string arg = argv[i];

        for (const auto& command : commands) {
            // La commande est trouvée, appelle la fonction de rappel associée
            if (command.getName() == arg) {
                if (command.isImediatly()) {
                    command.launchCommand();
                }
            }
            // je sais pas encore

            else {
                throw std::invalid_argument("Commande inconnue : " + arg);
            }
        }
        
    }
}
