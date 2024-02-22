#include <iostream>

class Shape {
public:
    double calculateArea();
};

class Circle : public Shape {
public:
    Circle(double r) : radius(r) {}

    double calculateArea();

private:
    double radius;
};

class Rectangle : public Shape {

public:
    Rectangle(double l, double w) : length(l), width(w) {}
   
    double calculateArea(); 
private:
    double length;
    double width;
};

int main() {

	double radius = 0.0;
	double length = 0.0;
	double width = 0.0;

	std::cout << "Enter the circle radius: ";
	std::cin >> radius;

	std::cout << "Enter the rectangle length: ";
	std::cin >> length;
	
	std::cout << "Enter the rectangle width: ";
	std::cin >> width;
	
	Circle circle(radius);
    Rectangle rectangle(length, width);

    std::cout << "Circle Area = " << circle.calculateArea() << "." << std::endl;
    std::cout << "Rectangle Area = " << rectangle.calculateArea() << "." << std::endl;

    return 0;
}

double Shape::calculateArea() 
{
	return 0.0;
}

double Circle::calculateArea()
{
    return 3.14159 * radius * radius;
}

double Rectangle::calculateArea() {
	return length * width;
}





