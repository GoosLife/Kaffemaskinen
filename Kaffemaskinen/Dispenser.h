#pragma once

#include "Part.h"
#include "IDispense.h"

#include <vector>

template <typename T, typename U>
class Dispenser : public Part, public IDispense<T, U>
{
public:
	Dispenser() {}
	~Dispenser() {}

	virtual void dispense(std::vector<PhysicalContainer<U>>& containers) override
	{
		for (auto& container : containers)
		{
			T t;
			container.addIngredient(t);
		}
	}

	virtual void dispense(PhysicalContainer<U>& container) override
	{
		T t;
		container.addIngredient(t);
	}
};