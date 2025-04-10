#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <string>

void FIFO(std::vector<int>& refString, int numPageFrames);
void LRU(std::vector<int>& refString, int numPageFrames);
void OPT(std::vector<int>& refString, int numPageFrames);
//int findePageUsedLast(std::vector<int>& refString, std::list<int>& optList, int posInRefString);
void printPageFaults(const std::string& algorithm, int numPageframes, int pageFaults);
void printPageFrame(const std::list<int>& pageFrames) {
	std::cout << '[';
	for (const auto& page : pageFrames) {
		std::cout << page << ' ';
	}
	std::cout << "]\n";
}
int main()
{
	int numPageFrames{ 3 };
	std::vector<int> refString{ 7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1 };
	FIFO(refString, numPageFrames);
	LRU(refString, numPageFrames);
	return 0;
}

void FIFO(std::vector<int>& refString, int numPageFrames)
{
	std::list<int> pageFrame{};
	int pageFaults{ 0 };

	for (const auto& page : refString)
	{

		auto iter{ std::find(pageFrame.begin(), pageFrame.end(), page) };
		// If we dont find the page in the pa
		if (iter == pageFrame.end())
		{
			pageFaults++;
			if (pageFrame.size() >= numPageFrames)
			{
				pageFrame.pop_front();
			}
			pageFrame.push_back(page);
		}
	}
	printPageFaults("FIFO", numPageFrames, pageFaults);
}

void LRU(std::vector<int>& refString, int numPageFrames) {
	std::list<int> pageFrame{};
	int pageFaults{ 0 };

	for (const auto& page : refString) {

		auto iter{ std::find(pageFrame.begin(), pageFrame.end(), page)};
		if (std::find(pageFrame.begin(), pageFrame.end(), page) == pageFrame.end())
		{
			pageFaults++;
			if (pageFrame.size() >= numPageFrames)
			{
				pageFrame.pop_front();
			}
			pageFrame.push_back(page);
		}
		else {
			pageFrame.erase(iter);
			pageFrame.push_back(page);
		}
	}
	printPageFaults("LRU", numPageFrames, pageFaults);
}
void OPT(std::vector<int>& refString, int numPageFrames) {

}

void printPageFaults(const std::string& algorithm, int numPageframes, int pageFaults) {
	std::cout << "Using " << algorithm << " with " << numPageframes << " page frames yielded " << pageFaults << " page faults.\n";
}