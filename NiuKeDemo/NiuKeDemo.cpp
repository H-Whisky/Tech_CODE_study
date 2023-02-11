// NiuKeDemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
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


#if 1
// https://www.nowcoder.com/practice/f9c6f980eeec43ef85be20755ddbeaf4
class HUAWEI_HJ16 {
public:

};

void main() {
	// 总钱数<32000
	int dp[32000];
	// N:总钱数
	// m:可购买的物品的个数
	int N, m;
	cin >> N >> m;

	// 定义几个数组
	vector<int> zj(m + 1), zj_vw(m + 1), fj_1(m + 1), fj_1_vw(m + 1), fj_2(m + 1), fj_2_vw(m + 1);
	
	for (int i = 1; i <= m; i++) {
		// v:物品的价格
		// p:物品的重要程度
		// q:所属主件的编号，=0为主件，>0为编号
		int v, p, q;
		cin >> v >> p >> q;
		// 主件
		if (q == 0) {
			zj[i] = v;
			zj_vw[i] = v * p;
		}
		// 附件1
		else if (fj_1[q] == 0) {
			fj_1[q] = v;
			fj_1_vw[q] = v * p;
		}
		// 附件2
		else if (fj_2[q] == 0) {
			fj_2[q] = v;
			fj_2_vw[q] = v * p;
		}
	}

	// dp
	for (int i = 1; i <= m; i++) {
		for (int j = N; j >= 1; j--) {
			// 只要主件
			if (j >= zj[i]) {
				dp[j] = max(dp[j],dp[j-zj[i]]+zj_vw[i]);
			}

			// 主件+附件1
			if (j >= zj[i]- + fj_1[i]) {
				dp[j] = max(dp[j], dp[j - zj[i] - fj_1[i]] + zj_vw[i]+ fj_1_vw[i]);
			}
			// 主件+附件2
			if (j >= zj[i] + fj_2[i]) {
				dp[j] = max(dp[j], dp[j - zj[i] - fj_2[i]] + zj_vw[i] + fj_2_vw[i]);
			}
			// 主件 + 附件1 + 附件2
			if (j >= zj[i] + fj_1[i] + fj_2[i]) {
				dp[j] = max(dp[j], dp[j - zj[i] - fj_1[i]-fj_2[i]] + zj_vw[i] + fj_1_vw[i] + fj_2_vw[i]);
			}
		}
	}
	cout  << endl;
	cout << dp[N] << endl;
}
#endif
