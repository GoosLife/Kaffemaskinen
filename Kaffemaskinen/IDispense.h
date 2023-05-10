#pragma once

#include "PhysicalContainer.h"

#include <vector>

template <typename T, typename U>
class IDispense {
	virtual void dispense(std::vector<PhysicalContainer<U>>& containers) = 0;
	virtual void dispense(PhysicalContainer<U>& container) = 0;
};