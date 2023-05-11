#pragma once
#include "OutputIngredient.h"
#include "Coffee.h"

class CoffeeBean :
    public OutputIngredient<Coffee>
{
public:
    CoffeeBean() : OutputIngredient("coffee bean") {}
    

    // Inherited via OutputIngredient
    virtual Coffee brew() override;

};

