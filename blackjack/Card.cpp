#include "Card.h"

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

int Card::value() const
{
    switch (this->rank)
    {
    case ace:
        return 1;
    case two:
        return 2;
    case three:
        return 3;
    case four:
        return 4;
    case five:
        return 5;
    case six:
        return 6;
    case seven:
        return 7;
    case eight:
        return 8;
    case nine:
        return 9;
    case ten:
    case jack:
    case queen:
    case king:
        return 10;
    default:
        std::cerr << "Error, this shouldnt happen!!\n";
        return 0;
    }
}