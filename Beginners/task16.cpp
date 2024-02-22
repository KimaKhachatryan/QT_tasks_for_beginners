#include "task16.h"

int main()
{
	int choice = 0;
	std::string inFileName;
	std::string outFileName;
	
	std::cout << "Enter your input file name: ";
	std::cin >> inFileName;
	
	std::cout << "Enter your output file name: ";
	std::cin >> outFileName;
	
	do {
		std::cout << "For Bubble Sort enter 1, for Selection Sort enter 2: ";
		std::cin >> choice;
	} while (choice != 1 &&  choice != 2);
	
	SortingAplication my_option(choice, inFileName, outFileName);
	
	my_option.sort();

	return 0;
}

