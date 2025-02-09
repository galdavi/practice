#include <iostream>
#include <algorithm>
#include <cassert>
#include "Random.h"
#include "Deck.h"


//Constructors so we can intialize our deck
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

//Function prints the whole entire deck
void Deck::print() const
{
    for (const auto &card : m_cards)
        std::cout << card << ' ';
    std::cout << '\n';
}

//Function returns a card from the top of the deck.
Card Deck::dealCard()
{
    assert(m_currentCard < s_deckSize && "Ran out of cards!(current card is trying to get a value outside of the deck size)");
    return m_cards[m_currentCard++];
}

//Funciton utilizes the Random.h and algo library to shuffle the cards in the deck.
void Deck::shuffle()
{
    std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
}