#include <iostream>
#include <filesystem>
#include <string>

int main() {
	namespace fs = std::filesystem;
	//����·��
	fs::path p{R"(D:\worksapce\MoocClassDemo\PathQuery\PathQuery.cpp)"};
	//�Ƿ���ڣ���������·�������·����
	
	if (p.empty()) {
		std::cout << "Path:" << p << " is empty. " << std::endl;
	}

	if (!fs::exists(p)) {
		std::cout << "Path: " << p << " does not exist." << std::endl;
		std::exit(0);
	}
	//��·�����ļ������ļ������ɣ���չ����
	std::cout << "root_name(): " << p.root_name() << "\n"
		<< "root_path(): " << p.root_path() << "\n"
		<< "relative_path(): " << p.relative_path() << "\n";
	std::cout << "parent_path(): " << p.parent_path() << "\n"
		<< "filename(): " << p.filename() << "\n"
		<< "stem(): " << p.stem() << "\n"
		<< "extension(): " << p.extension() << std::endl;

	std::cin.get();
	return (0);
}