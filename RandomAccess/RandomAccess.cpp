#include <iostream>
#include <filesystem>
#include <fstream>
#include <vector>
#include <array>
using std::cout;
using std::cin;
using std::endl;
using std::fstream;

namespace fs = std::filesystem;
int main() {
	fs::path p{ "test.dat" };
	fstream file{ p, std::ios::out |std::ios::in| std::ios::trunc };

	auto x{ 12LL }, y{ 24LL };
	char str[]{ "Hello World" };

	file.write(reinterpret_cast<char*>(&x), sizeof(x));
	file.write(reinterpret_cast<char*>(&y), sizeof(long long int));
	file.write(str, sizeof(str));
	
	char buf[100]{ 0 };
	file.seekg(2*sizeof(long long int),std::ios::beg);
	file.read(buf, 5);

	cout << buf << endl;
	cin.get();
	return (0);
}