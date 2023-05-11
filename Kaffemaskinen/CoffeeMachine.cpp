#include "CoffeeMachine.h"
#include "TeaLeaf.h"
#include "CoffeeBean.h"
#include "OutputIngredient.h"

#include <iostream>
#include <typeinfo>

CoffeeMachine::CoffeeMachine()
{
	Dispenser<Liquid>* coffeeDispenser = new Dispenser<Liquid>();
	Filter* filter = new Filter(50); // The coffee machine comes with a brand new filter that can hold up to 50 coffee beans!
	WaterContainer* waterContainer = new WaterContainer(500);

	_coffeeDispenser = coffeeDispenser;
	_filter = filter;
	_waterContainer = waterContainer;

	_parts.push_back(coffeeDispenser);
	_parts.push_back(filter);
	_parts.push_back(waterContainer);
}

CoffeeMachine::~CoffeeMachine() {}

void CoffeeMachine::RemoveFilter()
{
	if (_filter != nullptr)
	{
		for (auto it = _parts.begin(); it != _parts.end(); ++it)
		{
			if (*it == _filter)
			{
				_parts.erase(it);
				break;
			}
		}
		delete _filter;
		_filter = nullptr;
	}
}

void CoffeeMachine::AddFilter(Filter* filter)
{
	_filter = filter;
	_parts.push_back(_filter);
}

void CoffeeMachine::AddWater(Water water)
{
	_waterContainer->addIngredient(water);
}

template <typename T, typename Enable>
void CoffeeMachine::FillCoffeeFilter(T& coffeeBean)
{
	_filter->addIngredient(coffeeBean);
}

void CoffeeMachine::AddWater(std::vector<Water> water)
{
	_waterContainer->addIngredient(water);
}

template <typename T, typename Enable>
void CoffeeMachine::FillCoffeeFilter(std::vector<T>& coffeeBeans)
{
	_filter->addIngredient(coffeeBeans);
}

void CoffeeMachine::BrewCoffee(std::vector<PhysicalContainer<Liquid>>& cups)
{
	if (_filter != nullptr) {
		try {
			_coffeeDispenser->dispense(cups, _filter->getIngredient());
		}
		catch (std::exception e) {
			// Tell user filter is empty
		}
	}
}

void CoffeeMachine::BrewCoffee(PhysicalContainer<Liquid>& cup)
{
	if (_filter != nullptr) {
		try {
			_coffeeDispenser->dispense(cup, _filter->getIngredient());
		}
		catch (std::exception e) {
			// Tell user filter is empty
		}
	}
}
