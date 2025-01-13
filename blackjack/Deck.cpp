#include <iostream>
#include <algorithm>
#include <cassert>
#include "Random.h"
#include "Deck.h"

Deck::Deck()
{
    size_t deckIndex{0};
    for (auto suit : Card::allSuits)
        for (auto rank : Card::allRanks)
        {
            m_cards[deckIndex] = Card{rank, suit};
            deckIndex++;
        }
}

void Deck::print() const
{
    static int index{0};
    for (const auto &e : m_cards)
        std::cout << e << ' ';
    std::cout << '\n';
}

Card Deck::dealCard()
{
    assert(m_currentCard < s_deckSize && "Ran out of cards!(current card is trying to get a value outside of the deck size)");
    return m_cards[m_currentCard++];
}

void Deck::shuffle()
{
    std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
}