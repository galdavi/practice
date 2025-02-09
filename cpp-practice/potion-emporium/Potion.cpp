#include "Potion.h"
#include "Random.h"
#include "Player.h"
#include <iostream>


void Potion::shop()
{
    std::cout << "\nHere is our selection for today:\n";
    for(std::size_t i{0}; i < static_cast<int>(Potion::max_types); i++)
    {
        std::cout << i << ") " << Potion::names[i] << " costs " << Potion::cost[i] << '\n';
    }    
}