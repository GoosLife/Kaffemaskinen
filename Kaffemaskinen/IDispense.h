#pragma once

#include "PhysicalContainer.h"
#include "OutputIngredient.h"

#include <vector>

template <typename U>
class IDispense {
	virtual void dispense(std::vector<PhysicalContainer<U>>& containers, OutputIngredient<Ingredient>& ingredient) = 0;
	virtual void dispense(PhysicalContainer<U>& container, OutputIngredient<Ingredient>& ingredient) = 0;
};