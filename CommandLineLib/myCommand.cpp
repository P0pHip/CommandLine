#include "pch.h"
#include "myCommand.h"

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

bool myCommand::isImediatly() const
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
