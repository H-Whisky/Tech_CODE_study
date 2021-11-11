#include <iostream>
#include <typeinfo>
#include "Circle.h"
#include "Rectangle.h"
#include "Shape.h"
using std::cout;
using std::cin;
using std::endl;

int main() {
	//Shape s{ Color::blue,true };
	Circle c{ 0.2,Color::blue,true };
	/*cout << c.getArea() << endl;*/
	Shape* p = &c;
	cout << p->getArea() << endl;

	auto& t1 = typeid(c);
	if (typeid(Circle) == t1) {
		cout << t1.name() << endl;
	}


	cin.get();
	return (0);
}