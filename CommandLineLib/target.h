#pragma once
#include <vector>
#include <string>

class target
{
private:
	std::vector<std::string> targets;
	std::string description;
	bool empty;
public:
	target(std::vector<std::string> targs,
		std::string desc = "",
		bool empty = true);
	~target();
	std::vector<std::string> getTargets();
	std::string getDescription();
	bool isEmpty();
};

