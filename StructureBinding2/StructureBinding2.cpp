#include <iostream>


//½á¹¹Ìå
struct S
{
	double d1{ 1.0 };
	int i1{ 32 };
};

class C {
public:
	int i2{ 1 };
	char c[ 3 ]{ 'a', 'b','\0' };
};


int main() {
	S s;
	C c;
	auto [d1, i1] {s};
	auto& [i2, c2] {c};


	std::cout <<"s.d1="<< d1 << " s.i1=" << i1 << std::endl;
	std::cout <<"c.i2="<< i2 << " c.c[3]=" << c2 << std::endl;

	return (0);
}