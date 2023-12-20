#include "pch.h"
#include "command.h"

command::command(std::string name, std::string alias,
	std::string description, size_t argumentNumber, 
	bool obligatoryFlag, bool immediatlyFlag)
	: name(name),alias(alias),description(description),
	argumentNumber(argumentNumber),obligatoryFlag(obligatoryFlag),
	immediatlyFlag(immediatlyFlag)
{	
}
