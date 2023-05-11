#pragma once
#include "Dispenser.h"
#include "Coffee.h"
#include "CoffeeBean.h"
#include "OutputIngredient.h"
#include "Filter.h"
#include "Machine.h"
#include "Water.h"
#include "WaterContainer.h"

#include <memory>

class CoffeeMachine :
    public Machine
{
public:
	CoffeeMachine();
	~CoffeeMachine();

	void RemoveFilter();
	void AddFilter(Filter* filter);
	
	// Notice how these two overloaded functions are identical to the ones in container, so we can add one or more water, and one or more beans at the same time by calling the same function throughout.

	void AddWater(Water water);

	void AddWater(std::vector<Water> water);

	template <typename T, typename std::enable_if<std::is_base_of<OutputIngredient<Ingredient>, T>::value, int>::type = 0>
	void FillCoffeeFilter(const T& ingredient) {
		_filter->addIngredient(ingredient);
	}

	template <typename T, typename std::enable_if<std::is_base_of<OutputIngredient<Ingredient>, T>::value, int>::type = 0>
	void FillCoffeeFilter(std::vector<T> ingredients) {
		for (auto& ingredient : ingredients) {
			_filter->addIngredient(ingredient);
		}
	}

	void FillCoffeeFilter(const Ingredient& ingredient) {
		_filter->addIngredient(ingredient);
	}

	// This could be on a "StartButton" part or similar, but for now, we will just use the interface like this

	void BrewCoffee(std::vector<PhysicalContainer<Liquid>>& cups);
	void BrewCoffee(PhysicalContainer<Liquid>& cup);
	
private:
	Dispenser<Liquid>* _coffeeDispenser;
	Filter* _filter;
	WaterContainer* _waterContainer;
};

