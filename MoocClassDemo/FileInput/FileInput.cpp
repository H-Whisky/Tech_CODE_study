#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

using std::ifstream;
using std::ofstream;
using std::cin;
using std::cout;
using std::endl;


namespace fs = std::filesystem;


int main() {
	fs::path p{ "D:/Workspace/Practise/Tech_CODE_study/MoocClassDemo/FileInput/scores.txt" };
	ifstream input{ p };

	if (input.fail()) {
		cout << "Can not open file " << p << endl;
		return (0);
	}

	std::string name{ "" };
	double score{ 0.0 };

	//input >> name >> score;
	//cout << name << " " << score<<endl;
	//input >> name >> score;
	//cout << name << " " << score<<endl;

	char x;
	while (!input.get(x).eof())
	{
		cout << x ;
	}

	cin.get();
	return (0);
}