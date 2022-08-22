#include <iostream>

using namespace std;

#ifdef DEBUG
class P {
	char nameP[30];
public:
	P(char *name = "123") {
		strcpy(nameP, name);
	}
	char *getName() {
		return nameP;
	}
	virtual char* getType() {
		return "P";
	}
};

class B :public P {
	char nameB[30];
public:
	B(char* n1, char* n2) :P(n1) {
		strcpy(nameB, n2);
	}
	char *getName() {
		return nameB;
	}
	char *getType() {
		return "B";
	}
};

void showP(P* p) {
	cout << p->getType() << ":" << p->getName() << endl;
}

int main() {
	B b("book1", "book2");
	showP(&b);

	return (0);
}
#endif

#ifdef DEBUG
typedef struct object object
struct object {
	char data[3];
};

int main(void) {
	object obj_array[3] = { {'a','b','c'}, {'d','e','f'},{'g','h','i'} };
	object* cur = obj_array;
	printf("%c %c\n",*(char*));
}
#endif

#ifdef DEBUG
class D {
	int d;
public:
	D(int x = 1) :d(x) {};
	~D() {
		std::cout << "D";
	}
};



int main() {
	D d[] = { D(3),D(3),D(3) };
	D* p = new D[2];
	delete[] p;
	//std::cin.get();
	return(0);
}
#endif

#ifdef DEBUG
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
#endif

#ifdef DEBUG
int main() {
	uint32_t n = 10110;
	// n&1判断奇数，奇数返1
	std::cout << (n & 1);
}
#endif // DEBUG

// 计算32位二进制的汉明重量
int32_t swar(int32_t i)
{
	i = (i & 0x55555555) + ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	i = (i & 0x0F0F0F0F) + ((i >> 4) & 0x0F0F0F0F);
	i = (i * (0x01010101) >> 24);
	return i;
}

int hammingWeight(uint32_t n) {
	int ret = 0;
	for (int i = 0; i < 32; i++) {
		if (n & (1 << i)) {
			ret++;
		}
	}
	return ret;
}

void main() {
	std::cout<<swar(00000000000000000000000000001011)<<std::endl;
	std::cout<< hammingWeight(00000000000000000000000000001011)<<std::endl;
}