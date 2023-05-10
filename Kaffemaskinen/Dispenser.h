#pragma once

#include "Part.h"
#include "IDispense.h"

#include <vector>

template <typename T, typename U>
class Dispenser : public Part, public IDispense<T>
{
public:
	Dispenser() {}
	~Dispenser() {}

	virtual void dispense(std::vector<Container<U>>& containers)
	{
		for (auto container in containers)
		{
			container->addIngredient(T);
		}
	}

	T 
};