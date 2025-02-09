#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <string_view>
#include <array>
#include "Potion.h"

class Player
{
public:
    Player() = default;
    Player(std::string_view name, int gold)
        :m_name{name}, m_gold{gold}
        {}
    
    const std::string& getName()const {return m_name;}
    int getGold()const {return m_gold;}
    void printInventory() const;
    void removeGold(int amount);
    void addPotion(int index);
private:
    std::string m_name{""};
    std::array<int, static_cast<std::size_t>(Potion::max_types)> m_inventory{};
    int m_gold{0};
};

#endif