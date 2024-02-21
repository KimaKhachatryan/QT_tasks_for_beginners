#include <iostream>
#include <fstream>
#include <string>

int main()
{
	std::ofstream write;

	write.open("Names.txt");

	if(!write.is_open()) {
		std::cout << "I coundn't open the file for writing." << std::endl;
		exit(0);
	}

	write << "Joe" << "\n"
		  << "Ann" << "\n"
		  << "David" << "\n"
		  << "Jasmin" << "\n"
		  << "Mark" << std::endl;

	write.close();

	std::ifstream read;
	std::string str;

	read.open("Names.txt");

	if(!read.is_open()) {
		std::cout << "I coundn't open the file for reading." << std::endl;
		exit(0);
	}

	while (!read.eof()) {
		std::getline (read, str);
		std::cout << str << std::endl;
	}

	read.close();
	return 0;
}
