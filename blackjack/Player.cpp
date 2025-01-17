#include "Player.h"
#include <iostream>

//Function gets a card and places it into the vector of card the player has
void Player::hit(const Card &card)
{
    // If we pull an ace and is advantagous towards the player we use it as a 1 instead of eleven
    if (card.rank == Card::Rank::ace && (score += card.value() == bustValue))
    {
        score += 11;
    }
    else
    {
        score += card.value();
    }
    cards.push_back(card);
}

//Function shows the cards and the score the player has
void Player::showCards() const
{
    for (const auto &card : cards)
    {
        std::cout << card << ' ';
    }
    std::cout << " --- Score: " << score << '\n';
}

//Function returns wheter or not the player has busted, returns true if they have false otherwise.
bool Player::bust() const
{
    if (score > bustValue)
        return true;
    else
        return false;
}
