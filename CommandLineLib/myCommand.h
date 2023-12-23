#pragma once
#include <string>
#include <vector>
#include "myParsing.h"


class myCommand
{
protected:
	std::string name;
	std::string alias;
	std::vector<std::string> myArgs;
	myTarget myTargs;

	size_t argumentNumber;
	std::string description;
	bool obligatoryFlag;
	bool immediatlyFlag;
public:
	std::string getName() const;
	std::string getAlias() const;

	size_t getArgumentNumber() const;
	std::string getDescription() const;
	bool isObligatory() const;
	bool isImmediatly() const;

	myCommand(std::string name, std::string alias,
		std::string description, size_t argumentNumber,
		bool obligatoryFlag = false, bool immediatlyFlag = false);
	virtual void assignment(std::vector<std::string> assign) = 0;
	virtual void addTargs(myTarget target) = 0;
	virtual void launchCommand() const = 0;
	virtual ~myCommand() = default;
};
