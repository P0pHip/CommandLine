#include "hello.h"
#include <iostream>

hello::hello() : myCommand("--hello", "-hey",
	"Bonjour",
	2, false, false)
{
}


void hello::assignment(std::vector<std::string> assign)
{
	myArgs = assign;
}

void hello::addTargs(myTarget target)
{
	myTargs = target;
}

void hello::launchCommand() const
{
	std::cout << "Bonjour " << myArgs[0] << " " << myArgs[1] << std::endl;
}
