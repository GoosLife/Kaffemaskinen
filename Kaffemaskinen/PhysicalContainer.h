#pragma once

#include "Part.h"
#include "Ingredient.h"

#include <vector>
#include <type_traits>

template<typename T>
class PhysicalContainer : public Part {
	static_assert(std::is_base_of<Ingredient, T>::value, "Container can only contain ingredients.");
public:
	PhysicalContainer(int maxCapacity) : _maxCapacity(maxCapacity) {}

	bool hasIngredient() { return ingredients.size() > 0; }

	void addIngredient(T ingredient) {
		if (ingredients.size() < _maxCapacity) {
			ingredients.emplace_back(std::move(ingredient));
		}
		else {
			// Reject ingredient
		}
	}

	void addIngredient(std::vector<T> ingredientsToAdd)
	{
		int amount = ingredientsToAdd.size();
		int amountLeft = amount;

		for (int i = 0; i < amount && ingredients.size() < _maxCapacity; i++)
		{
			ingredients.push_back(ingredientsToAdd.back());
			ingredientsToAdd.pop_back();
			amountLeft--;
		}

		if (amountLeft > 0)
		{
			// Reject remaining ingredients
		}
	}

	template <typename U>
	void addIngredient(U ingredient) {
		// Check if U is the same type as the value_type of _ingredients
		if constexpr (std::is_same_v<U, typename std::vector<T>::value_type>) {
			ingredients.push_back(ingredient);
		}
		else {
			// U is not the same type as the value_type of _ingredients
			// Handle the error here
		}
	}

	std::string getIngredientName() { return ingredients.back().getName(); }
	T& getIngredient() { return ingredients.back(); }

private:
	std::vector<T> ingredients;
	int _maxCapacity;
};

