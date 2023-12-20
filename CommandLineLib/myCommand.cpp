#include "pch.h"
#include "myCommand.h"

std::string myCommand::getName()
{
	return name;
}

std::string myCommand::getAlias()
{
	return alias;
}

size_t myCommand::getArgumentNumber()
{
	return argumentNumber;
}

std::string myCommand::getDescription()
{
	return description;
}

bool myCommand::isObligatory()
{
	return obligatoryFlag;
}

bool myCommand::isImediatly()
{
	return immediatlyFlag;
}

myCommand::myCommand(std::string name, std::string alias,
	std::string description, size_t argumentNumber, 
	bool obligatoryFlag, bool immediatlyFlag)
	: name(name),alias(alias),description(description),
	argumentNumber(argumentNumber),obligatoryFlag(obligatoryFlag),
	immediatlyFlag(immediatlyFlag)
{	
}
