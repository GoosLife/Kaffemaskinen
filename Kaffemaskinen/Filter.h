#pragma once
#include "PhysicalContainer.h"
#include "OutputIngredient.h"

class Filter :
    public PhysicalContainer<OutputIngredient<Ingredient>>
{
public:
    Filter(int maxCapacity) : PhysicalContainer<OutputIngredient<Ingredient>>(maxCapacity) {}
	~Filter() {}
};

