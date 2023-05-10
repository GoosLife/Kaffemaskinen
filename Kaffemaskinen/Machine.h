#pragma once
#include "Part.h"
#include <vector>

class Machine
{
public:
	~Machine() {
		//for (auto part : _parts)
		//{
		//	delete(part);
		//}
		//_parts.clear();
	}

protected:
	Machine() {}
	std::vector<Part*> _parts;
};
