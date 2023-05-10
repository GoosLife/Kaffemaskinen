#pragma once

#include "Part.h"
#include "Ingredient.h"

#include <vector>

template<typename T>
class Container : public Part {
	static_assert(std::is_base_of<Ingredient, T>::value, "Container can only contain ingredients.");
public:
	Container(int maxCapacity) : _maxCapacity(maxCapacity) {}

	bool hasIngredient() { return ingredients.size() > 0 }

	void addIngredient(T ingredient) {
		if (ingredients.size() < _maxCapacity) {
			ingredients.push_back(ingredient);
		}
		else {
			// Reject ingredient
		}
	}

private:
	std::vector<T> ingredients;
	int _maxCapacity;
};

