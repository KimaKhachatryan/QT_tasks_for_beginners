#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

//abstract base class for serving as the interface for all sorting algorithms
class SortingStrategy {
public:
	virtual ~SortingStrategy() = default;
	virtual void sort(std::vector<int>& vec) = 0;
};

//concrete classes for each sorting algorithm
class BubbleSort : public SortingStrategy {
public:
	BubbleSort() : swap{false} {}
	~BubbleSort() override {
		swap = false;
	}
	
	void sort(std::vector<int>& vec) override;
private:
	bool swap;
};

class SelectionSort : public SortingStrategy {
public:
	SelectionSort() : min_ind {0} {}
	~SelectionSort() override {
		min_ind = 0; 
	}
	
	void sort(std::vector<int>& vec) override;
private:
	int min_ind;
};

//FileHandler class responsible for reading an array of integers from a file 
//and writing the sorted array back to a file
class FileHandler {
public:
	FileHandler(std::string inName, std::string outName) {
		read.open(inName);

		if(!read.is_open()) {
			std::cout << "File doesn't exist." << std::endl;
			exit(0);
		}
		
		write.open(outName);

		if(!write.is_open()) {
			std::cout << "I coundn't open the file for writing." << std::endl;
			exit(0);
		}
	}
	
	~FileHandler() {
		read.close();
		write.close();
	}

	void readArrayFromFile();
	void SaveArrayToFile();
	
	std::vector<int>& getVector();
	
	void helper(std::string str);
private:
	std::ifstream read;
	std::ofstream write;
	std::vector<int> vec;
};

//class that encapsulates the application logic
class SortingAplication {
public:
	SortingAplication(int user_choice, std::string inFileName, std::string outFileName) : choice {user_choice}, handler(inFileName, outFileName) {
		if (choice == 1) {
			strategy = &bubble;
		} else {
			strategy = &selection;
		}
	}
	
	void sort();
private:
	int choice;
	BubbleSort bubble;
	SelectionSort selection;
	SortingStrategy* strategy;
	FileHandler handler;
};

void BubbleSort::sort(std::vector<int>& vec)
{
	for(int j = 0; j < vec.size() - 1; ++j) { 
		swap = false;
		
		for (int i = 0; i < vec.size() - 1 - j; ++i) {
			if (vec[i] > vec[i + 1]) {
				std::swap(vec[i], vec[i + 1]);
				swap = true;
			}
		}

		if (swap == false) {
			break;
		}
	}
}

void SelectionSort::sort(std::vector<int>& vec)
{
	for (int i = 0; i < vec.size() - 1; ++i) {
		min_ind = i;

		for (int j = i + 1; j < vec.size(); ++j) {
			if (vec[j] < vec[min_ind]) {
				min_ind = j;
			}

			if (i != min_ind) {
				std::swap(vec[i], vec[min_ind]);
			}
		}
	}
}

void FileHandler::readArrayFromFile()
{
	std::string str;

	while (!read.eof()) {
		std::getline (read, str);
		helper(str);
	}
}

void FileHandler::SaveArrayToFile()
{
	for (int val : vec) {
		write << val << " ";
	}
}


std::vector<int>& FileHandler::getVector()
{
	return vec;
}

void FileHandler::helper(std::string str)
{
	std::string tokens;
	std::stringstream ss(str);
	int val = 0;

	while (ss >> tokens) {
		try {
			val = std::stoi(tokens);
			vec.push_back(val);
		} catch (const std::invalid_argument& e) {
			std::cerr << "Error: Invalid argument." << std::endl;
			exit(0);
		} catch (const std::out_of_range& e) {
			std::cerr << "Out of range." << std::endl;
			exit(0);
		}
	}
}

	
void SortingAplication::sort()
{
	handler.readArrayFromFile();
	strategy->sort(handler.getVector());
	handler.SaveArrayToFile();
}


