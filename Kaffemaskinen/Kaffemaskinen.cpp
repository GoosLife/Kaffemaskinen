#include <iostream>

#include "CoffeeMachine.h"
#include "Cup.h"
#include "CoffeeBean.h"
#include "Coffee.h"
#include "OutputIngredient.h"
#include "TeaLeaf.h"
#include "Water.h"

#include <typeinfo>

int main()
{
    CoffeeMachine c;
    
    std::vector<Water> waterSource;

    for (int i = 0; i < 100; i++)
    {
        Water w;
        waterSource.push_back(w);
    }

    std::vector<CoffeeBean> beanBag;

    for (int i = 0; i < 50; i++)
    {
        CoffeeBean b;
		beanBag.push_back(b);
    }

    c.AddWater(waterSource); // Add up to 100 water to the water container
    c.FillCoffeeFilter(beanBag); // Fill the filter with up to 50 coffee beans

    std::vector<PhysicalContainer<Liquid>> allOurCups;

    for (int i = 0; i < 10; i++)
    {
        Cup cup(10); // Create a cup that can hold up to 10 "liquid"
        allOurCups.push_back(cup);
    }

    c.BrewCoffee(allOurCups); // Brew coffee into all our cups

    for (int i = 0; i < allOurCups.size(); i++)
    {
        std::cout << "Cup " << i << " has " << allOurCups[i].getIngredientName() << " in it!" << std::endl;
    }

    // Our coffee machine can now also brew tea. Let us use a new coffee machine (because I don't want to clean the old one first)
    CoffeeMachine teaMachine;

    std::vector<TeaLeaf> teaBag;

    for (int i = 0; i < 50; i++) {
        TeaLeaf t;
        teaBag.push_back(t);
        teaMachine.FillCoffeeFilter(t);
    }

    teaMachine.AddWater(waterSource);
    teaMachine.FillCoffeeFilter(teaBag);
    
    teaMachine.BrewCoffee(allOurCups);

    for (int i = 0; i < allOurCups.size(); i++)
    {
        std::cout << "Cup " << i << " has " << allOurCups[i].getIngredientName() << " in it!" << std::endl;
    }

    getchar();
}

