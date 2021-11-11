#include <iostream>
#include "ArrayStack.h"
using namespace std;

int main() {
	int tmp = 0;
	ArrayStack<int>* astack = new ArrayStack<int>();
	cout << "main" << endl;
	//将10,20,30入栈
	astack->push(10);
	astack->push(20);
	astack->push(30);
	//将栈顶元素赋值给tmp，并删除栈顶元素
	tmp = astack->pop();
	cout << "tmp=" << tmp << endl;
	//将栈顶元素赋值给tmp,不删除元素
	tmp = astack->peek();
	astack->push(40);
	while (!astack->isEmpty()) {
		tmp = astack->pop();
		cout << tmp << endl;
	}

	cin.get();
	return (0);
}