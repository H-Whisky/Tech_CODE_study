
#include <iostream>
#include <typeinfo>
using std::cout;
using std::endl;
using std::cin;

auto max(int x, int y) {
	return x > y ? x : y;
}

int main() {
	auto x = 3;
	auto y{ 42 };
	auto x1{ 1 }, x2{ 2 };

	int y1{ 42 }, &y2{ y1 };
	auto y3{ y2 };
	cout << typeid(y3).name() << endl;

	auto& z1{ y2 };
	cout << typeid(z1).name() << endl;

	int p[3]{ 1,2,3 };
	auto p1 = p;
	cout << typeid(p1).name() << endl;

	auto& p2{ p };
	cout << typeid(p2).name() << endl;

	cin.get();

	return 0;
}