#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include <string>

//Function protoypes.
void FIFO(const std::vector<int>& refString, int numPageFrames);
void LRU(const std::vector<int>& refString, int numPageFrames);
void OPT(const std::vector<int>& refString, int numPageFrames);

//Helper functions prototypes 
int findPageUsedLast(const std::vector<int>& refString, std::list<int>& pageFrames, int posInRefString);
void printPageFaults(const std::string& algorithm, int numPageframes, int pageFaults);

//Used for debugging remove once done
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

//Function implements and displays the FIFO page replacement algorithm results.
void FIFO(const std::vector<int>& refString, int numPageFrames)
{
	//Intialize the variables and container we will be using.
	std::list<int> pageFrame{};
	int pageFaults{ 0 };

	//Use a foreach loop to iterate through the refrence string
	for (const auto& page : refString)
	{
		//Using std::find we look for the current page in the page frame list.
		//std::find returns and iterator pageFrame.end() if we dont find the page.
		auto iter{ std::find(pageFrame.begin(), pageFrame.end(), page) };
		
		
		if (iter == pageFrame.end())
		{
			//Page fault occurred
			pageFaults++;
			
			//If the max size of the page frame was reached, pop front of list
			if (pageFrame.size() >= numPageFrames)
			{
				pageFrame.pop_front();
			}
			pageFrame.push_back(page);
		}
	}
	//Display Results
	printPageFaults("FIFO", numPageFrames, pageFaults);
}

//Function implements and the displays the LRU page replacement algorithm results
void LRU(const std::vector<int>& refString, int numPageFrames) {
	
	//Intialize the container and variable we will be using
	std::list<int> pageFrame{};
	int pageFaults{ 0 };

	//Use a foreach loop to iterate through the refrence string
	for (const auto& page : refString) {

		//Using std::find we look for the current page in the page frame list.
		//std::find returns and iterator pageFrame.end() if we dont find the page.
		auto iter{ std::find(pageFrame.begin(), pageFrame.end(), page)};

		if (iter == pageFrame.end())
		{
			//Page fault occured
			pageFaults++;

			//If the max size of the pageFrame was reached, pop front of list and push back the new page
			if (pageFrame.size() >= numPageFrames)
			{
				pageFrame.pop_front();
			}
			pageFrame.push_back(page);
		}
		else {
			//Page hit occured remove the page from the current position and place on the back of the list. 
			pageFrame.erase(iter);
			pageFrame.push_back(page);
		}
	}

	//Display results.
	printPageFaults("LRU", numPageFrames, pageFaults);
}

void OPT(const std::vector<int>& refString, int numPageFrames) {
	
	//Intialize the variable and container we will be using.
	std::list<int> pageFrames{};
	int pageFaults{0};

	//Since the postion of the refrence string is needed, we use a for loop to cycle through the reference string.
	for(int index{0}; index < refString.size(); index++){

		//Using std::find we look for the current page in the page frame list.
		//std::find returns and iterator pageFrame.end() if we dont find the page.
		auto iter{std::find(pageFrames.begin(), pageFrames.end(), refString[index])};

		if(iter == pageFrames.end()){
			//Page Fault occured
			pageFaults++;

			if(pageFrames.size() >= numPageFrames){
				//If our page frame size has reached its max size find the last used page.
				int pageReplacement{findPageUsedLast(refString, pageFrames, index)};
				pageFrame[pageReplacement] = refString[index];
			} else{
				pageFrame.push_back(refString[index]);
			}
		}

	}
}

int findPageUsedLast(const std::vector<int>& refString, std::list<int>& pageFrames, int posInRefString){

}

void printPageFaults(const std::string& algorithmName, int numPageframes, int pageFaults) {
	std::cout << "Using " << algorithmName << " with " << numPageframes << " page frames yielded " << pageFaults << " page faults.\n";
}