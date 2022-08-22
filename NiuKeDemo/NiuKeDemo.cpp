// NiuKeDemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
using namespace std;

#ifdef DEBUG
//int main() {
//	int a[3][4] = { 1,3,5,7,9,11,13,15,17,19,21,23 }, (*p)[4] = a, i, j, k = 0;
//	for (i = 0; i < 3; i++) {
//		for (j = 0; j < 2; j++) {
//			k = k + *(*(p + i) + j);
//		}
//	}
//	cout << k << endl;
//	cin.get();
//	return (0);
//}
#endif // DEBUG

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
#endif



// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
