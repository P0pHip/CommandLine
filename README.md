# CommandLine

Mon Programme contient la bibliothèque CommandLineLib;
Pour utiliser et créer ces propres commandes il faut créer des classes héritant de myCommand;
cf la documentation doxygène et sa page de my command qui présente un petit diagramme d'héritage;

La classe la plus importante est  myParsing avec la methode parse:

pour utiliser mon code 2 methodes:

    Premierement depuis visual studio lancé le code en debug ou release pour creer un executable;
    ensuite 2 méthodes:

        - Premièrement dans les paramètres de debogage de visual choisir de lancé
          le code avec les argument que vous voulez;
        - creer un terminal par l'intermédiare de Visual Studio (crtl+ù)
          ou de façon classique puis vous devez vous déplacer jusqu'à l'executable:
          Voici un exmple de chemin: cd .\CommandLine\x64\Debug\ puis ./CommandLine.exe


Pour ce qui s'agit de mes tests unitaires je considaires que ce sont mes commandes de tests qui sont sont dans le dossiers ./commandLine/command "hello" et "geometry" qui font office de test unitaires.

"geometry" prend 2 parametres et retourne si c'est un carre ou un rectangle et affiche le résulat en ligne de commande et dans un fichier;

"hello" prend 2 paramètre et affiche "bonjour param1 param2";
