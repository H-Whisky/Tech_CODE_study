#include <iostream>
#include "Circle3.h"


Circle::Circle() {
	radius = 1.0;
}

Circle::Circle(double radius_) {
	radius = radius_;
}

double Circle::getArea() const{
	return (3.14 * radius * radius);
}

double Circle::getRadius() const {
	return radius;
}

Circle& Circle::setRadius(double radius) {
	this->radius = radius;
	return (*this);
	//return (Circle(radius));
}


