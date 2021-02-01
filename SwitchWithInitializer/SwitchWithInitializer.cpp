/*
利用带有初始化器的switch语句，将百分制成绩转化为五分制成绩
[90,100]:A
[80,89]:B
[70,79]:C
[60,69]:D
[0,59]:E
*/

#include <iostream>
using std::cout;
using std::endl;

int main() {
	cout << "请输入课程成绩:";

	int score = 0;
	std::cin >> score;

	switch (int x = score / 10; x) {
	case 10:
	case 9:
		cout << "你的成绩是A\n";
		break;
	case 8:
		cout << "你的成绩是B\n";
		break;
	case 7:
		cout << "你的成绩是C\n";
		break;
	case 6:
		cout << "你的成绩是D\n";
		break;
	default:
		cout << "你的成绩是E\n";
	}

	return 0;
}