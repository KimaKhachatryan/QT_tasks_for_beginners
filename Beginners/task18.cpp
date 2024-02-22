#include <iostream>

template <typename T>
class Shape {
public:
    virtual T calculateArea() = 0;
};

template <typename T>
class Circle : public Shape<T> {
public:
    Circle(T r) : radius(r) {}

    T calculateArea() override;

private:
    T radius;
};

template <typename T>
class Rectangle : public Shape<T> {

public:
    Rectangle(T l, T w) : length(l), width(w) {}
   
    T calculateArea () override; 
private:
    T length;
    T width;
};

template <typename T>
T calculation(Shape<T>* object);

int main() {

	double radius = 0.0;
	int length = 0;
	int width = 0;

	std::cout << "Enter the circle radius: ";
	std::cin >> radius;

	std::cout << "Enter the rectangle length: ";
	std::cin >> length;
	
	std::cout << "Enter the rectangle width: ";
	std::cin >> width;
	
	Circle<double> circle(radius);
	Rectangle<int> rectangle(length, width);

    std::cout << "Circle Area = " << calculation<double>(&circle) << "." << std::endl;
    std::cout << "Rectangle Area = " << calculation<int>(&rectangle) << "." << std::endl;

    return 0;
}

template <typename T>
T Circle<T>::calculateArea()
{
    return 3.14159 * radius * radius;
}

template <typename T>
T Rectangle<T>::calculateArea() 
{
	return length * width;
}

template <typename T>
T calculation (Shape<T>* object)
{
	return object->calculateArea();
}



