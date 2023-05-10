#pragma once

#include "Part.h"

#include <vector>

class Dispenser
{
public:
	Dispenser();
	~Dispenser();

private:
	std::vector<Part*> parts;
};
