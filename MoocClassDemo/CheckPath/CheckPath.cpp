#include <iostream>
#include <filesystem>
#include <string>

int main() {
	namespace fs = std::filesystem;
	fs::path p1{ "D:\Workspace\Practise\Tech_CODE_study\MoocClassDemo\CheckPath\Hello.txt" };
	fs::path p2{ R"(D:\Workspace\Practise\Tech_CODE_study\MoocClassDemo\CheckPath)" };
	fs::path p3{ "D:\Workspace\Practise\Tech_CODE_study\MoocClassDemo\CheckPath\Hello.txt" };

	std::cout << fs::path::preferred_separator << std::endl;
	if (fs::is_regular_file(p2)) {
		std::cout << p2 << "'s size: "<< fs::file_size(p2) << std::endl;
	}
	else if(fs::is_directory(p2)){
		std::cout << p2 << "is a directory,includes: " << std::endl;
		for (auto& e : fs::directory_iterator(p2)) {
			std::cout << "e.path():" << e.path()<<std::endl;
		}
	}
	else if (fs::exists(p2)) {
		std::cout << p2 << " is a special file\n";
	}
	else {
		std::cout << p2 << " does not exist" << std::endl;
	}

	std::cin.get();
	return (0);
}