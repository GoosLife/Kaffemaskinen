#pragma once

#include "Ingredient.h"

class Liquid : public Ingredient
{
public:
	Liquid(std::string name) : Ingredient(name) {}
	~Liquid() {}
};