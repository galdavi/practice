#include <iostream>
#include "Blackjack.h"

int main()
{
    Blackjack blackjack{};

    do
    {
        blackjack.gam();

    } while (blackjack.playAgain());
    
    return 0;
}
