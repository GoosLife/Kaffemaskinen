#pragma once

#include "Part.h"
#include "IDispense.h"

#include <vector>

template <typename U>
class Dispenser : public Part, public IDispense<U>
{
public:
	Dispenser() {}
	~Dispenser() {}

	virtual void dispense(std::vector<PhysicalContainer<U>>& containers, OutputIngredient<Ingredient>& ingredient) override
	{
		for (auto& container : containers)
		{
			auto output = ingredient.brew();
			container.addIngredient(output);
		}
	}

	virtual void dispense(PhysicalContainer<U>& container, OutputIngredient<Ingredient>& ingredient) override
	{
		auto output = ingredient.brew();
		container.addIngredient(output);
	}
};