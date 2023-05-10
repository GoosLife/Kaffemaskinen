#pragma once
#include "Liquid.h"
class Coffee :
    public Liquid
{
public:
    Coffee() : Liquid("Coffee") {}
	~Coffee() {}
};

