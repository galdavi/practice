#include <iostream>
#include <vector>

void selectionSort(std::vector<int>& arr)
{
    //If the array is empty or a single  we exit the function.
    if(arr.empty() || arr.size() == 1)
        return;

    size_t smallestIndex{0}; //We assume the smallest value is the first value in the array.

    for(size_t currentIndex{}; currentIndex < arr.size(); index++)
    {
        if( > arr[index])
        {
            smallestValue = arr[index];
            std::swap(arr[])
        }
    }
}


//Helper function so we can print the array.
void printArr(const std::vector<int>& arr)
{
    bool comma{false};

    std::cout << "{";
    for(const auto element: arr)
    {
        if(comma)
            std::cout << ", ";
        
        std::cout << element; 

        comma = true;
    }

    std::cout << "}\n";
}
int main()
{
    std::vector arr{30,50,20,10,40};
    printArr(arr);
    
    return 0;
}