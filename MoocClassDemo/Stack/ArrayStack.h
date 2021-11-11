#pragma once

#include <iostream>
using namespace std;

//模板类
template<class T>
class ArrayStack {
public:
	ArrayStack();
	~ArrayStack();
	void push(T t);//向栈中添加一个t元素
	T peek();//向栈中取出一个元素
	T pop();//在栈中删除一个元素
	int size();//大小
	int isEmpty();//判断是否为空
private:
	T* arr;//
	int count;
};

//栈的构造函数
template<class T>
ArrayStack<T>::ArrayStack() {
	arr = new T[12];
	if (!arr) {
		cout << "arr malloc error!" << endl;
	}
}

//析构函数
template<class T>
ArrayStack<T>::~ArrayStack() {
	if (arr) {
		delete[] arr;
		arr = NULL;
	}
}

//向栈中添加一个元素
template<class T>
void ArrayStack<T>::push(T t) {
	arr[count++] = t;
}

//返回栈顶元素
template<class T>
T ArrayStack<T>::peek() {
	return arr[count - 1];
}

//返回栈顶元素，并删除"栈顶元素"
template<class T>
T ArrayStack<T>::pop() {
	int ret = arr[count - 1];
	count--;
	return ret;
}

//返回栈的大小
template<class T>
int ArrayStack<T>::size() {
	return count;
}

//返回栈判空
template<class T>
int ArrayStack<T>::isEmpty() {
	return size() == 0;
}