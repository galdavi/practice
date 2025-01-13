#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"

struct Player
{
    void drawCard(const Card &card);
    int score{0};
};
#endif