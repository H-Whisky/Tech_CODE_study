#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main() {
	//�õ�cin����Ļ�����ָ��
	auto p = std::cin.rdbuf();
	//�Ӽ��̶����ַ��������������������ַ��ڻ�����
	auto x = std::cin.peek();

	cout << "x = " << x << endl;
	//��ʾ�������е��ַ�����
	auto count = p->in_avail();
	cout << "There are " << p->in_avail() << " characters in the buffer. " << endl;

	//�ѻ��������ַ���ȡ��������ʾ
	for (int i = 0; i < count; i++) {
		cout << i + 1 << ": " << cin.get() << endl;
	}

	cin.get();
	return (0);
}