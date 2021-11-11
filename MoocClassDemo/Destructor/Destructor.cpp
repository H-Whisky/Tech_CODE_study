#include <iostream>

#include "Date.h"
#include "Employee.h"

int Emplyee::numberOfObjects = 0;

int main() {
	Emplyee e1;
	std::cout << e1.toString() << std::endl;
	Emplyee* e2 = new Emplyee{ "John",Gender::male,Date(2000,10,2) };
	std::cout << e2->toString() << std::endl;

	{
		Emplyee e3{ "Alice", Gender::famale,{1989,3,2} };
		std::cout << e3.toString() << std::endl;
	}//×÷ÓÃÓò
	  
	std::cin.get();
	return (0);
}