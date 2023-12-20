#pragma once
#include <string>
#include <vector>
class myCommand
{
private:
	std::string name;
	std::string alias;

	size_t argumentNumber;
	std::string description;
	bool obligatoryFlag;
	bool immediatlyFlag;
public:
	std::string getName();
	std::string getAlias();

	size_t getArgumentNumber();
	std::string getDescription();
	bool isObligatory();
	bool isImediatly();

	myCommand(std::string name, std::string alias,
		std::string description, size_t argumentNumber,
		bool obligatoryFlag = false, bool immediatlyFlag = false);
	virtual void assignment(std::vector<std::string> assign) const = 0;
	virtual void launchCommand() const = 0;
	virtual ~myCommand() = default;
};
