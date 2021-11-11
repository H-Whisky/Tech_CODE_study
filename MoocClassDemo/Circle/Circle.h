#pragma once

class Circle {
public:
	double radius;
	Circle();
	Circle(double radius_);
	double getArea();
	double getRadius() const;
	void setRadius(double radius);

};