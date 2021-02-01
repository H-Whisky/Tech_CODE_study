#include <iostream>
using std::cout;
using std::endl;

class Computer {
public:
	Computer() { cout << "Computer()" << endl; }
	~Computer() { cout << "~Computer()" << endl; }
};
class PC : public Computer {
public:
	PC() { cout << "PC()" << endl; }
	~PC() { cout << "~PC()" << endl; }
};
class Desktop : public PC {
public:
	Desktop() { cout << "Desktop()" << endl; }
	~Desktop() { cout << "~Desktop()" << endl; }
};
class Camera {
public:
	Camera() { cout << "Embedded Camera()" << endl; }
	~Camera() { cout << "Embedded ~Camera()" << endl; }
};

class Laptop : public PC {
public:
	Laptop() { cout << "Laptop()" << endl; }
	~Laptop() { cout << "~Laptop()" << endl; }
private:
	Camera c{};
};



int main() {
	{Laptop l; }
	


	std::cin.get();
	return (0);
}