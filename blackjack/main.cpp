#include <iostream>
#include "Blackjack.h"

int main()
{
    Blackjack blackjack{};


        if (blackjack.game())
        {
            std::cout << "Winner, Winner, Chicken Dinner'\n";
        }
        else
        {
            std::cout << "You lose. \nLoser, Loser, Shitty User'\n";
        }

    return 0;
}
