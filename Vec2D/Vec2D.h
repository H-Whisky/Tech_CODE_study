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
	Vec2D add(Vec2D secondVec2D);
	Vec2D add(double numeral);
	// 向量比较
	int compareTo(Vec2D secondVec2D);
	// 读取或者修改向量元素
	double& at(const int index);
	// 向量方向
	double direction();
	// 向量点乘
	int dot(Vec2D secondVec2D);
	// 向量求负值
	Vec2D negative();
	// 向量自增1
	Vec2D& increase();
	// 向量自减1
	Vec2D& decrease();
	double magnitude();
	Vec2D multiply(double multiplier);
	Vec2D substract(Vec2D secondVec2D);
};

