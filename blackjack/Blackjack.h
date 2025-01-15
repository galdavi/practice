#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "Player.h"
#include "Deck.h"
class Blackjack
{
public:
    Blackjack() = default;

    bool game();
    void displayCards() const;
    void gameOver() const;
    bool playAgain() const;
private:
    Player m_player{};
    Player m_dealer{};
    Deck m_deck{};

    const int m_bustValue{21};
    bool m_gameOver{false};
};

#endif