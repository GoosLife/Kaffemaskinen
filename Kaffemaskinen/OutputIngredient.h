#pragma once
#include "Ingredient.h"

template <typename T> // The output of the ingredient
class OutputIngredient :
    public Ingredient
{
public:
    virtual T brew() = 0;
protected:
    OutputIngredient(std::string name) : Ingredient(name) {}
};

