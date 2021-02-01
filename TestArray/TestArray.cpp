#include <iostream>
#include <array>
#include <algorithm>

void print(std::array<int,3>& a) {
	for (auto x : a) {
		std::cout << x << " ";
	}
	std::cout << std::endl;
}

int search(std::array<int, 3>& a, int token) {
	bool isEsist{ false };
	int i = 0;
	for (auto element : a) {
		if (element == token) {
			isEsist = true;
			break;
		}
		i++;
	}
	if (isEsist) {
		return (i);
	}
	else {
		return (-1);
	}
}

int main() {
	std::array a1 { 1,2,4 };
	print(a1);

	std::array b1{ 100,200,300 };
	print(b1);
	a1.swap(b1);
	print(a1);
	print(b1);
	std::cout << a1.size() << std::endl;
	std::cout << a1.max_size() << std::endl;

	std::cout << "search 300:"<<search(a1, 300) << std::endl;
	std::cout << "search 1:" << search(a1, 1) << std::endl;

	std::sort(a1.rbegin(), a1.rend());
	print(a1);
	//¶þÎ¬Êý×é
	std::array<std::array<int, 3>, 4> a8;
	return (0);
}