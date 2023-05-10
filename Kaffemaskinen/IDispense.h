#pragma once

#include "Container.h"

#include <vector>

template <typename T, typename U>
class IDispense {
	virtual void dispense(std::vector<Container<U>*>& containers) = 0;
};