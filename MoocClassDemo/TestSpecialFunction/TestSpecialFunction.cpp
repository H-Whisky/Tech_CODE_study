#include <iostream>
#include <string>
using namespace std;
template <typename T>
auto max(T x,T y) {
	return x > y ? x : y;
}

template <typename T>
auto max(T a ,T b, T c) {
	return max(a, max(b, c));
}

int main() {
	cout << max(1, 2, 3)<<endl;
	cout << max('a', 'b', 'A') << endl;
	cin.get();
	return 0;
}