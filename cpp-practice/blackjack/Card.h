#ifndef CARD_h
#define CARD_h

#include <array>
#include <iostream>

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
    int value() const;

    static constexpr std::array allRanks{ace, two, three, four, five, six, seven, eight, nine, ten, jack, queen, king};
    static constexpr std::array allSuits{clubs, diamonds, hearts, spades};
    friend std::ostream &operator<<(std::ostream &out, const Card &card);

    static_assert(std::size(allRanks) == max_ranks);
    static_assert(std::size(allSuits) == max_suits);
};
#endif