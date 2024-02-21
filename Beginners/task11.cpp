#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

std::vector<int> read_file(std::string fileName);
void write_file(std::string fileName, std::vector<int> arr);
void helper(std::string str, std::vector<int>& arr);

//Implement Sorting Functions
void BubbleSort(std::vector<int>& arr);
void SelectionSort(std::vector<int>& arr);

//Define Enum and Struct
enum SortingStrategy {
	BUBBLE = 1,
	SELECTION
};

struct SortingOption {
	SortingStrategy choice;
	void(*fptr)(std::vector<int>&);
};

int main()
{
	std::string fileName;
	int choice = 0;
	
	//User Input for File Name and Sorting Selection
	std::cout << "Enter your file name: ";
	std::cin >> fileName;
	
	do {
		std::cout << "For Bubble Sort enter 1, for Selection Sort enter 2: ";
		std::cin >> choice;
	} while (choice != 1 &&  choice != 2);
	
	//Read Array from File
	std::vector<int> arr = read_file(fileName);
	
	//Sorting Option Array
	SortingOption option[2];
	option[0].choice = BUBBLE;
	option[0].fptr = BubbleSort;

	option[1].choice = SELECTION;
	option[1].fptr = SelectionSort;

	//Sort Array
	if (choice == option[0].choice) {
		option[0].fptr(arr);
	} else {
		option[1].fptr(arr);
	}

	//Save Sorted Array to File
	write_file(fileName, arr);
	
	return 0;
}

std::vector<int> read_file(std::string fileName)
{
	std::ifstream read;
	std::string str;
	std::vector<int> arr;

	read.open(fileName);

	if(!read.is_open()) {
		std::cout << "File doesn't exist." << std::endl;
		exit(0);
	}

	while (!read.eof()) {
		std::getline (read, str);
		helper(str, arr);
	}

	read.close();	
	
	return arr;
}

void write_file(std::string fileName, std::vector<int> arr)
{
	std::ofstream write;

	write.open(fileName);

	if(!write.is_open()) {
		std::cout << "I coundn't open the file for writing." << std::endl;
		exit(0);
	}

	for (int val : arr) {
		write << val << " ";
	}

	write.close();
}

void helper(std::string str, std::vector<int>& arr)
{
	std::string tokens;
	std::stringstream ss(str);
	int val = 0;

	while (ss >> tokens) {
		try {
			val = std::stoi(tokens);
			arr.push_back(val);
		} catch (const std::invalid_argument& e) {
			std::cerr << "Error: Invalid argument." << std::endl;
			exit(0);
		} catch (const std::out_of_range& e) {
			std::cerr << "Out of range." << std::endl;
			exit(0);
		}
	}
}

void BubbleSort (std::vector<int>& arr)
{
	for(int j = 0; j < arr.size() - 1; ++j) { 
		bool swap = false;
		
		for (int i = 0; i < arr.size() - 1 - j; ++i) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				swap = true;
			}
		}

		if (swap == false) {
			break;
		}
	}
}

void SelectionSort (std::vector<int>& arr)
{
	for (int i = 0; i < arr.size() - 1; ++i) {
		int min_ind = i;

		for (int j = i + 1; j < arr.size(); ++j) {
			if (arr[j] < arr[min_ind]) {
				min_ind = j;
			}

			if (i != min_ind) {
				std::swap(arr[i], arr[min_ind]);
			}
		}
	}
}

