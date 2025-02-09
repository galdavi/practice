#ifndef DECK_h
#define DECK_h

#include <array>
#include "Card.h"

class Deck
{
public:
    Deck();
    // helper function with print
    void print() const;
    Card dealCard();

    void shuffle();

private:
    static constexpr size_t s_deckSize{52};
    std::array<Card, s_deckSize> m_cards{};
    size_t m_currentCard{0};
};

#endif