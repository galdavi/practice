#include "Potion.h"
#include "Random.h"
#include "Player.h"
#include <iostream>


std::string Potion::getName()
{
    std::string name{};
    std::cout << "Enter name: ";
    std::cin >> name;

    return name;
}


void Potion::shop()
{
    std::cout << "Welcome to Roscoe's potion emporium!\n";
    std::string name{getName()};
    Player player{name,Random::get(1,200) };
    std::cout << "Hello, " << player.getName() << " you have " << player.getGold() << " gold.\n";
    std::cout << "Here is our selection for today:\n";
    for(std::size_t i{0}; i < static_cast<int>(Potion::max_types); i++)
    {
        std::cout << i << ") " << Potion::names[i] << " costs " << Potion::cost[i] << '\n';
    }    
}