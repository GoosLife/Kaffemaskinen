#pragma once
#include "Ingredient.h"
class CoffeeBean :
    public Ingredient
{
public:
    CoffeeBean() : Ingredient("coffee bean") {}
};

