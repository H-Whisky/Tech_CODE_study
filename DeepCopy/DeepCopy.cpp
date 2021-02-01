#include <iostream>
#include "Date.h"
#include "Employee.h"


//int Employee::numberOfObjects = 0;
int main() {
	Emplyee e1{ "Alex",Gender::male,{1998,5,1} };
	Emplyee e2{ e1 };
	std::cout << e1.toString() << std::endl;
	std::cout << e2.toString() << std::endl;
	std::cin.get();
	return (0);
}