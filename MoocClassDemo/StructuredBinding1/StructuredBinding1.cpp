#include <iostream>
#include <array>

int main() {
	std::array a{ 1,2,3 };
	std::array <int, 2> b{ 11,12 };

	//int a[] {1, 2, 3};

	//auto [ e1, e2, e3] = a;
	//const auto [e1, e2, e3] {a};
	auto& [e1, e2, e3] {a};
	e1 = 10;

	std::cout << e1 << " " << e2 << " " << e3 << std::endl;
	std::cout << a[0] <<  std::endl;
	//for (int &i : a) {
	//	std::cout << a[i] << std::endl;
	//}
	

	std::cin.get();
	return (0);
}