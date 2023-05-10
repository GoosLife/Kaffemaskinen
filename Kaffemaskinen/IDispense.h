#pragma once

#include "Container.h"

#include <vector>

class IDispense {
	virtual void dispense(std::vector<Container>& containers) = 0;
};