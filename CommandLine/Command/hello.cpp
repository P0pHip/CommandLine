#include "hello.h"

hello::hello() : myCommand("--hello", "-hey",
	"Bonjour",
	2, false, false)
{
}


void hello::assignment(std::vector<std::string> assign) const
{
}

void hello::launchCommand(myParsing parser) const
{
}
