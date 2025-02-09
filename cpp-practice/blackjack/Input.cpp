#include <iostream>
#include <limits>

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

char getSelection()
{
    std::cout << "(h) to hit, or (s) to stand:";

    while (true)
    {
        char selection{};
        std::cin >> selection;

        if (!clearFailedExtraction()) // we'll handle error messaging if extraction failed below
            ignoreLine();             // remove any extraneous input (only if extraction succeded)
        switch (selection)
        {
        case 'h':
        case 's':
            return selection; // Return the entered char to the caller
        default:              // Otherwise tell the user what went wrong
            std::cout << "Oops, that input is invalid.  Please try again: ";
        }
    }
}