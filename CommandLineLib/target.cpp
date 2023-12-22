#include "pch.h"
#include "target.h"

target::target() : targets(), description(), empty(true)
{
}

target::target(std::vector<std::string> targs, std::string desc, bool isE):
	targets(targs), description(desc), empty(isE)
{
}

target::target(const target& other)
	: targets(other.targets), description(other.description), empty(other.empty)
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

target& target::operator=(const target& other)
{
    if (this != &other)
    {
        targets = other.targets;
        description = other.description;
        empty = other.empty;        
    }
    return *this;
}