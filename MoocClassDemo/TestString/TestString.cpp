#include <iostream>

int main() {
	//创建字符串
	std::string s{ "Hello" };
	//用数组为字符串赋值
	s.clear();
	//assign()
	char arr[]{ 'W','o','r','l','d' };
	s += arr;
	//append
	s.assign("1024");
	//insert 空白
	s.append(" ");
	//s.append("    ");
	s.append(5,'\t');
	std::cout << s << std::endl;

	//移除字符串前面的空白
	s.insert(0, "  ");
	//移除字符串后面的空白
	s.erase(0, s.find_first_not_of(" \n\t\r"));
	//把字符串转化为整数或浮点数
	s.erase(s.find_last_not_of(" \n\t\r")+1);
	s += "$";

	//int x = std::stoi(s)
	std::cout << s << std::endl;
	return (0);
}