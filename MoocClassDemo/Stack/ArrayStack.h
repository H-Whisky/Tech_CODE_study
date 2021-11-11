#pragma once

#include <iostream>
using namespace std;

//ģ����
template<class T>
class ArrayStack {
public:
	ArrayStack();
	~ArrayStack();
	void push(T t);//��ջ�����һ��tԪ��
	T peek();//��ջ��ȡ��һ��Ԫ��
	T pop();//��ջ��ɾ��һ��Ԫ��
	int size();//��С
	int isEmpty();//�ж��Ƿ�Ϊ��
private:
	T* arr;//
	int count;
};

//ջ�Ĺ��캯��
template<class T>
ArrayStack<T>::ArrayStack() {
	arr = new T[12];
	if (!arr) {
		cout << "arr malloc error!" << endl;
	}
}

//��������
template<class T>
ArrayStack<T>::~ArrayStack() {
	if (arr) {
		delete[] arr;
		arr = NULL;
	}
}

//��ջ�����һ��Ԫ��
template<class T>
void ArrayStack<T>::push(T t) {
	arr[count++] = t;
}

//����ջ��Ԫ��
template<class T>
T ArrayStack<T>::peek() {
	return arr[count - 1];
}

//����ջ��Ԫ�أ���ɾ��"ջ��Ԫ��"
template<class T>
T ArrayStack<T>::pop() {
	int ret = arr[count - 1];
	count--;
	return ret;
}

//����ջ�Ĵ�С
template<class T>
int ArrayStack<T>::size() {
	return count;
}

//����ջ�п�
template<class T>
int ArrayStack<T>::isEmpty() {
	return size() == 0;
}