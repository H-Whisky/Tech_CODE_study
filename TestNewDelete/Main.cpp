#include <iostream>

int main() {
	int* p = nullptr;
	int* q(nullptr);//c++11 Initializer List
	int* o = 0;
	int a = 0;

	p = new int(42);
	q = new int[4];

	std::cout << "Before: *p =" << *p << std::endl;
	*p = 24;
	std::cout << "output:" << static_cast<double>(1) / 2 << std::endl;

	std::cout << "After:*p =" << *p << std::endl;

	int intValue = 4;
	float floatValue = 0.0;
	floatValue = static_cast<float>(intValue);
	std::cout << "explicitly:" << floatValue << std::endl;

	for (int i = 0; i < 4; i++) {
		*(q + i) = 10 + i;
		std::cout << *(q+i) << std::endl;
	}

	delete p;
	delete[] q;


	if (3 == a) {

	}

	std::cin.get();
	return 0;
}