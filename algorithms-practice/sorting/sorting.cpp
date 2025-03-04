#include <iostream>
#include <vector>
#include <algorithm>

// The function uses selection sort, to sort the array in ascending order.
// The bool parameter determines whether we sort it in ascending or descending order.
void selectionSort(std::vector<int> &vect, bool ascending)
{
    // If the vector/array is empty then dont sort and just return.
    if (vect.empty() || vect.size() == 1)
        return;

    if (ascending)
    {
        // We go through the whole vector checking if we can find the smallest value. We skip the last one because it will already be sorted.
        for (size_t startIndex{0}; startIndex < vect.size() - 1; ++startIndex)
        {
            // Assume the starting index is the smallest value.
            size_t smallestIndex{startIndex};

            // We then look through the whole vector to see if there is a smaller value
            for (size_t currentIndex{smallestIndex + 1}; currentIndex < vect.size(); ++currentIndex)
            {
                // If there is a smaller value we set that value as the smallest index.
                if (vect[smallestIndex] > vect[currentIndex])
                {
                    smallestIndex = currentIndex;
                }
            }

            // since we went through the whole vector we now swap it.
            std::swap(vect[smallestIndex], vect[startIndex]);
        }
    }
    else
    {
        // for descending is the same thing just different variable names and switching from greater than to lesser than

        // We go through the whole vector checking if we can find the largest value. We skip the last one because it will already be sorted.
        for (size_t startIndex{0}; startIndex < vect.size() - 1; ++startIndex)
        {
            // Assume the starting index is the largest value.
            size_t largestIndex{startIndex};

            // We then look through the whole vector to see if there is a larger value
            for (size_t currentIndex{largestIndex + 1}; currentIndex < vect.size(); ++currentIndex)
            {
                // If there is a larger value we set that value as the smallest index.
                if (vect[largestIndex] < vect[currentIndex])
                {
                    largestIndex = currentIndex;
                }
            }

            // since we went through the whole vector we now swap it.
            std::swap(vect[largestIndex], vect[startIndex]);
        }
    }
}

void printVector(const std::vector<int> &vect)
{
    bool comma{false};
    std::cout << "{";

    for (const int &number : vect)
    {
        if (comma)
        {
            std::cout << ", ";
        }

        std::cout << number;

        comma = true;
    }

    std::cout << "}\n";
}

void bubbleSort(std::vector<int> &vect)
{
    // we need to go through the whole entire array in order to check every single value.
    for (size_t iteration{0}; iteration < vect.size() - 1; iteration++)
    {

        bool swap{false};
        // This loops checks and compares the values in ascending order. We make sure we dont go past the vector size by subtractin it by one
        
        for (size_t currentValue{0}; currentValue < vect.size() - 1; currentValue++)
        {
            size_t adjacentValue{currentValue + 1};

            // If the current value is greater than the adjacent value we swap it and keep track of the swap.
            if (vect[currentValue] > vect[adjacentValue])
            {
                std::swap(vect[currentValue], vect[adjacentValue]);
                swap = true;
            }
        }
        // If we go throught the whole array without swapping we terminate early.
        if (!swap)
        {
            std::cout << "Early termination in iteration: " << iteration + 1 << '\n';
            return;
        }
    }
}

// Function sorts a vector.
// I implemented it correctly just need to move my variables around as some of them are unecessary
void insertionSort(std::vector<int> &vect)
{
    // We start at index 1 because index 0 is the sorted portion of the vector
    // Every single iteration we increment because the sorted portion of our vector increases
    for (size_t currentIndex{1}; currentIndex < vect.size(); currentIndex++)
    {
        int currentElement{vect[currentIndex]};
        size_t sortedIndex{currentIndex - 1};

        // We continously compare the current index to the previous index. The loop ends once we swap everything.
        while (currentElement < vect[sortedIndex] && sortedIndex >= 0)
        {
            vect[sortedIndex + 1] = vect[sortedIndex];
            --sortedIndex;
        }

        vect[sortedIndex + 1] = currentElement;
    }
}

void mergeSort(std::vector<int> &vect)
{
}
int main()
{
    std::vector<int> vect{6, 3, 2, 9, 7, 1, 5, 4, 8};
    std::cout << "Before bubble sort: ";
    printVector(vect);
    insertionSort(vect);

    std::cout << "After bubble sort: ";
    printVector(vect);

    return 0;
}