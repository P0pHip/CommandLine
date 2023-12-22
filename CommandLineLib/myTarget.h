#pragma once
#include <vector>
#include <string>

class myTarget
{
private:
	std::vector<std::string> targets;
	std::string description;
	bool empty;
public:
	myTarget();
	myTarget(std::vector<std::string> targs,
		std::string desc,
		bool empty);
	myTarget(const myTarget& other);
	~myTarget();
	std::vector<std::string> getTargets();
	std::string getDescription();
	bool isEmpty();
	myTarget& operator=(const myTarget& other);
};

