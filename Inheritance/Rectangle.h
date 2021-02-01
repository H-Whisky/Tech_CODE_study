#pragma once
#include "Circle.h"
class Rectangle : public Shape {
private:
	double width{ 1.0 };
	double height{ 1.0 };
public:
	Rectangle() = default;
	Rectangle(double w, double h, Color c ,bool f);

	double getWidth() const;//调用的时候，对象的状态不改变
	void setWidth(double w);
	double getHeight() const;
	void setHeight(double h);

	double getArea() const;
};