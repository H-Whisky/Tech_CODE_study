#include <iostream>
#include <stdio.h>
/*
using namespace std;

int main() {//This is main function
	cout << "Aloha,World!" << endl;
	return 0;
}
*/
struct Propery {
	char name[20];
	char value[40];

}p3 = { "1","blue" };

int main() {
	printf("%s \n", p3.name);
	printf("%s \n", p3.value);

	return 0;
}

// 构造函数不被继承 