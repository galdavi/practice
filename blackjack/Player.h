#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <vector>

struct Player
{
    void hit(const Card &card);
    void showCards() const;

    bool bust() const;
    
    int score{0};
    int bustValue{21};
    std::vector<Card> cards{};

};
#endif