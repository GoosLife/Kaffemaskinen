#pragma once

#include <string>
class Ingredient
{
public:
	using value_type = Ingredient;
	~Ingredient() {}
	virtual std::string getName() const { return _name; }
protected:
	Ingredient(std::string name) : _name(name) {}
	std::string _name;
};