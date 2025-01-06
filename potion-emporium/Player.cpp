#include "Player.h"
#include <iostream>

void Player::printInventory() const 
{
    bool empty{true};
    std::cout << "Your inventory contains:\n";
    //loop through the inventory so we can get his inventory
    for(std::size_t i {0};i < m_inventory.size(); i++)
    {
        if(m_inventory[i] > 0)
        {
            std::cout << m_inventory[i] << "x potion of " << Potion::names[i] << '\n';
            empty = false;
        }
    }

    if(empty)
    {
        std::cout << "No potions.\n";
    }

    std::cout << "You left with " << m_gold << '\n';
}