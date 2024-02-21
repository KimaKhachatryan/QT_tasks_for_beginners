#include <iostream>

enum Week {
	Monday = 1,
	Tuesday,
	Wednesday,
	Thursday,
	Friday,
	Saturday,
	Sunday
};

struct Date {
	int Weekday;
	std::string Day;
	std::string Month;
	std::string Year;

	std::string date;

	void setDate();
	void getDate();
};

int main()
{
	Date obj;
	obj.setDate();
	obj.getDate();

	return 0;
}

void Date::setDate()
{
	std::cout << "Enter the weekday (with numbers): ";
	std::cin >> Weekday;

	std::cout << "Enter the day: ";
	std::cin >> Day;  
	
	std::cout << "Enter the Month: ";
	std::cin >> Month;  

	std::cout << "Enter the Year: ";
	std::cin >> Year;

	date = Day + "." + Month + "." + Year + ", ";

	switch(Weekday) {
		case 1:
			date += "Monday";
			break;
		case 2:
			date += "Tuesday";
			break;
		case 3:
			date += "Wednesday";
			break;
		case 4:
			date += "Thursday";
			break;
		case 5:
			date += "Friday";
			break;
		case 6:
			date += "Saturday";
			break;
		case 7:
			date += "Sunday";
			break;
		default:
			std::cout << "Invalid input: you should enter the weekday with numbers" << std::endl;
			exit(0);
	}
}

void Date::getDate()
{
	std::cout << date << std::endl;
}

