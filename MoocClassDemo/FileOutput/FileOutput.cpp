#include <iostream>
#include <filesystem>
#include <fstream>
using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;

namespace fs = std::filesystem;

int main() {
	fs::path p{ "D:/Workspace/Practise/Tech_CODE_study/MoocClassDemo/FileOutput/scores.txt" };
	
	ofstream output{ p };

	double lileiScore{ 90.5 };
	
	int hanmeimeiScore{ 84 };

	int huaweiScore{ 100 };

	output << "LiLei " << lileiScore << endl;
	output << "HanMeimei" << hanmeimeiScore << endl;
	output << "HuaWei" << huaweiScore << endl;

	output.close();

	cout << "size of: " << p << " is " << fs::file_size(p) << endl;
	
	cin.get();
	return (0);
}