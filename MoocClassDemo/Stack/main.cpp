#include <iostream>
#include "ArrayStack.h"
using namespace std;

int main() {
	int tmp = 0;
	ArrayStack<int>* astack = new ArrayStack<int>();
	cout << "main" << endl;
	//��10,20,30��ջ
	astack->push(10);
	astack->push(20);
	astack->push(30);
	//��ջ��Ԫ�ظ�ֵ��tmp����ɾ��ջ��Ԫ��
	tmp = astack->pop();
	cout << "tmp=" << tmp << endl;
	//��ջ��Ԫ�ظ�ֵ��tmp,��ɾ��Ԫ��
	tmp = astack->peek();
	astack->push(40);
	while (!astack->isEmpty()) {
		tmp = astack->pop();
		cout << tmp << endl;
	}

	cin.get();
	return (0);
}