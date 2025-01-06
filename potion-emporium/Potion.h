#ifndef POTION_H
#define POTION_H

#include <array>
#include <string>

namespace Potion
{
    enum Type
    {
        healing,
        mana,
        speed,
        invisibility,
        max_types,
    };

    constexpr std::array cost{20, 30, 12, 50};
    constexpr std::array names{"healing", "mana", "speed", "invisibility"};

    void shop();
    std::string getName();
}

#endif