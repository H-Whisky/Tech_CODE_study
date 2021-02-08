#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	//拿到cin对象的缓冲区指针
	auto p = std::cin.rdbuf();
	//从键盘读入字符到缓冲区，保留所有字符在缓冲区
	auto x = std::cin.peek();

	cout << "x = " << x << endl;
	//显示缓冲区中的字符数量
	auto count = p->in_avail();
	cout << "There are " << p->in_avail() << " characters in the buffer. " << endl;

	//把缓冲区的字符都取出来并显示
	for (int i = 0; i < count; i++) {
		cout << i + 1 << ": " << cin.get() << endl;
	}

	cin.get();
	return (0);
}