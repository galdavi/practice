#include "Blackjack.h"
#include "Input.h"

// Funciton intialzes a blackjack game.
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

    while (!m_player.bust())
    {
        char selection{getSelection()};
        if (selection == 'h')
        {
            m_player.hit(m_deck.dealCard());
            std::cout << "You pulled a: " << m_player.cards.back() << '\n';
            if (m_player.bust())
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
            while (!m_dealer.bust())
            {
                // when we stop pulling the game is over so we can now see their cards
                m_gameOver = true;
                displayCards();
                m_dealer.hit(m_deck.dealCard());
                std::cout << "Dealer pulled a: " << m_dealer.cards.back() << '\n';
                if (m_dealer.bust())
                {
                    std::cout << "Dealer bust!\n";
                    displayCards();
                    return true;
                }
            }
            break;
        }
    }
    m_gameOver = true;
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

    std::cout << "=============================================\n";
}

bool Blackjack::playAgain()
{
    std::cout << "Would you like the play again? (Y) Yes or (N) No? ";
    while (true)
    {
        char selection{};
        std::cin >> selection;

        if (!clearFailedExtraction()) // we'll handle error messaging if extraction failed below
            ignoreLine();             // remove any extraneous input (only if extraction succeded)
        switch (selection)
        {
        case 'Y':
        case 'y':
            reset();
            return true;
        case 'N':
        case 'n':
            return false; // Return the entered char to the caller
        default:          // Otherwise tell the user what went wrong
            std::cout << "Oops, that input is invalid.  Please try again: ";
        }
    }
}
//function is revamped so we can have a tie amongst the player and dealer
void Blackjack::gam()
{
    std::cout << "Welcome to Blackjack'\n";

    // Similar to a regular blackjack game the dealer shuffles the cards, and distrbute the cards to the players first then the dealer
    m_deck.shuffle();

    m_player.hit(m_deck.dealCard());
    m_player.hit(m_deck.dealCard());

    m_dealer.hit(m_deck.dealCard());
    m_dealer.hit(m_deck.dealCard());
    displayCards();

    //While player hasnt busted he is able to pull out cards
    while (!m_player.bust())
    {
        char selection{getSelection()};
        if (selection == 'h')
        {
            m_player.hit(m_deck.dealCard());
            std::cout << "You pulled a: " << m_player.cards.back() << '\n';
            
            //if the player has busted he loses and the game is over
            if (m_player.bust())
            {
                std::cout << "You bust\n";
                m_gameOver = true;
                displayCards();
                break;                  //we brek out of the loop so we can display the winner.
            }
            displayCards();             //after we pull a card we display the card
        }
        else
        {
            while (!m_dealer.bust())
            {
                // when we stop pulling the game is over so we can now see their cards
                m_gameOver = true;
                displayCards();
                m_dealer.hit(m_deck.dealCard());
                std::cout << "Dealer pulled a: " << m_dealer.cards.back() << '\n';
                if (m_dealer.bust())
                {
                    std::cout << "Dealer bust!\n";
                    displayCards();
                    break;
                }
            }
        }
    }
    m_gameOver = true;
    displayCards();
    winner();
}

void Blackjack::winner() const
{
    if (m_dealer.score > m_player.score)
    {
        std::cout << "Dealer won.\n";
    }
    else if (m_player.score > m_dealer.score)
    {
        std::cout << "You won\n";
    }
    else
    {
        std::cout << "Tie!\n";
    }
}