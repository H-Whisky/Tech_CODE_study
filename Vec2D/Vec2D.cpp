#include "Vec2D.h"


Vec2D::Vec2D() {
	x_ = 0.0;
	y_ = 0.0;
}

Vec2D::Vec2D(double x, double y) {
	x_ = x;
	y_ = y;
}

Vec2D::~Vec2D() {

}

// 将向量转换为字符串形式表示
std::string Vec2D::toString()
{
	return std::string("("+std::to_string(x_) + ", "+std::to_string(y_) + ")" );
}

// 向量加法
Vec2D Vec2D::add(Vec2D secondVec2D)
{
	return Vec2D(x_ + secondVec2D.x_ , y_ + secondVec2D.y_);
}

Vec2D Vec2D::add(double numeral) {
	return Vec2D(this->x_ + numeral, this->y_ + numeral);
}

// 向量减法
Vec2D Vec2D::substract(Vec2D secondVec2D)
{
	return Vec2D(x_ - secondVec2D.x_, y_ - secondVec2D.y_);
}

// 比较两个向量的长度。如果firstVec2D小于secondVec2D，返回-1，若大于则返回1，若相等则返回0
int Vec2D::compareTo(Vec2D secondVec2D)
{
	double m1 = this->magnitude();
	double m2 = secondVec2D.magnitude();
	if (abs(m1 - m2) < 1e-10) {
		return 0;
	}
	else {
		return (m1 > m2 ? 1 : -1);
	}
	return 0;
}

// 读取或者修改向量元素
double& Vec2D::at(const int index)
{
	if (0 == index) {
		return x_;
	}
	else if (1 == index) {
		return y_;
	}
	else {
		throw std::out_of_range("at() only acept 1 or 2 as parameter");
	}
}

// 向量自增1
Vec2D& Vec2D::increase()
{
	x_++; y_++;
	return *this;
}

// 向量自减1
Vec2D& Vec2D::decrease()
{
	x_--; y_--;
	return *this;
}


// 向量方向
double Vec2D::direction()
{
	return 0.0;
}


// 向量点积
int Vec2D::dot(Vec2D secondVec2D)
{
	return (x_ * secondVec2D.x_+y_ * secondVec2D.y_);
}

double Vec2D::magnitude()
{
	return 0.0;
}

// 向量数乘
Vec2D Vec2D::multiply(double multiplier)
{
	return Vec2D(x_ * multiplier , y_ * multiplier);
}

// 向量求负值
Vec2D Vec2D::negative()
{
	return Vec2D(x_ * -1, y_ * -1);
}


