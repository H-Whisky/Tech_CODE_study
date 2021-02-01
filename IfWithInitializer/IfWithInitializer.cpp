/*
猜大小
随机生成0-100的整数
用户猜一个整数，输入电脑
电脑判断用户输入的整数的大小，提示用户“猜大了/猜小了/猜中了”
*/

#include <iostream>

int main() {
	std::cout << "生成0-100的数...\n";

	std::cout << "请输入你猜测的整数：" << std::endl;

	auto x{ 0 };
	std::cin >> x;

	if (int z = rand() % 100; x > z) {
		std::cout << "你猜大了，我的数是" << z << std::endl;
	}
	else if (x < z) {
		std::cout << "你猜小了，我的数是" << z << std::endl;
	}
	else {
		std::cout << "你猜对了，我的数是" << z << std::endl;
	}





	std::cin.get();
	return 0;
}