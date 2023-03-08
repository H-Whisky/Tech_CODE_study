// NiuKeDemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
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

#if 0
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

#if 0
// 密码验证合格程序
// https://www.nowcoder.com/practice/184edec193864f0985ad2684fbc86841

const std::string OK = "OK";
const std::string NG = "NG";
class HUAWEI_HJ20 {
public:
	bool check1(const std::string& s) {
		return s.length() > 8;
	}

	bool check2(const std::string& s) {
		int type[4] = { 0, 0, 0, 0 };
		for (auto& i : s) {
			if (i == ' ' || i == '\n') {
				return false;
			}
			if (i >= 'A' && i <= 'Z') {
				type[0] = 1;
			}
			else if (i >= 'a' && i <= 'z') {
				type[1] = 1;
			}
			else if (i >= '0' && i <= '9') {
				type[2] = 1;
			}
			else {
				type[3] = 1;
			}
		}
		if (type[0] + type[1] + type[2] + type[3] < 3) {
			return false;
		}
		return true;
	}

	bool check3(const std::string& s) {
		// 法一
		return check3_func1(s);
		// 法二
		return check3_func2(s);
	}

	bool check3_func1(const std::string& s) {
		std::unordered_set<std::string> sets;
		std::string tmp;
		for (int i = 0; i < s.length() - 2; ++i) {
			tmp = s.substr(i, 3);
			if (sets.find(tmp) == sets.end()) {
				sets.insert(tmp);
			}
			else {
				return false;
			}
		}
		return true;
	}

	bool check3_func2(const std::string& s) {
		string::size_type pos;
		for (int i = 0; i < s.size(); i++) {
			string sub = s.substr(i, 3);
			pos = s.find(sub, i + 3);
			// string::npos是特殊值，说明查找没有匹配
			// ！= 即匹配了
			if (pos != string::npos) {
				break;
			}
			if (pos == string::npos) {
				return true;
			}
			else {
				return false;
			}
		}
	}

};

int main() {
	HUAWEI_HJ20* hj20 = new HUAWEI_HJ20;
	std::string in;
	while (getline(std::cin, in)) {
		if (hj20->check1(in) && hj20->check2(in) && hj20->check3(in)) {
			std::cout << OK << '\n';
		}
		else {
			std::cout << NG << '\n';
		}
	}
	return 0;
}
#endif

#if 0
// https://www.nowcoder.com/practice/6d9d69e3898f45169a441632b325c7b4
class HUAWEI_HJ24 {
public:
	int solution_1() {
		int n;
		while (cin >> n) {
			// 输入的数组
			int tmp;
			vector<int> v;
			for (int i = 0; i < n; ++i) {
				cin >> tmp;
				v.push_back(tmp);
			}

			// 最长递增子序列
			if (v.empty()) return 0;
			vector<int> dp1(n, 0);
			for (int i = 0; i < n; ++i) {
				dp1[i] = 1;
				for (int j = 0; j < i; ++j) {
					if (v[i] > v[j]) {
						dp1[i] = max(dp1[i], dp1[j] + 1);
					}
				}
			}

			// 最长递减子序列
			vector<int> dp2(n, 0);
			for (int i = n - 1; i >= 0; --i) {
				dp2[i] = 1;
				for (int j = n - 1; j > i; --j) {
					if (v[i] > v[j]) {
						dp2[i] = max(dp2[i], dp2[j] + 1);
					}
				}
			}

			int maxLength = 0;
			for (int i = 0; i < n; ++i) {
				if (maxLength < dp1[i] + dp2[i] - 1) {
					// i就是划分中点
					maxLength = dp1[i] + dp2[i] - 1;
				}
			}
			cout << n - maxLength << endl;
		}
		return 0;
	}

	int solution_2() {
		int n;

		while (cin >> n) {
			vector<int> height(n, 1);
			vector<int> increasenum(n, 1);
			vector<int> decreasenum(n, 1);
			vector<int> realnum;

			int tmp;
			for (int i = 0; i < n; i++) {
				cin >> height[i];
				//cin >> tmp, height.push_back(tmp);
			}
			// 求递增序列数组人数
			calcu(height, increasenum);

			// 求递减序列数组人数
			reverse(height.begin(), height.end());
			calcu(height, decreasenum);
			reverse(decreasenum.begin(), decreasenum.end());

			// 求最长的队列
			int maxnum = 0;
			for (int i = 0; i < n; i++) {
				// 减掉自身的
				realnum.push_back(increasenum[i] + decreasenum[i] - 1);
				maxnum = max(maxnum, realnum[i]);
			}
			cout << n - maxnum << endl;

		}
		return 0;
	}

	void calcu(vector<int> height, vector<int>& increasenum) {
		// 计算以height[i]为最高的递增队列人数
		for (int i = 1; i < height.size(); i++) {
			for (int j = i - 1; j >= 0; j--) {
				if (height[j] < height[i] && increasenum[i] < increasenum[j] + 1) {
					increasenum[i] = increasenum[j] + 1;
				}
			}
		}
	}
};

int main() {
	HUAWEI_HJ24* hj24 = new HUAWEI_HJ24;
	//hj24->solution_1();
	hj24->solution_2();
	return 0;
}
#endif

#if 0
// https://www.nowcoder.com/practice/5190a1db6f4f4ddb92fd9c365c944584

