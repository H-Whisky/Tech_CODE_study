#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main() {
	//��������
	const int x=0;
	//x = 21;Error

	int y = 2;
	//const int* p = &x;
	//(*p) = 24;
	//const int* q = &y;
	//(*q) = 24;
	
	// ָ�볣�����ɱ�
	int* r = &y;
	int z = 5;

	*r = z;
	cout << *r << " "<<y<<endl;
	
	// ��ָ�볣��
	const int* const s = &y;
	//s = &z;
	
	const char* str = "Hello";
	//*str = 'P';

	auto p1 = &y;
	auto p2 = "World";
	auto const p3 = "!";

	cin.get();

	return 0;
}