#pragma once

#include "Ingredient.h"

class Liquid : public Ingredient
{
public:
	Liquid(std::string name = "Liquid") : Ingredient(name) {}
	~Liquid() {}
};