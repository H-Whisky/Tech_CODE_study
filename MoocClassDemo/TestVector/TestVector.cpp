#include <vector>
#include <iostream>
#include <string>

#include "Helper.h"

int main() {
	//��C++11���б��ʼ��������vector����words1
	std::vector<std::string> words1{ "Hello","World!","Welcome","To","C" };
	PRINT(words1);
	//ɾ��words1���һ��Ԫ��
	words1.erase(words1.end()-1);
	PRINT(words1);
	//��words1β��׷��Ԫ��
	words1.push_back("C++!");
	PRINT(words1);
	//�ڵ���������words1�������Դ���words2
	std::vector<std::string> words2(words1.begin(), words1.end());
	PRINT(words2);
	//��words2�в���Ԫ��
	words2.insert(words2.begin(), "Hello!");
	PRINT(words2);
	//�ÿ������캯������words3
	std::vector<std::string> words3(words2);
	PRINT(words3);
	//��[]�޸�words3��Ԫ��
	words3[3] = "C Plus Plus!";
	PRINT(words3);
	
	//����words4����ʼ��Ϊ�����ͬ���ִ�
	std::vector <std::string> words4(4, "C++!");
	PRINT(words4);
	//word3��word4����
	words4.swap(words3);
	PRINT(words3);
	PRINT(words4);

	std::cout << R"Hello("111Hello")Hello";
	return (0);
}