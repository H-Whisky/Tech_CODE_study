#include <iostream>
//using namespace std;
using std::cout;
using std::endl;
using std::cin;
using std::string;

namespace MyAloha {
	int main() {
		cout << "Aloha,World!" << endl;

		std::cin.get();
		return 0;
	}
}

void swap(int x, int y) {
	int  t;
	t = x;  x = y;  y = t;
}
int main() {
	int x = 0, & rx = x;
	int a = 5, b{ 10 };
	cout << "Before: a=" << a << " b=" << b << endl;
	swap(a, b);
	cout << "After:  a=" << a << "b=" << b << endl;
	return 0;
}