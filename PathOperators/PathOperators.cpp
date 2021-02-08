#include <iostream>
#include <string>
#include <filesystem>
using std::cout;
using std::cin;
using std::endl;

namespace fs = std::filesystem;

int main() {
	fs::path p1{ R"(C:\temp)" };
	fs::path p2{ R"(C:\temp)" };
	fs::path p3{ "" };

	p1.append(R"(users)");
	p1 /= R"(hua)";
	cout << p1 << endl;

	p2.concat(R"(users)");
	p2 += R"(hua)";
	cout << p2 << endl;

	p3 = p3 / R"(C:\temp)" / R"(hua)";
	cout << p3 << endl;

	cin.get();
	return (0);
}