#include <iostream>

int main()
{
	std::string str1;
	std::string str2;

	std::cout << "Enter string 1: ";
	std::getline (std::cin, str1);

	std::cout << "Enter string 2: ";
	std::getline (std::cin, str2);

	std::cout << "The lenght of string 1 = " << str1.length() << std::endl;
	std::cout << "The lenght of string 2 = " << str2.length() << std::endl;

	std::cout << "Concatenated string: " << str1 + str2 << std::endl;
	return 0;
}
