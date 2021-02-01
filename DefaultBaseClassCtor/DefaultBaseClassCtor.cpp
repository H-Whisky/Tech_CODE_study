#include <iostream>

class A {
public:
	//A() { std::cout << "A()" << std::endl; }
	A() = default;
	A(int i) {
		std::cout << "A(" << i << ")" << std::endl;
	}
};

class B : public A {
public:
	B() { std::cout << "B()" << std::endl; }
	B(int j): A(j) { std::cout << "B(" << j << ")" << std::endl; }
};



int main() {
	A a1{};
	A a2{ 1 };
	B b1{};
	B b2{ 2 };

	std::cin.get();
	return (0);
}