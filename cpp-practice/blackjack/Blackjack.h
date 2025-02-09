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
    void reset() {*this = {};};
    bool playAgain();
    void winner() const ;
    void gam();
private:
    Player m_player{};
    Player m_dealer{};
    Deck m_deck{};

    bool m_gameOver{false}; //variable is used so that the ui display settings
};

#endif