/*
This software is based on chapter 17 of learncpp.com. It utilzes the random library from the website and showcases
header mangement mild improvement would be to seperate the functions


*/
#include <iostream>
#include "Random.h"
#include "Potion.h"
#include "Player.h"

//Namespace is used to set the setting of the shop emporium
namespace Settings
{
    constexpr int minGold{20};
    constexpr int maxGold{200};
}

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns true if extraction failed, false otherwise
bool clearFailedExtraction()
{
    // Check for failed extraction
    if (!std::cin) // If the previous extraction failed
    {
        if (std::cin.eof()) // If the stream was closed
        {
            std::exit(0); // Shut down the program now
        }

        // Let's handle the failure
        std::cin.clear(); // Put us back in 'normal' operation mode
        ignoreLine();     // And remove the bad input

        return true;
    }

    return false;
}
std::string getName()
{
    std::string name{};
    std::cout << "Enter name: ";
    std::cin >> name;

    return name;
}
char getSelection()
{
    std::cout << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";

    while (true)
    {
        char selection{};
        std::cin >> selection;
        if (!clearFailedExtraction()) // we'll handle error messaging if extraction failed below
            ignoreLine();             // remove any extraneous input (only if extraction succeded)
        switch (selection)
        {
        case '0':
        case '1':
        case '2':
        case '3':
        case 'q':
            return selection; // Return the entered char to the caller
        default:              // Otherwise tell the user what went wrong
            std::cout << "Oops, that input is invalid.  Please try again: ";
        }
    }
}
void sim()
{
    std::cout << "Welcome to Roscoe's potion emporium!\n";
    std::string name{getName()};
    Player player{name, Random::get(Settings::minGold, Settings::maxGold)};
    std::cout << "Hello, " << player.getName() << " you have " << player.getGold() << " gold.\n";

    while (true)
    {
        Potion::shop();
        char selection{getSelection()};

        if ((selection == 'q') || (player.getGold() == 0))
            break;
        std::size_t index{static_cast<std::size_t>(selection) - 48};

        if (Potion::cost[index] > player.getGold())
        {
            std::cout << "You can not afford that.";
        }
        else
        {
            player.addPotion(index);
            std::cout << Potion::cost[index] << '\n';
            player.removeGold(Potion::cost[index]);
            std::cout << "You purchased a potion of " << Potion::names[index] << ". You have " << player.getGold() << " gold left.\n";
        }
    }
    player.printInventory();
    
    std::cout << "You left with " << player.getGold() << " gold.\n";
}

int main()
{
    sim();
    return 0;
}