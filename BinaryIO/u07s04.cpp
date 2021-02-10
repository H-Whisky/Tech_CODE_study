#include <iostream>
#include <filesystem>
#include <vector>
#include <fstream>
using namespace std;
using io = std::ios;

//int main() {
//	ifstream inFile("binary.dat", io::in|io::binary );
//	if (!inFile) {
//		cout << "error" << endl;
//		return (0);
//	}
//	float fea[128];
//	int n = 0;
//	while (inFile.read((char*)&fea[0], 128 * sizeof(float))) {
//		n++;
//	}
//	cout << n << endl;
//	for (int i = 0; i < 128; i++) {
//		cout << fea[i] << endl;
//	}
//	cin.get();
//	return(0);
//
//
//}