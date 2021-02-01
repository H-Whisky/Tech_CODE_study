#include <iostream>

class B {
public:
	B() { std::cout << "B()" << std::endl; }
	B(int i) { std::cout << "B(" << i << ")" << std::endl; }
	B(char  c) { std::cout << "B(" << c << std::endl; }
};

class E {
public:
	E() { std::cout << "E()" << std::endl; }
};


class D : public B{
public :
	using B::B;
	D() = default;
	D(double x) : e1{}, e2{}, B(static_cast<int>(x)) {
		std::cout << "D(" << x << ")" << std::endl;
	}
private:
	//double x{ 0.0 };
	E e1, e2;
};



int main() {
	B b;
	D d;
	D d2{ 3.3 };
	//D d3{ 'd3'};

	std::cin.get();
	return (0);
}