#include "pch.h"
#include "myTarget.h"

myTarget::myTarget() : targets(), description(), empty(true)
{
}

myTarget::myTarget(std::vector<std::string> targs, std::string desc, bool isE):
	targets(targs), description(desc), empty(isE)
{
}

myTarget::myTarget(const myTarget& other)
	: targets(other.targets), description(other.description), empty(other.empty)
{
}

myTarget::~myTarget()
{
}

std::vector<std::string> myTarget::getTargets()
{
	return targets;
}

std::string myTarget::getDescription()
{
	return description;
}

bool myTarget::isEmpty()
{
	return empty;
}

myTarget& myTarget::operator=(const myTarget& other)
{
    if (this != &other)
    {
        targets = other.targets;
        description = other.description;
        empty = other.empty;        
    }
    return *this;
}