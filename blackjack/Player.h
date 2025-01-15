#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <vector>

struct Player
{
    void hit(const Card &card);
    void showCards() const;
    int score{0};
    std::vector<Card> cards{};

};
#endif