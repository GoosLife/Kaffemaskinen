#pragma once
#include "Liquid.h"
class Water :
    public Liquid
{
public:
	Water() : Liquid("Water") {}
	~Water() {}
};

