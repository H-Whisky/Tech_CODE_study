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
	// 将向量转换为字符串形式表示
	std::string toString();
	// 向量加法
	Vec2D add(const Vec2D& secondVec2D);
	Vec2D add(double numeral);
	Vec2D operator+ (const Vec2D& secondVec2D);
	Vec2D operator+ (const double numeral);
	Vec2D& operator+= (const Vec2D& secondVec2D);//v1+=3.0+=v2不考虑
	// 向量减法
	Vec2D substract(const Vec2D& secondVec2D);
	Vec2D substract(double numeral);
	Vec2D operator- (const Vec2D& secondVec2D);
	Vec2D operator- (const double numeral);
	Vec2D& operator-=(const Vec2D& secondVec2D);
	// 向量点积
	int dot(const Vec2D& secondVec2D);
	// 向量数乘
	Vec2D multiply(double multiplier);
	double operator* (const Vec2D& secondVec2D);
	Vec2D operator* (double multiplier);
	friend Vec2D operator* (double multiplier, Vec2D vec2d);
	// 向量比较
	int compareTo(Vec2D secondVec2D);
	// 读取或者修改向量元素
	double& at(const int index);
	// 向量方向
	double direction();
	// 向量求负值
	Vec2D negative();
	// 向量自增1
	Vec2D& increase();
	// 向量自减1
	Vec2D& decrease();
	double magnitude();
};

