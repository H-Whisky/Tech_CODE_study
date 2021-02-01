#include <iostream>

//using namespace std;
//
//class P {
//	char nameP[30];
//public:
//	P(char *name = "123") {
//		strcpy(nameP, name);
//	}
//	char *getName() {
//		return nameP;
//	}
//	virtual char* getType() {
//		return "P";
//	}
//};
//
//class B :public P {
//	char nameB[30];
//public:
//	B(char* n1, char* n2) :P(n1) {
//		strcpy(nameB, n2);
//	}
//	char *getName() {
//		return nameB;
//	}
//	char *getType() {
//		return "B";
//	}
//};
//
//void showP(P* p) {
//	cout << p->getType() << ":" << p->getName() << endl;
//}
//
//int main() {
//	B b("book1", "book2");
//	showP(&b);
//
//	return (0);
//}

//typedef struct object object
//struct object {
//	char data[3];
//};
//
//int main(void) {
//	object obj_array[3] = { {'a','b','c'}, {'d','e','f'},{'g','h','i'} };
//	object* cur = obj_array;
//	printf("%c %c\n",*(char*));
//}

//class D {
//	int d;
//public:
//	D(int x = 1) :d(x) {};
//	~D() {
//		std::cout << "D";
//	}
//};
//
//
//
//int main() {
//	D d[] = { D(3),D(3),D(3) };
//	D* p = new D[2];
//	delete[] p;
//	//std::cin.get();
//	return(0);
//}

struct A {
	A(int i) {
		std::cout << "A(int i)" << std::endl;
	}
	A(double d, int i){}
};

struct B :A {
	using A::A;
	int d{ 0 };
	B(int i) :A{ i }, d{ i }{
		std::cout << "B(int i)" << std::endl;
	}
};

int main() {
	B b(1);
	std::cin.get();
	return (0);
}