class HUAWEI_HJ26 {
public:
	void solution_1() {
		// 输入
		string str;
		// 字母顺序存储
		vector<char> alp;

		while (getline(cin, str))
		{
			alp.clear();
			for (int i = 0; i < 26; i++) {
				for (int j = 0; j < str.size(); j++) {
					// abc
					if (str[j] - 'a' == i || str[j] - 'A' == i) {
						alp.push_back(str[j]);
					}
				}
			}
			// 输出
			for (int m = 0, n = 0; m < str.size() && n < alp.size(); m++) {
				if (str[m] >= 'a' && str[m] <= 'z' || str[m] >= 'A' && str[m] <= 'Z') {
					str[m] = alp[n], n++;
				}
			}
			//
			cout << str << endl;
		}
	}
};

int main() {
	HUAWEI_HJ26* sj26 = new HUAWEI_HJ26;
	sj26->solution_1();
	return 0;
}

#endif

#if 0
class HUAWEI_HJ27 {
public:
	void solution_1() {
		// 字典中单词个数
		int n;

		while (cin >> n) {
			// 字典
			vector<string> dic;
			string word;
			// 字典初始化
			for (int i = 0; i < n; i++) {
				cin >> word;
				dic.push_back(word);
			}

			// 目标单词
			string target;
			cin >> target;

			// 处理 搜索兄弟单词
			// 记录所有兄弟单词
			vector<string> res;

			string temp = target;
			// 排序
			sort(temp.begin(), temp.end());
			int lent = target.size(); // 目标单词的长度
			for (int i = 0; i < n; i++) {
				int lendic = dic[i].size();

				// 长度一致，单词不同
				if ((lendic == lent) && target != dic[i]) {
					string tempdic = dic[i];
					sort(tempdic.begin(), tempdic.end());
					if (temp == tempdic) {
						res.push_back(dic[i]);
					}
				}
			}

			// 所有兄弟单词都在res中
			int index; // res[index - 1]
			cin >> index;
			// 坑 一定要字典排序
			sort(res.begin(), res.end());
			cout << res.size() << endl;
			// 默认了index-1 >= res.size()
			if (index - 1 < res.size()) {
			cout << res[index - 1] << endl;
			}

		}
	}
};

int main() {
	HUAWEI_HJ27* hj27 = new HUAWEI_HJ27;
	hj27->solution_1();
	return 0;
}
#endif

#if 0
// https://www.nowcoder.com/practice/2aa32b378a024755a3f251e75cbf233a

const string helpStr1 = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
const string helpStr2 = "BCDEFGHIJKLMNOPQRSTUVWXYZAbcdefghijklmnopqrstuvwxyza1234567890";

class HUAWEI_HJ29 {
public:
	void solution_1() {
		string str1, str2;
		string pwdGet, pwdSet;
		while (cin >> str1 >> str2) {
			pwdSet = setPwd(str1);
			pwdGet = getPwd(str2);
			cout << pwdSet << endl;
			cout << pwdGet << endl;
		}
	}

	string setPwd(string str) {
		int len = str.size();
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < helpStr1.size(); j++) {
				if (str[i] == helpStr1[j]) {
					str[i] = helpStr2[j];
					break;
				}
			}
		}
		return str;
	}

	string getPwd(string str) {
		int len = str.size();
		for (int i = 0; i < len; i++) {
			for (int j = 0; j < helpStr2.size(); j++) {
				if (str[i] == helpStr2[j]) {
					str[i] = helpStr1[j];
					break;
				}
			}
		}
		return str;
	}
};

int main() {
	HUAWEI_HJ29* hj29 = new HUAWEI_HJ29;
	hj29->solution_1();
	return 0;
}

#endif

#if 1
class HUAWEI_HJ32 {
public:
	void solution_1() {
		string s;
		
		while (cin >> s) {
			int maxLen = 0;

			int n = s.size();

			for (int i = 1; i < n; i++) {
				// 奇数 ABA
				int low = i - 1, high = i + 1;
				while (low >= 0 && high < n && s[low] == s[high]) {
					low--, high++;
				}
				if (high - low - 1 > maxLen) {
					maxLen = high - low - 1;
				}
				// 偶数 ABBA
				low = i - 1, high = i;
				while (low >= 0 && high < n && s[low] == s[high]) {
					low--, high++;
				}
				if (high - low - 1 > maxLen) {
					maxLen = high - low - 1;
				}
			}
			cout << maxLen << endl;
		}
	}

	void solution_2() {
		string s;

		while (cin >> s) {
			int maxLen = 0;
			// ABA 3 #A#B#A# 7		7/2 = 3
			// ABBA 4 #A#B#B#A# 9	9/2 = 4
			// 扩充字符串
			string temp = "";
			temp.append(1, '#');
			for (int i = 0; i < s.size(); i++) {
				temp.append(1, s[i]), temp.append(1, '#');
			}
			s = temp;
			int n = s.size();

			for (int i = 1; i < n; i++) {
				int low = i - 1, high = i + 1;
				while (low >= 0 && high < n && s[low] == s[high]) {
					low--, high++;
				}
				if (high - low - 1 > maxLen) {
					maxLen = high - low - 1;
				}
			}
			cout << maxLen / 2 << endl;
		}
	}
};

int main() {
	HUAWEI_HJ32* hj32 = new HUAWEI_HJ32;
	hj32->solution_1();
	return 0;
}
#endif