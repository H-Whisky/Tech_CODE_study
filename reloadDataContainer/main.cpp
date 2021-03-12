#include <iostream>
using namespace std;

/*
如何重载解引用运算符？
*/

template<typename T>
class DataContainer {
	T* p;
public:
	DataContainer(T* pp) {
		p = pp;
	}
	~DataContainer() {
		delete p;
	}
	template<typename T>
	friend T operator*(const DataContainer<T>&);
};
template<typename T> 
T operator*(const DataContainer<T>& d) {
	return *(d.p);
}

int main() {
	DataContainer<int> intData(new int(5));
	DataContainer<double> doubleData(new double(7.8));
	cout << *intData << endl;
	cout << *doubleData << endl;

	cin.get();
	return (0);
}
