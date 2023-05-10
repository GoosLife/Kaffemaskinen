#pragma once
#include "PhysicalContainer.h"
#include "Liquid.h"

class Cup : public PhysicalContainer<Liquid>
{
public:
	Cup(int maxCapacity) : PhysicalContainer<Liquid>(maxCapacity) {}
	~Cup() {}
};

