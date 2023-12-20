#pragma once
#include <string>
#include <vector>
class command
{
private:
	std::string name;
	std::string alias;

	size_t argumentNumber;
	std::string description;
	bool obligatoryFlag;
	bool immediatlyFlag;
public:
	command(std::string name, std::string alias,
		std::string description, size_t argumentNumber,
		bool obligatoryFlag = false, bool immediatlyFlag = false);
	virtual void assignment(std::vector<std::string> assign) const = 0;
	virtual void launchCommand() const = 0;	
};
