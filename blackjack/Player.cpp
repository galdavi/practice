#include "Player.h"

void Player::drawCard(const Card &card)
{
    this->score += card.value();
}