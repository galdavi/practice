#include <iostream>
#include <vector>
#include <algorithm>

void printVector(const std::vector<int> &coins)
{
    for (const auto &e : coins)
    {
        std::cout << "coin: " << e << '\n';
    }
}
int main()
{
    std::vector<int> coins1 = {1, 2, 5};
    const int amount2 = 3;
    //std::cout << coins1.size();

    std::vector<std::vector<int>> temp;
    int row{2};
    int col{4};
    temp.resize(2);
    //std::cout << temp.size();
    for(auto& e: temp)
    {
        e.resize(4);
    }
    for(int i{0}; i < row; i++)
    {
        for(int j{0}; j < col; j++)
        {
            std::cout << temp[i][j]<< ' ';
        }
        std::cout << '\n';
    }
//     printVector(coins1);
//     std::sort(coins1.begin(), coins1.end(),
//               [](int a, int b)
//               {
//                   return a > b;
//               });
//  printVector(coins1);
    return 0;
}
