#pragma once
#include "PhysicalContainer.h"
#include "Water.h"

class WaterContainer :
    public PhysicalContainer<Water>
{
public:
	WaterContainer(int maxCapacity) : PhysicalContainer(maxCapacity) {}
	~WaterContainer() {}
};
