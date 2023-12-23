#include "pch.h"
#include "myCommand.h"

std::string myCommand::getName() const
{
	return name;
}

std::string myCommand::getAlias() const
{
	return alias;
}

size_t myCommand::getArgumentNumber() const
{
	return argumentNumber;
}

std::string myCommand::getDescription() const
{
	return description;
}

bool myCommand::isObligatory() const
{
	return obligatoryFlag;
}

bool myCommand::isImmediatly() const
{
	return immediatlyFlag;
}

myCommand::myCommand(std::string name, std::string alias,
	std::string description, size_t argumentNumber, 
	bool obligatoryFlag, bool immediatlyFlag)
	: name(name),alias(alias), myArgs(), description(description),
	argumentNumber(argumentNumber),obligatoryFlag(obligatoryFlag),
	immediatlyFlag(immediatlyFlag)
{	
}
