#include <iostream>

int main() {
	//�����ַ���
	std::string s{ "Hello" };
	//������Ϊ�ַ�����ֵ
	s.clear();
	//assign()
	char arr[]{ 'W','o','r','l','d' };
	s += arr;
	//append
	s.assign("1024");
	//insert �հ�
	s.append(" ");
	//s.append("    ");
	s.append(5,'\t');
	std::cout << s << std::endl;

	//�Ƴ��ַ���ǰ��Ŀհ�
	s.insert(0, "  ");
	//�Ƴ��ַ�������Ŀհ�
	s.erase(0, s.find_first_not_of(" \n\t\r"));
	//���ַ���ת��Ϊ�����򸡵���
	s.erase(s.find_last_not_of(" \n\t\r")+1);
	s += "$";

	//int x = std::stoi(s)
	std::cout << s << std::endl;
	return (0);
}