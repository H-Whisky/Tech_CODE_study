#include <iostream>
#include "Date.h"
#include "Employee.h"

int main() {
	Emplyee e;
	//1.setter
	e.setBirthday(Date(1993, 7, 23));
	std::cout << e.toString() << std::endl;
	//2.getter
	e.getBirthday()->setYear(1998);
	std::cout << e.toString() << std::endl;
	return (0);
}