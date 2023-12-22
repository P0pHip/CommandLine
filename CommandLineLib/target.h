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
	target();
	target(std::vector<std::string> targs,
		std::string desc,
		bool empty);
	target(const target& other);
	~target();
	std::vector<std::string> getTargets();
	std::string getDescription();
	bool isEmpty();
	target& operator=(const target& other);
};

