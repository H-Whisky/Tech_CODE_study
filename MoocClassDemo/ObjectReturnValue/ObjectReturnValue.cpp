#include <iostream>
#include "Circle3.h"

/*
//
*/
int main() {
	Circle c{ 1.0 };
	
	std::cout << c.setRadius(2.0)
		.setRadius(3.0)
		.getArea() << std::endl;;
	
	return (0);
} 