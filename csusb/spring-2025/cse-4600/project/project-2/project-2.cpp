#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <string>

// Page replacement algorithm function protoypes.
void FIFO(const std::vector<int> &refString, int numPageFrames);
void LRU(const std::vector<int> &refString, int numPageFrames);
void OPT(const std::vector<int> &refString, int numPageFrames);

// Helper functions prototypes
int findPageUsedLast(const std::vector<int> &refString, const std::list<int> &pageFrames, int posInRefString);
void printPageFaults(const std::string &algorithm, int numPageframes, int pageFaults);
std::vector<int> getReferenceString();
std::vector<int> simplifyRefString(std::vector<int>& refString);
// Used for debugging remove once done
void printPageFrames(const std::list<int> &pageFrames)
{
	std::cout << '[';
	for (const auto &page : pageFrames)
	{
		std::cout << page << ' ';
	}
	std::cout << "]\n";
}

void printRefString(const std::vector<int> &refString)
{
	std::cout << '{';
	for (const auto &page : refString)
	{
		std::cout << page << ' ';
	}
	std::cout << "}\n";
}
int main()
{
	std::cout << "Enter the number of page frames: ";
	int numPageFrames{};
	std::cin >> numPageFrames;
	std::vector<int> refString{getReferenceString()};

	std::cout << "Your reference string:\n";
	printRefString(refString);
	// Call the page replacement algorithms.
	//FIFO(refString, numPageFrames);
	//LRU(refString, numPageFrames);
	//OPT(refString, numPageFrames);
	return 0;
}

// Function implements and displays the FIFO page replacement algorithm results.
void FIFO(const std::vector<int> &refString, int numPageFrames)
{
	// Intialize the variables and container we will be using.
	std::list<int> pageFrames{};
	int pageFaults{0};

	// Use a foreach loop to iterate through the refrence string
	for (const auto &page : refString)
	{
		// Using std::find we look for the current page in the page frame list.
		// std::find returns and iterator pageFrame.end() if we dont find the page.
		auto iter{std::find(pageFrames.begin(), pageFrames.end(), page)};

		if (iter == pageFrames.end())
		{
			// Page fault occurred
			pageFaults++;

			// If the max size of the page frame was reached, pop front of list
			if (pageFrames.size() >= numPageFrames)
			{
				pageFrames.pop_front();
			}
			pageFrames.push_back(page);
		}
	}
	// Display Results
	printPageFaults("FIFO", numPageFrames, pageFaults);
}

// Function implements and the displays the LRU page replacement algorithm results
void LRU(const std::vector<int> &refString, int numPageFrames)
{

	// Intialize the container and variable we will be using
	std::list<int> pageFrames{};
	int pageFaults{0};

	// Use a foreach loop to iterate through the refrence string
	for (const auto &page : refString)
	{

		// Using std::find we look for the current page in the page frame list.
		// std::find returns and iterator pageFrame.end() if we dont find the page.
		auto iter{std::find(pageFrames.begin(), pageFrames.end(), page)};

		if (iter == pageFrames.end())
		{
			// Page fault occurred
			pageFaults++;

			// If the max size of the pageFrame was reached, pop front of list and push back the new page
			if (pageFrames.size() >= numPageFrames)
			{
				pageFrames.pop_front();
			}
			pageFrames.push_back(page);
		}
		else
		{
			// Page hit occurred remove the page from the current position and place on the back of the list.
			pageFrames.erase(iter);
			pageFrames.push_back(page);
		}
	}

	// Display results.
	printPageFaults("LRU", numPageFrames, pageFaults);
}

void OPT(const std::vector<int> &refString, int numPageFrames)
{

	// Intialize the variable and container we will be using.
	std::list<int> pageFrames{};
	int pageFaults{0};

	// Since the postion of the refrence string is needed, we use a for loop to cycle through the reference string.
	for (int index{0}; index < refString.size(); index++)
	{
		// Using std::find we look for the current page in the page frame list.
		// std::find returns and iterator pageFrame.end() if we dont find the page.
		auto iter{std::find(pageFrames.begin(), pageFrames.end(), refString[index])};

		if (iter == pageFrames.end())
		{
			// Page Fault occured
			pageFaults++;

			if (pageFrames.size() >= numPageFrames)
			{
				// If our page frame size has reached its max size find the last used page and replace it.
				int pageReplacement{findPageUsedLast(refString, pageFrames, index)};
				auto replacementIter{std::find(pageFrames.begin(), pageFrames.end(), pageReplacement)};
				*replacementIter = refString[index];
			}
			else
			{
				pageFrames.push_back(refString[index]);
			}
		}
	}

	printPageFaults("OPT", numPageFrames, pageFaults);
}

int findPageUsedLast(const std::vector<int> &refString, const std::list<int> &pageFrames, int posInRefString)
{
	int longestDistance{0};
	int replacementCandidate{0};

	for (const auto &page : pageFrames)
	{
		bool seen{false};
		int distance{0};

		for (int i{posInRefString + 1}; i < refString.size(); i++)
		{
			distance++;

			// If we find the page in our remaining refrence string and the current distance is greater than our longest distance.
			if (page == refString[i])
			{
				if (distance > longestDistance)
				{
					replacementCandidate = page;
					longestDistance = distance;
				}
				seen = true;
				break;
			}
		}

		// if we went through the whole refrence without seeing the page its the best candidate for replacement.
		if (!seen)
		{
			return page;
		}
	}

	return replacementCandidate;
}

// Function prints the result of the fucntion.
void printPageFaults(const std::string &algorithmName, int numPageframes, int pageFaults)
{
	std::cout << "Using " << algorithmName << " with " << numPageframes << " page frames yielded " << pageFaults << " page faults.\n";
}

std::vector<int> getReferenceString()
{
	std::vector<int> refString;
	
	std::cout << "Enter the page number(-1 to stop):\n";
	bool inputComplete{false};

	while (!inputComplete)
	{
		int page{};
		std::cout << "Enter a page number: ";
		std::cin >> page;

		if(page == -1){
			inputComplete = true;
		}else{
		refString.push_back(page);
	}
	}
	
	return refString;
	
}