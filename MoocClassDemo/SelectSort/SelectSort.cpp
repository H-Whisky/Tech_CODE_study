#include <iostream>
using namespace std;

int main() {
	double arrays[10] = { 2,1,4,7,6,9,3,0,5,10 };
	int arrays_length = sizeof(arrays) / sizeof(double);
	for (int i = 0; i < arrays_length - 1; i++) {
		for (int j = i + 1; j < arrays_length; j++) {
			if (arrays[j] > arrays[i]) {
				swap(arrays[j], arrays[i]);
			}
		}
	}

	//cout << *arrays << endl;
	for (int i = 0; i < arrays_length; i++) {
		cout << arrays[i] << " ";
	}
	cout << endl;

	for (int i = arrays_length - 1; i >= 0; i--) {
		cout << arrays[i] << " ";
	}
	cout << endl;

	cin.get();
	return (0);
}