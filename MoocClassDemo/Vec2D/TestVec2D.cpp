#include <iostream>
#include "Vec2D.h"
using std::cout;
using std::endl;
using std::cin;

int main() {
	//������������
	Vec2D v1{ 3,5 }, v2{ 4,6 };

	//����תΪ�ַ���
	cout << "v1 = " << v1.toString() << endl;
	cout << "v2 = " << v2.toString() << endl;

	//�����ӷ�������+����
	//Vec2D v3 = v1.add(v2);
	Vec2D v3 = v1 + v2;
	//Vec2D v4 = v3.add(10.0);
	Vec2D v4 = v3 + 10.0;
	cout << "v3 = " << v3.toString() << endl;
	cout << "v4 = " << v4.toString() << endl;
	
	//���������������������������
	Vec2D v5 = v2- v1;
	double v6 = v2 * v1;
	Vec2D v7 = 2.1 * v3;
	cout << "v2 - v1 = " << v5.toString() << endl;
	cout << "v2 . v1 = " << v6 <<endl;
	cout << "v3 * 2.1 =" << (v3 * 2.1).toString() << endl;
	cout << "2.1 * v3 =" << v7.toString() << endl;

	Vec2D va1{ 10,12 }, va2{ 1,2 };
	cout << "va1 += va2" <<(va1+=va2).toString()<< endl;
	cout << "va1 -= va2" <<(va1-=va2).toString()<< endl;


	//������ֵ
	Vec2D v8 = v2.negative();
	cout << "-v2 = " << v8.toString() << endl;
	cout << "-v2 = " << (-v2).toString() << endl;

	//��������/�Լ�
	cout << "v8 increase =" << v8.increase().toString() << endl;
	cout << "++ v8 =" << (++v8).toString() << endl;
	cout << "v8 ++ =" << (v8++).toString() << endl;
	cout << "v8=" << v8.toString() << endl;

	cout << "v2 decrease =" << v2.decrease().toString() << endl;
	cout << "-- v2 =" << (--v2).toString() << endl;
	cout << "v2 -- =" << (v2 --).toString() << endl;
	cout << "v2 =" << v2.toString() << endl;

	//��ȡ�����޸�����Ԫ��
	cout << "v1.x_ = " << v1.at(0) << endl;
	cout << "v1.y_ = " << v1.at(1) << endl;
	v1[0] = 31.1;
	cout << "v1[0] = " << v1[0] << endl;
	cout << "v1[1] = " << v1[1] << endl;
	//v1[8] = 2;//Խ�� ��Ҫ�쳣����

	//�����ĳ���magnitude �ͽǶ�direction
	cout << "v1.magnitude = " << v1.magnitude() << endl;
	cout << "v1.direction = " << v1.direction() << endl;

	//�Ƚ���������
	cout << "v1 compare v2 :" << v1.compareTo(v2) << endl;

	//���������
	int a = 1, b = 2;
	int c = a << b;
	cout << "����:" << c << endl;
}