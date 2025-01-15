#include "Blackjack.h"
#include "Input.h"

bool Blackjack::game()
{
    std::cout << "Welcome to Blackjack'\n";

    // Similar to a regular blackjack game the dealer shuffles the cards, and distrbute the cards to the players first then the dealer
    m_deck.shuffle();

    m_player.hit(m_deck.dealCard());
    m_player.hit(m_deck.dealCard());

    m_dealer.hit(m_deck.dealCard());
    m_dealer.hit(m_deck.dealCard());
    displayCards();

    while(m_player.score <= m_bustValue)
    {
        char selection{getSelection()};
        if(selection == 'h')
        {
            m_player.hit(m_deck.dealCard());
            std::cout << "You pulled a: " << m_player.cards.back() << '\n';
            if(m_player.score > m_bustValue)
            {
                std::cout << "You bust\n";
                m_gameOver = true;
                displayCards();
                return false;
            }
            displayCards();
        }
        else
        {
            while(m_dealer.score < m_bustValue)
            {
                m_dealer.hit(m_deck.dealCard());
                std::cout << "Dealer pulled a: " << m_dealer.cards.back() << '\n';
                if(m_dealer.score > m_bustValue)
                {
                    std::cout << "Dealer bust!\n";
                    m_gameOver = true;
                    displayCards();
                    return true;
                }
            }
            break;
        }
    }
    m_gameOver =true;
    displayCards();
    return m_player.score > m_dealer.score;
}

void Blackjack::displayCards() const
{
    std::cout << "Dealer is showing: ";
    if (!m_gameOver)
    {
        std::cout << m_dealer.cards[0] << " [ ]\n";
    }
    else
    {
        m_dealer.showCards();
    }
    std::cout << "You are showing: ";
    m_player.showCards();
}
