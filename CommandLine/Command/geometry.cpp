#include "geometry.h"
#include <iostream>
#include <fstream>

geometry::geometry() : myCommand("--geometry", "-g",
	"Detecte si les arguments nous donne un carre ou un rectangle et enregistre le résulat dans un fichier que vous souhaitez.",
	2, false, false)
{
}

void geometry::assignment(std::vector<std::string> assign)
{
	myArgs = assign;
}

void geometry::addTargs(myTarget target)
{
	myTargs = target;
}

void geometry::launchCommand() const
{
	std::string nb1 = myArgs[0];
	std::string nb2 = myArgs[1];
	if (nb1 == nb2) {
		std::cout << "Ceci est un carre de " << nb1 << " par " << nb2 << std::endl;

        for (const auto& targ : myTargs.getTargets()) {
            // Ouvrir le fichier en mode écriture (ios::out)
            std::ofstream outFile(targ);

            // Vérifier si l'ouverture a réussi
            if (outFile.is_open()) {
                // Écrire dans le fichier
                outFile << "Ceci est un carre de " << nb1 << " par " << nb2 << std::endl;

                // Fermer le fichier
                outFile.close();

                std::cout << "Écriture dans le fichier réussie." << std::endl;
            }
            else {
                std::cerr << "Erreur lors de l'ouverture du fichier." << std::endl;
            }
        }
	}

    else {
        std::cout << "Ceci est un rectangle de " << nb1 << " par " << nb2 << std::endl;

        for (const auto& targ : myTargs.getTargets()) {
            // Ouvrir le fichier en mode écriture (ios::out)
            std::ofstream outFile(targ);

            // Vérifier si l'ouverture a réussi
            if (outFile.is_open()) {
                // Écrire dans le fichier
                outFile << "Ceci est un rectangle de " << nb1 << " par " << nb2 << std::endl;               

                // Fermer le fichier
                outFile.close();

                std::cout << "Ecriture dans le fichier " << targ <<" reussie." << std::endl;
            }
            else {
                std::cerr << "Erreur lors de l'ouverture du fichier "<< targ <<"."<< std::endl;
            }
        }
    }
}
