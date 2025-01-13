#include <iostream>
#include "Deck.h"
#include "Player.h"

bool blackjack(Player &player, Player &dealer)
{
    Deck deck{};
    deck.shuffle();
    dealer.drawCard(deck.dealCard());

    std::cout << "Dealer is showing: " << dealer.score << '\n';
    player.drawCard(deck.dealCard());
    player.drawCard(deck.dealCard());
    std::cout << "You are showing: " << player.score << '\n';

    if (player.score > dealer.score)
        return true;
    else
        return false;
}

int main()
{
    Player player{};
    Player dealer{};
    bool win{blackjack(player, dealer)};

    if (win)
    {
        std::cout << "Winner, Winner, Chicken Dinner'\n";
    }
    else
    {
        std::cout << "Loser, Loser, Shitty User'\n";
    }
    return 0;
}
