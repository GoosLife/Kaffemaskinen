#pragma once
#include "OutputIngredient.h"
#include "Tea.h"

class TeaLeaf :
    public OutputIngredient<Tea>
{
public:
    TeaLeaf() : OutputIngredient<Tea>("TeaLeaf") {}
	~TeaLeaf() {}

    virtual Tea brew() override;
};

