#include <iostream>

long add (int a, int b);
int sub (int a, int b);
long long mul (int a, int b);
double division (int a, int b);

int main()
{
	int a = 0; 
	int b = 0;
	char symb;

	std::cout << "Enter the first number: ";
	std::cin >> a;
	
	std::cout << "Enter the symbol: ";
	std::cin >> symb;
	
	std::cout << "Enter the second number: ";
	std::cin >> b;

	switch(symb) {
		case '+':
			std::cout << a << " + " << b << " = " 
					  << add(a, b) << "." << std::endl;
			break;
		case '-':
			std::cout << a << " - " << b << " = " 
					  << sub(a, b) << "." << std::endl;
			break;
		case '*':
			std::cout << a << " * " << b << " = " 
					  << mul(a, b) << "." << std::endl;
			break;
		case '/':
			std::cout << a << " / " << b << " = " 
					  << division(a, b) << "." << std::endl;
			break;
		default:
			std::cout << "Wrong input!" << std::endl;
			break;
	}

	return 0;
}


long add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

long long mul(int a, int b)
{
	return a * b;
}

double division(int a, int b)
{
	if (b == 0) {
		std::cout << "Division by 0!!!" << std::endl;
		exit(0);
	}

	return static_cast<double>(a) / b;
}
