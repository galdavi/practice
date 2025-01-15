#include "Player.h"
#include <iostream>

void Player::hit(const Card &card)
{
    score += card.value();
    cards.push_back(card);
}

void Player::showCards() const
{
    for (const auto &card : this->cards)
    {
        std::cout << card << ' ';
    }
    std::cout << " --- Score: " << score << '\n';
}