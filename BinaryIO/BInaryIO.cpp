#include <iostream>
#include <filesystem>
#include <fstream>
#include <array>
using io = std::ios;

namespace fs = std::filesystem;

int main() {
	fs::path p{ "array.dat" };
	//创建二进制输出流
	std::fstream out{ p,io::out | io::app };

	//判断流是否成功打开
	if (!out) {
		std::cout << "error" << std::endl;
		return (0);
	}

	//将一个整型数组的内容输出到二进制文件中
	std::array a{ 21,42,63 };
	std::streamsize size = a.size() * sizeof(a[0]);
	out.write(reinterpret_cast<char*>(&a[0]),size);

	//以读取模式重新打开二进制文件，或者将文件光标定位到文件头 fstream::seekg()
	out.close();

	out.open(p, io::in);

	//从二进制流中读入一个整数并显示到屏幕上
	auto x{ 0L };
	out.read(reinterpret_cast<char*>(&x), sizeof(x));
	std::cout << x << std::endl;

	std::cin.get();
	return (0);
}