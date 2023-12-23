#include "pch.h"
#include "myParsing.h"
#include "myCommand.h"
#include <stdexcept>
#include <iostream>
#include "help.h"

myParsing::myParsing(int argc, char* argv[]) :argc(argc), argv(argv), mytargets(), commands()
{
}

std::vector<myCommand*> myParsing::getCommands()
{
    return commands;
}

int myParsing::getArgc() const
{
    return argc;
}

char** myParsing::getArgv()
{
    return argv;
}

void myParsing::addCommand(myCommand* command)
{
	commands.push_back(command);
}

void myParsing::parse()
{
    // on ajoute a Help la liste des commandes
    for (const auto& command : commands) {
        // je caste dynamiquement vers la classe help
        if (auto* helpCommand = dynamic_cast<help*>(command)) {
            std::vector<std::string> arguments;
            for (int i = 0; i < argc; ++i) {
                arguments.push_back(argv[i]);
            }
            helpCommand->assignment(arguments);
            helpCommand->addAllCommands(commands);
            break;
        }
    }

    if (argc < 2) {
        for (const auto& command : commands) {
            // Vous pouvez ajuster cette condition en fonction du nom de la commande que vous recherchez
            if (command->getName() == "--help") {
                command->launchCommand();
            }
        }
    }
    else {        

        // recherche des cibles 
        std::vector<std::string> vTargets;
        std::string argTarg;
        bool isTarg = false;

        for (int i = argc; i > 2; --i) {
            const std::string arg = argv[i-1];
            if (arg.find('.') != std::string::npos) {
                vTargets.push_back(arg);
                isTarg = true;
            }
            if (arg.find('.') == std::string::npos) {
                break; // je quitte pour que argTarg reste vide
            }
            else argTarg = arg; break;
        }
        std::string descTarget = "les cibles sont des fichiers du meme type que: " + argTarg + "\n";
        std::cout << descTarget << std::endl;
        mytargets = myTarget(vTargets, descTarget, isTarg);
        // les cibles on été trouvés

        //vector pour stochker les methodes non imédiates;
        std::vector<myCommand*> notImmediatlys;

        // On passe a la recherche des commandes
        for (int i = 1; i < argc; ++i) {
            const std::string arg = argv[i];            
            if (arg.find('-') != std::string::npos || arg.find("--") != std::string::npos) {
                for (const auto& command : commands) {
                    // La commande est trouvée, appelle la fonction de rappel associée
                    if (command->getName() == arg || command->getAlias() == arg) {
                        if (command->getArgumentNumber() > 0) {
                            if (command->getArgumentNumber() + i < argc) {
                                std::vector<std::string> myArgs;
                                for (int j = 1; j <= command->getArgumentNumber(); j++) {
                                    myArgs.push_back(argv[i + j]);
                                }
                                command->assignment(myArgs);
                            }
                            else {
                                std::cout << "le nombre d'argument n'est pas bon pour: " << command->getName() << std::endl;
                                break; //quitte la boucle for car il n'ya pas assez d'argument;
                            }
                        }
                        if (command->isImmediatly()) {
                            if (auto* helpCommand = dynamic_cast<help*>(command)) {
                                std::vector<std::string> arguments;
                                for (int i = 0; i < argc; ++i) {
                                    arguments.push_back(argv[i]);
                                }
                                helpCommand->assignment(arguments);
                                helpCommand->addAllCommands(commands);
                            }
                            std::cout << "je launch une commande immediate\n";
                            command->launchCommand();
                            // ya un warning mais il est pas possible selon moi
                            std::cout << std::endl << std::endl;
                            break;
                        }
                        else {                            
                            notImmediatlys.push_back(command);
                        }
                        break;
                    }                   
                }            
            }
            else {
                if (arg.find('-') != std::string::npos || arg.find("--") != std::string::npos) {
                    std::cout << "Commande inconnue : " << arg << std::endl;
                }                
            }
        }
        // lancement de toutes les commandes non immediates.
        for (const auto& command : notImmediatlys) {
            std::cout << "je launch une commande non immediate\n";
            command->launchCommand();
            std::cout << std::endl << std::endl;
        }
    }
}
