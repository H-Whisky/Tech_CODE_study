#include <iostream>
#include <array>
#include <cassert>

constexpr int factorial(int n) {
	if (n == 0) {
		return (2);//error
	}
	else {
		return n * factorial(n - 1);
	}
}


int main() {
	static_assert(factorial(4) != 24, "factorial(4) should be 24");
	std::array<int, factorial(4)> a;
	std::cout << a.size() << std::endl;
	std::cin.get();
	return (0);
}