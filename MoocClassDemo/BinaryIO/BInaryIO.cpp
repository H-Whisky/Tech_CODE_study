#include <iostream>
#include <filesystem>
#include <fstream>
#include <array>
using io = std::ios;

namespace fs = std::filesystem;

int main() {
	fs::path p{ "array.dat" };
	//���������������
	std::fstream out{ p,io::out | io::app };

	//�ж����Ƿ�ɹ���
	if (!out) {
		std::cout << "error" << std::endl;
		return (0);
	}

	//��һ���������������������������ļ���
	std::array a{ 21,42,63 };
	std::streamsize size = a.size() * sizeof(a[0]);
	out.write(reinterpret_cast<char*>(&a[0]),size);

	//�Զ�ȡģʽ���´򿪶������ļ������߽��ļ���궨λ���ļ�ͷ fstream::seekg()
	out.close();

	out.open(p, io::in);

	//�Ӷ��������ж���һ����������ʾ����Ļ��
	auto x{ 0L };
	out.read(reinterpret_cast<char*>(&x), sizeof(x));
	std::cout << x << std::endl;

	std::cin.get();
	return (0);
}