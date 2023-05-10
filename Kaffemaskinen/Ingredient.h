#pragma once

#include <string>

class Ingredient
{
public:
	~Ingredient() {}
	virtual std::string getName() const { return _name; }
protected:
	Ingredient(std::string name) {}
	std::string _name;
};