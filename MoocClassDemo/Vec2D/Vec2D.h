#pragma once
#include <string>
#include <iostream>
#include <cmath>

class Vec2D
{
public:
	Vec2D();
	Vec2D(double x, double y);
	~Vec2D();
private:
	double x_;
	double y_; 
public:
	// ������ת��Ϊ�ַ�����ʽ��ʾ
	std::string toString();
	// �����ӷ�
	Vec2D add(const Vec2D& secondVec2D);
	Vec2D add(double numeral);
	Vec2D operator+ (const Vec2D& secondVec2D);
	Vec2D operator+ (const double numeral);
	Vec2D& operator+= (const Vec2D& secondVec2D);//v1+=3.0+=v2������
	// ��������
	Vec2D substract(const Vec2D& secondVec2D);
	Vec2D substract(double numeral);
	Vec2D operator- (const Vec2D& secondVec2D);
	Vec2D operator- (const double numeral);
	Vec2D& operator-=(const Vec2D& secondVec2D);
	// �������
	int dot(const Vec2D& secondVec2D);
	// ��������
	Vec2D multiply(double multiplier);
	double operator* (const Vec2D& secondVec2D);
	Vec2D operator* (double multiplier);
	friend Vec2D operator* (double multiplier, Vec2D vec2d);
	// ������ֵ
	Vec2D negative();
	Vec2D operator- ();
	// ��������1
	Vec2D& increase();
	Vec2D& operator++();
	Vec2D operator++(int dummy);
	// �����Լ�1
	Vec2D& decrease();
	Vec2D& operator--();
	Vec2D operator--(int dummy);
	// �����Ƚ�
	int compareTo(Vec2D secondVec2D);
	// ��ȡ�����޸�����Ԫ��
	double& at(const int index);
	double& operator[] (const int& index);
	// ��������
	double direction();
	double magnitude();
};

