#include <iostream>

class Shape {
public:
    virtual double calculateArea() = 0;
};

class Circle : public Shape {
public:
    Circle(double r) : radius(r) {}

    double calculateArea() override;

private:
    double radius;
};

class Rectangle : public Shape {

public:
    Rectangle(double l, double w) : length(l), width(w) {}
   
    double calculateArea () override; 
private:
    double length;
    double width;
};

double calculation(Shape* object);

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

    std::cout << "Circle Area = " << calculation(&circle) << "." << std::endl;
    std::cout << "Rectangle Area = " << calculation(&rectangle) << "." << std::endl;

    return 0;
}

double Circle::calculateArea()
{
    return 3.14159 * radius * radius;
}

double Rectangle::calculateArea() 
{
	return length * width;
}

double calculation (Shape* object)
{
	return object->calculateArea();
}



