#include <iostream>
#include <filesystem>
#include <string>
using std::cin;
using std::cout;
using std::endl;

namespace fs = std::filesystem;

int main() {
	fs::path p{ "D:\\" };
	cout << "C: total space: " << fs::space(p).capacity << endl;
	cout << "C: free space: " << fs::space(p).available << endl;




	cin.get();
	return (0);
}