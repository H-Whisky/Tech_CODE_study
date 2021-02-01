#include <iostream>
#include <string>

#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"

int main() {
	Shape s1{ Color::blue,false };
	Circle c1{ 3.9 ,Color::green,true};
	Rectangle r1{ 4.0,1.0 ,Color::red,true};
	
	std::cout << s1.toString() << std::endl;
	std::cout << c1.toString() << std::endl;
	std::cout << r1.toString() << std::endl;

	std::cout <<"c1's area is " << c1.getArea() << std::endl;
	std::cout <<"r1's area is " << r1.getArea() << std::endl;

	std::cin.get();
	return (0);
}