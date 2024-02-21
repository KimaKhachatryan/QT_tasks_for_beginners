#include <iostream>

int main()
{
	int number = 0;

	std::cout << "Enter your number: ";
	std::cin >> number;

	if (number == 0) {
		std::cout << "Your number is equal to 0." << std::endl;
		std::cout << "Grade E!" << std::endl;
	} else if (number < 0) {
		std::cout << "Your number is negativ." << std::endl;
	} else {
		std::cout << "Your number is positiv." << std::endl;
		switch(number)
		{
			case 90 ... 100:
				std::cout << "Grade A!" << std::endl;
				break;
			case 80 ... 89:
				std::cout << "Grade B!" << std::endl;
				break;
			case 70 ... 79:
				std::cout << "Grade C!" << std::endl;
				break;
			case 60 ... 69:
				std::cout << "Grade D!" << std::endl;
				break;
			case 1 ... 59:
				std::cout << "Grade E!" << std::endl;
				break;
		}
	}
	
	std::cout << "Number drom 1 to 10 :)" << std::endl;
	for (size_t i = 1; i <= 10; ++i) {
		std::cout << i << " ";
	}

	std::cout << std::endl;

	return 0;
}
