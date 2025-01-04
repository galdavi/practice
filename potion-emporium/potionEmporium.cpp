#include <iostream>
#include <array>
#include <string_view>
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
}

void Potion::shop()
{
    std::cout << "Here is our selection for today:\n";
    for(std::size_t i{0}; i < Potion::max_types; i++)
    {
        std::cout << i << ") " << Potion::names[i] << " costs " << Potion::cost[i] << '\n';
    }    
}

int main()
{
    Potion::shop();
    return 0;
}