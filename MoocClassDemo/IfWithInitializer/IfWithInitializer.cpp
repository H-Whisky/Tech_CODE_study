/*
�´�С
�������0-100������
�û���һ���������������
�����ж��û�����������Ĵ�С����ʾ�û����´���/��С��/�����ˡ�
*/

#include <iostream>

int main() {
	std::cout << "����0-100����...\n";

	std::cout << "��������²��������" << std::endl;

	auto x{ 0 };
	std::cin >> x;

	if (int z = rand() % 100; x > z) {
		std::cout << "��´��ˣ��ҵ�����" << z << std::endl;
	}
	else if (x < z) {
		std::cout << "���С�ˣ��ҵ�����" << z << std::endl;
	}
	else {
		std::cout << "��¶��ˣ��ҵ�����" << z << std::endl;
	}





	std::cin.get();
	return 0;
}