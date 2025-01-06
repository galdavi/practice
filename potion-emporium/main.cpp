#include "Random.h"
#include "Potion.h"
#include <iostream>

std::string getName()
{
    std::string name{};
    std::cout << "Enter name: ";
    std::cin >> name;

    return name;
}

int main()
{
    Potion::shop();
    return 0;
}