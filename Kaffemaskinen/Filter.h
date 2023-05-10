#pragma once
#include "PhysicalContainer.h"
#include "CoffeeBean.h"

class Filter :
    public PhysicalContainer<CoffeeBean>
{
public:
    Filter(int maxCapacity) : PhysicalContainer<CoffeeBean>(maxCapacity) {}
	~Filter() {}
};

