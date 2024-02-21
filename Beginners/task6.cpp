#include <iostream>

int main()
{
	int num = 0;
	std::cout << "Enter the value of number: ";
	std::cin >> num;

	int* pi = &num;
	int& ri = num;

	*pi *= 2;
	std::cout << "The number is increased by 2 times using pointer to it\n" << "Number = " << num << std::endl;

	ri *= 3;  
	std::cout << "Now the number is increased by 3 times using reference to it\n" << "Number = " << num << std::endl;

	return 0;
}
