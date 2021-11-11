#pragma once

class Circle {
public:
	double radius;
	Circle();
	Circle(double radius_);
	double getArea() const;
	double getRadius() const;
	Circle& setRadius(double radius);

};