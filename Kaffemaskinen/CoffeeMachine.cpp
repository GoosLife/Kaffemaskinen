#include "CoffeeMachine.h"

CoffeeMachine::CoffeeMachine()
{
	Part* coffeeDispenser = new Dispenser<Coffee, Liquid>();
	Part* filter = new Filter(50); // The coffee machine comes with a brand new filter that can hold up to 50 coffee beans!
	Part* waterContainer = new WaterContainer(500);

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

void CoffeeMachine::ChangeFilter(std::unique_ptr<Filter> newFilter)
{
	bool filterExists = false;
	for (auto it = _parts.begin(); it != _parts.end(); ++it)
	{
		if (*it == _filter)
		{
			_filter = std::move(newFilter);
			delete _filter;
			*it = std::move(newFilter);
			filterExists = true;
			break;
		}
	}
	if (!filterExists)
	{
		_filter = newFilter;
		_parts.push_back(_filter);
	}
}