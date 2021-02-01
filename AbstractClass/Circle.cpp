#include <iostream>
#include "Circle.h"

Circle::Circle() {
	radius = 1.0;
}

Circle::Circle(double radius_, Color color_, bool filled_) : Shape(color_, filled_) {
	radius = radius_;
}

double Circle::getArea() {
	return (radius * radius * 3.14);
}

double Circle::getRadius() const {
	return radius;
}

void Circle::setRadius(double radius) {
	this->radius = radius;
}

string Circle::toString() {
	return ("Circle:radius" + std::to_string(radius) + ", " + colorToString() + " " + filledToString());
}