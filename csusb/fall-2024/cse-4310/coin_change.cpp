/*
David Solis Gallo
005286979
CSE 4310
Dr. Kim

Program solves the making change problem using greedy algorithm and dynamic programming.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int greedy_algorithm(vector<int> coins, int amount)
{
  if (amount == 0)
    return 0;
  // We use std::sort and a lambda to sort the coins in descending order. Adding this so it can
  // work with coins that are unsorted.
  sort(coins.begin(), coins.end(),
       [](int a, int b)
       {
         return a > b;
       });

  int answer = 0;
  // We go through all the coins we have and see we can substract our current coin from the amount
  for (size_t i{0}; i < coins.size();)
  {
    if (amount - coins[i] >= 0)
    {
      amount -= coins[i];
      answer++; // If we can substract from our amount we increment the coins we need
    }
    else
      i++;
  }
  if (amount > 0) // If we go through our whole coins with out being able to subtract an exact change we return -1.
    return -1;

  return answer;
}
// Function gets the amount of coins needed for the first row of coins
int getAmount(int coin, int amount)
{
  // If the amount is zero or less than the available coins then we return 1.

  if (amount == 0 || amount < coin)
    return 0;
  int coinsNeeded{0};

  // We keep subtracting amount by the current coin
  while (amount > 0)
  {
    amount -= coin;
    coinsNeeded++;
  }
  // If we arent able to make up change with the current coin we have we return -1 else we return the coins needed to make change
  if (amount < 0)
    return -1;
  else
    return coinsNeeded;
}
int dynamic_programming(vector<int> &coins, int amount)
{
  // If our amount is less than or equal to zero we return 0
  if (amount <= 0)
    return 0;
  // We make our dynamic table with a 2d vector.
  vector<vector<int>> table(coins.size(), vector<int>(amount + 1));
  bool firsRow{true};
  int answer = 0;

  for (std::size_t i{0}; i < coins.size(); i++)
  {
    for (std::size_t j{0}; j <= amount; j++)
    {
      // In the first row we get the coins we need by calling the getAmount function
      if (firsRow)
      {
        table[i][j] = getAmount(coins[i], j);
        continue;
      }
      // If the amount we have is less than the current coin we copy the row above
      if (j < coins[i])
      {
        table[i][j] = table[i - 1][j];
      }
      else
      {
        // Since its not less we compare the value n coins away + 1 and the value above
        // We then get the min of the two values and add it to our dynamic table
        table[i][j] = min((table[i][j - coins[i]] + 1), table[i - 1][j]);
      }
    }
    // After our first iteration we wont be on the first row
    firsRow = false;
  }
  // We return the value at the very corner of the dynamic table.
  return table[coins.size() - 1][static_cast<size_t>(amount)];
}
// DO NOT modiry the function main()

int main()
{

  vector<int> coins1 = {1, 2, 5}; // 5 + 5 + 1
  const int amount1 = 11;

  vector<int> coins2 = {2};
  const int amount2 = 3;

  vector<int> coins3 = {1};
  const int amount3 = 0;

  vector<int> coins4 = {1, 4, 6};
  const int amount4 = 8;

  cout << greedy_algorithm(coins1, amount1) << endl; // 3 Expected
  cout << greedy_algorithm(coins2, amount2) << endl; // -1 Expected
  cout << greedy_algorithm(coins3, amount3) << endl; // 0 Expected
  cout << greedy_algorithm(coins4, amount4) << endl; // 3 Expected

  cout << "------------------" << endl;
  cout << dynamic_programming(coins1, amount1) << endl; // 2 Expected
  cout << dynamic_programming(coins2, amount2) << endl; // -1 Expected
  cout << dynamic_programming(coins3, amount3) << endl; // 0 Expected
  cout << dynamic_programming(coins4, amount4) << endl; // 2 Expected

  return 0;
}