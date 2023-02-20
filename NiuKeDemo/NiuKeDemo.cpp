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


#if 0
// 购物单
// https://www.nowcoder.com/practice/f9c6f980eeec43ef85be20755ddbeaf4
class HUAWEI_HJ16 {
public:
	void sol_1() {
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
			for (int j = 1; j <= N; j++) {
				// 只要主件
				if (j >= zj[i]) {
					dp[j] = max(dp[j], dp[j - zj[i]] + zj_vw[i]);
				}

				// 主件+附件1
				if (j >= zj[i] - +fj_1[i]) {
					dp[j] = max(dp[j], dp[j - zj[i] - fj_1[i]] + zj_vw[i] + fj_1_vw[i]);
				}
				// 主件+附件2
				if (j >= zj[i] + fj_2[i]) {
					dp[j] = max(dp[j], dp[j - zj[i] - fj_2[i]] + zj_vw[i] + fj_2_vw[i]);
				}
				// 主件 + 附件1 + 附件2
				if (j >= zj[i] + fj_1[i] + fj_2[i]) {
					dp[j] = max(dp[j], dp[j - zj[i] - fj_1[i] - fj_2[i]] + zj_vw[i] + fj_1_vw[i] + fj_2_vw[i]);
				}
			}
		}
		cout << endl;
		cout << dp[N] << endl;
	}

	void sol_2() {
		int N;
		int m;
		while (cin >> N >> m) {
			// 存放dp的矩阵
			int dp[61][3201] = { 0 };
			// 存放v
			int weight[61][3] = { 0 };
			// 存放v*p
			int value[61][3] = { 0 };
			int v, p, q;
			N /= 10;
			for (int i = 1; i <= m; i++) {
// 输入处理
cin >> v >> p >> q;
// 重量，我们要使这个p总和最大
p *= v;
// 价格
v /= 10;
// 这个东西是主件，q==0
if (!q) {
	// 重量就是价格v
	weight[i][q] = v;
	// 价值就是p==p*v
	value[i][q] = p;
}
// 这个东西是第q件物品的第一个附件
else if (!weight[q][1]) {
	weight[q][1] = v;
	value[q][q] = p;
}
// 这个东西是第q件物品的第二个附件
else {
	weight[q][2] = v;
	value[q][2] = p;
}
			}

			// 开始dp
			for (int i = 1; i <= m; i++) {
				for (int j = 1; j <= N; j++) {
					// 默认不装任何物品
					dp[i][j] = dp[i - 1][j];
					// 可以装入一个主件
					if (weight[i][0] <= j) {
						dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i][0]] + value[i][0]);
					}
					// 可以装入一个主件和第一个附件
					if (weight[i][0] + weight[i][1] <= j) {
						dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i][0] - weight[i][1]] + value[i][0] + value[i][1]);
					}
					// 可以装入一个主件和第二个附件
					if (weight[i][0] + weight[i][2] <= j) {
						dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i][0] - weight[i][2]] + value[i][0] + value[i][2]);
					}
					// 可以装入一个主件和第一、二个附件
					if (weight[i][0] + weight[i][1] + weight[i][2] <= j) {
						dp[i][j] = max(dp[i][j], dp[i - 1][j - weight[i][0] - weight[i][1] - weight[i][2]] + value[i][0] + value[i][1] + value[i][2]);
					}
				}
			}
			cout << dp[m][N] << endl;
		}
	}
};

int main() {
	// 总钱数<32000
	/*
	*I:	1000 5
		800 2 0
		400 5 1
		300 5 1
		400 3 0
		500 2 0

	 O:	2200
	*/
	HUAWEI_HJ16* hj16 = new HUAWEI_HJ16;
	hj16->sol_1();
	//hj16->sol_2();
	return 0;
}
#endif

#if 1
// 坐标移动
// https://www.nowcoder.com/practice/119bcca3befb405fbe58abe9c532eb29

// 坐标移动的函数接口
int Coordinate_Movement(string str) {
	int x = 0, y = 0;//初始化横纵坐标
	int len = str.size();//获取字符串的总长度
	vector<string> vec;//用一个向量来存储分割后的多个子字符串
	// 将字符串str按';'分割成多个子字符串substr，然后依次写入向量vec中
	int sublen = 0;//记录每个子字符串的长度
	for (int i = 0; i < len; i++) {
		if (str[i] != ';') {
			sublen++;
			continue;
		}
		vec.push_back(str.substr(i - sublen, sublen));
		sublen = 0;
	}
	// 坐标移动，方向（上下左右）+大小（-99~99）
	for (int i = 0; i < vec.size(); i++) {
		// 确定坐标移动的大小，[-99,99]
		int num = 0;//（横或纵）坐标移动的大小
		// 若字符串为三位有效位，则第二和第三位是坐标移动的大小
		if ((vec[i].size() == 3) && (vec[i][1] >= '0') && (vec[i][1] <= '9') && (vec[i][2] >= '0') && (vec[i][2] <= '9')) {
			num = (vec[i][1] - '0') * 10 + (vec[i][2] - '0');
		}
		// 若字符串为两位有效位，则第二位是坐标移动的大小
		if ((vec[i].size() == 2) && (vec[i][1] >= '0') && (vec[i][1] <= '9')){
			num = (vec[i][1] - '0');
		}
		// 若字符串为一位有效位，则无坐标移动
		if (vec[i].size() == 1) {
			num = 0;
		}

		// 确定坐标移动的方向，左右上下
		switch (vec[i][0])
		{
			case 'A': x -= num;
				break;
			case 'D': x += num;
				break;
			case 'S': y -= num;
				break;
			case 'W': y += num;
				break;
			default: 
				break;
		}
	}
	cout << x << "," << y << endl;
	return 0;
}

// 主函数
int main() {
	string str;
	while (cin >> str) {
		Coordinate_Movement(str);
	}
	return 0;
}
#endif
