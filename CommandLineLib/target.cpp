#include "pch.h"
#include "target.h"

target::target(std::vector<std::string> targs, std::string desc, bool isE): 
	targets(targs), description(desc), empty(isE)
{
}

target::~target()
{
}

std::vector<std::string> target::getTargets()
{
	return targets;
}

std::string target::getDescription()
{
	return description;
}

bool target::isEmpty()
{
	return empty;
}
