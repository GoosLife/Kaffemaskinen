#include <iostream>

#include "CoffeeMachine.h"
#include "Cup.h"
#include "CoffeeBean.h"
#include "Coffee.h"
#include "OutputIngredient.h"
#include "Water.h"

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
    c.FillCoffeeFilter<CoffeeBean>(beanBag); // Fill the filter with up to 50 coffee beans

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

    getchar();
}

