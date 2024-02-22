#include <iostream>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

//abstract base class for serving as the interface for all sorting algorithms
class SortingStrategy {
public:
	virtual void sort(std::vector<int>& vec) = 0;
};

//concrete classes for each sorting algorithm
class BubbleSort : public SortingStrategy {
public:
	void sort(std::vector<int>& vec) override;
};

class SelectionSort : public SortingStrategy {
public:
	void sort(std::vector<int>& vec) override;
};

//FileHandler class responsible for reading an array of integers from a file 
//and writing the sorted array back to a file
class FileHandler {
public:
	void readArrayFromFile();
	void SaveArrayToFile();
	
	void setInFileName();
	void setOutFileName();
	std::vector<int>& getVector();
	
	void helper(std::string str);

private:
	std::ifstream read;
	std::ofstream write;
	std::string inFileName;
	std::string outFileName;
	std::vector<int> vec;
};

//class that encapsulates the application logic
class SortingAplication {
public:
	void setFileNames();
	void setOption();
	void sort();
private:
	int choice;
	SortingStrategy* strategy;
	FileHandler handler;
};


void BubbleSort::sort(std::vector<int>& vec)
{
	for(int j = 0; j < vec.size() - 1; ++j) { 
		bool swap = false;
		
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
		int min_ind = i;

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

	read.open(inFileName);

	if(!read.is_open()) {
		std::cout << "File doesn't exist." << std::endl;
		exit(0);
	}

	while (!read.eof()) {
		std::getline (read, str);
		helper(str);
	}

	read.close();	
}

void FileHandler::SaveArrayToFile()
{
	write.open(outFileName);

	if(!write.is_open()) {
		std::cout << "I coundn't open the file for writing." << std::endl;
		exit(0);
	}

	for (int val : vec) {
		write << val << " ";
	}

	write.close();
}

void FileHandler::setInFileName()
{
	std::cout << "Enter your input file name: ";
	std::cin >> inFileName;
}

void FileHandler::setOutFileName()
{
	std::cout << "Enter your output file name: ";
	std::cin >> outFileName;
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

void SortingAplication::setFileNames()
{
	handler.setInFileName();
	handler.setOutFileName();
}

void SortingAplication::setOption()
{
	do {
		std::cout << "For Bubble Sort enter 1, for Selection Sort enter 2: ";
		std::cin >> choice;
	} while (choice != 1 &&  choice != 2);
		
}
	
void SortingAplication::sort()
{
	BubbleSort bubble;
	SelectionSort selection;

	if (choice == 1) {
		strategy = &bubble;
	} else {
		strategy = &selection;
	}

	handler.readArrayFromFile();
	strategy->sort(handler.getVector());
	handler.SaveArrayToFile();
}








