#pragma once
#include "Dispenser.h"
#include "Coffee.h"
#include "CoffeeBean.h"
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
	void ChangeFilter(std::unique_ptr<Filter> newFilter);

private:
	Dispenser<Coffee, Liquid>* _coffeeDispenser;
	Filter* _filter;
	WaterContainer* _waterContainer;
};

