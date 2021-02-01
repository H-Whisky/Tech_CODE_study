#include <iostream>
#include <cassert>

#include "StackOfIntegers.h"

int main() {
	StackOfIntegers s1{};
	for (int i = 0; i < 5;i++) { //µ× 1 2 3 4 5 ¶¥
		s1.push(i + 1);
	}

	std::cout << "Stack size = " << s1.getSize() << std::endl;
	int sizeOfStack = s1.getSize();
	std::cout << "Top elements is:" << s1.peek() << std::endl;
	for (int i = 0; i < sizeOfStack; i++) {
		std::cout << s1.pop() << " ";
	}
	std::cout << std::endl;
	std::cout << "Stack now is or not empty:" << s1.empty() << std::endl;

	std::cin.get();
	return(0);
}