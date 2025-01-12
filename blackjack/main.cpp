#include <iostream>
#include <array>
#include <cassert>
#include <algorithm>
#include "Random.h"

struct Card
{
    enum Rank
    {
        ace,
        two,
        three,
        four,
        five,
        six,
        seven,
        eight,
        nine,
        ten,
        jack,
        queen,
        king,
        max_ranks
    };

    enum Suit
    {
        clubs,
        diamonds,
        hearts,
        spades,
        max_suits,
    };

    Rank rank{};
    Suit suit{};
    char getRank(Rank rank) const;
    char getSuit(Suit suit) const;
    static constexpr std::array allRanks{ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};
    static constexpr std::array allSuits{clubs, diamonds, hearts, spades};
    friend std::ostream &operator<<(std::ostream &out, const Card &card);

    static_assert(std::size(allRanks) == max_ranks);
    static_assert(std::size(allSuits) == max_suits);
};

char Card::getRank(Rank rank) const
{
    switch (rank)
    {
    case ace:
        return 'A';
    case two:
        return '2';
    case three:
        return '3';
    case four:
        return '4';
    case five:
        return '5';
    case six:
        return '6';
    case seven:
        return '7';
    case eight:
        return '8';
    case nine:
        return '9';
    case ten:
        return 'T';
    case jack:
        return 'J';
    case queen:
        return 'Q';
    case king:
        return 'K';
    default:
        std::cerr << "Error, this shouldnt happen!!\n";
        return 'X';
    }
}

char Card::getSuit(Suit suit) const
{
    switch (suit)
    {
    case clubs:
        return 'C';
    case diamonds:
        return 'D';
    case hearts:
        return 'H';
    case spades:
        return 'S';
    default:
        std::cerr << "Error, this shouldnt happen!!\n";
        return 'X';
    }
}

std::ostream &operator<<(std::ostream &out, const Card &card)
{
    out << card.getRank(card.rank) << card.getSuit(card.suit);
    return out;
}

class Deck
{
public:
    Deck()
    {
        size_t deckIndex{0};
        for(auto suit: Card::allSuits)
            for(auto rank: Card::allRanks)
            {
                m_cards[deckIndex] = Card{rank, suit};
                deckIndex++;
            }
    }
    
    //helper function with print 
    void print()const
    {
        static int index{0};
        for(const auto& e: m_cards)
            std::cout << e << ' ';
        std::cout << '\n';

    }

    Card dealCard()
    {
        assert(m_currentCard < s_deckSize && "Ran out of cards!(current card is trying to get a value outside of the deck size)");
        return m_cards[m_currentCard++];
    }
    void shuffle()
    {
        std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
    }
private:
    static constexpr size_t s_deckSize{52};
    std::array<Card, s_deckSize> m_cards{};
    size_t m_currentCard{0};
};

int main()
{
    Deck deck{};
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    deck.shuffle();
    std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' ' << deck.dealCard() << '\n';

    return 0;
}
