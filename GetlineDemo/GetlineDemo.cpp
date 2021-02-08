#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <filesystem>
using std::cout;
using std::endl;
using std::ifstream;
using std::string;

namespace fs = std::filesystem;

int main() {
	//打开文件
	fs::path p {"greatwall.txt"};
	ifstream in{ p };
	if (!in) {
		cout << "Cant open file" << p << endl;
		std::abort();//exit
	}
	//istream::getline函数
	constexpr int SIZE = 1024;

	std::array<char, SIZE> buf;

	while (!in.eof()) {
		in.getline(&buf[0], SIZE, '#');
		cout << &buf[0] << endl;
	}

	string name1{ " " };
	in.close();
	in.open(p);

	while (!in.eof()) {
		std::getline(in, name1, '#');
		cout << name1 << endl;
	}


	std::cin.get();
	return (0);
}