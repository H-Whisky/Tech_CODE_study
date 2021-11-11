#include <iostream>
#include <cassert>
#include "Square.h"


int Square::numberOfObjects {10};
int main() {
	Square s1;
	std::cout << s1.getNumberOfObjects() << std::endl;
	assert(s1.getNumberOfObjects() == 11);
	Square s2{ 20.0 };
	std::cout << Square::getNumberOfObjects() << std::endl;
	std::cout << s2.getNumberOfObjectsNonStatics() << std::endl;
	//std::cout<<Square.
	std::cin.get();
	return (0);
}