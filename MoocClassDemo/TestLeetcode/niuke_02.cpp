#include <iostream>
#include <algorithm>
//#include <>
using namespace std;

#ifdef DEBUG
int main() {
	const char* p = { "abcdefgh" }, * r;
	long* q;
	q = (long*)p;
	q++;
	r = (char*)q;
	cout << r << endl;
	cout << floor(-8.5) << endl;
	int x = -1;
	unsigned int y = 2;
	cout << sizeof(x) << " | " << sizeof(y) << endl;
	cin.get();
	return (0);
}
#endif // DEBUG

