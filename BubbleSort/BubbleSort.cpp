#include <iostream>
using namespace std;

int main() {
	double arrays[10] = { 2,1,4,7,6,9,3,0,10,888 };
	int arrays_length = sizeof(arrays) / sizeof(double);
	double temp;
	for (int i = 0; i < arrays_length-1; i++) {
		for (int j = 0; j < arrays_length - 1; j++) {
			if (arrays[j] < arrays[j + 1]) {
				swap(arrays[j+1], arrays[j]);
			}
		}
	}

	for (int i = 0; i < arrays_length; i++) {
		cout << arrays[i] << " ";
	}
	cout << endl;

	for (int i = arrays_length-1; i >= 0; i--) {
		cout << arrays[i] << " ";
	}
	cout << endl;

	cin.get();
	return (0);
}