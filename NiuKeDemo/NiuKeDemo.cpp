// NiuKeDemo.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <sstream>
#include <regex>
#include <forward_list>
#include <set>
#include <stack>
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

#if 0
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

#if 0
class HUAWEI_HJ33 {
public:
	int solution_1() {
		unsigned int a, b, c, d,shi;// 10.0.3.193
		// int 32 1正负数
		//long a, b, c, d,shi;// 10.0.3.193

		char dot;
		while (cin >> a >> dot >> b >> dot >> c >> dot >> d) {
			cout << (a << 24) + (b << 16) + (c << 8) + d << endl;

			// 输入十进制
			cin >> shi;
			cout << ((shi & 0xff000000) >> 24) << '.' <<  ((shi & 0x00ff0000)>> 16) << '.' << ((shi & 0x0000ff00) >> 8) << '.' <<  (shi & 0x000000ff) << endl;

		}
		return 0;
	}

	/*
	2^n			<——>		1 << n;
	a * 2^n		<——>		a << n;
	a / 2^n		<——>		a >> n;
	a % 2^n		<——>		a & ((1 << n) - 1);
	*/
	const int BYTE = 8;

	unsigned int str2uint(const string& s) {
		unsigned int ret = 0;
		stringstream ss;
		ss << s;
		ss >> ret;
		ss.clear();
		return ret;
	}

	string uint2str(unsigned int n) {
		string ret = "";
		stringstream ss;
		ss << n;
		ss >> ret;
		ss.clear();
		return ret;
	}

	unsigned int ip2uint(string& s) {
		unsigned int ans = 0;
		for (char* p = strtok((char*)s.data(), "."); p; p = strtok(NULL,".")) {
			ans = (ans << BYTE) + str2uint(p);
		}
		return ans;
	}

	string uint2ip(unsigned int n) {
		string ans;
		for (int i = 4; i > 0; --i) {
			ans = (i == 1 ? "" : ".") + uint2str(n & ((1 << BYTE) - 1)) + ans;
			n >>= BYTE;
		}
		return ans;
	}

	bool is_ip(const string& s) {
		regex res("\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}");
		return regex_match(s, res);
	}

	int solution_2() {
		string in;
		while (getline(cin, in)) {
			if (is_ip(in)) {
				cout << ip2uint(in) << endl;
			}
			else {
				cout << uint2ip(str2uint(in)) << endl;
			}
		}
		return 0;
	}
};

int main() {

	return 0;
}

#endif

#if 0
// https://www.nowcoder.com/practice/e4af1fe682b54459b2a211df91a91cf3

class HUAWEI_HJ36 {
public:
	void Solution_1() {
		string sKey, sStr;
		while (getline(cin, sKey) && getline(cin, sStr)) {
			// key中大写变为小写
			for (int i = 0; i < sKey.size(); i++) {
				if (isupper(sKey[i])) {
					sKey[i] += 32;
				}
			}
			// set记录有多少个元素
			unordered_set<char> set;
			for (int i = 0; i < sKey.size(); i++) {
				set.insert(sKey[i]);
			}
			// 输入不重样字符的key
			vector<char> arr(26);
			int j = 0;
			for (int i = 0; i < sKey.size(); i++) {
				int flag = 0;
				for (char c : arr) {
					if (c == sKey[i]) {
						flag = 1;
					}
				}
				if (flag == 1) {
					arr[j++] = sKey[i];
				}
			}
			// 输入剩余字符
			for (int i = 0; i < 26; i++) {
				if (set.count('a' + i) == 0) {
					arr[j++] = 'a' + i;
				}
			}
			// 输出
			string ans;
			for (int i = 0; i < sStr.size(); i++) {
				if (isupper(sStr[i])) {
					ans += (arr[sStr[i] - 'A'] - 'a' + 'A');
					continue;
				}
				else if (islower(sStr[i])) {
					ans += arr[sStr[i] - 'a'];
					continue;
				}
				else {
					ans += sStr[i];
				}
			}
			cout << ans << endl;
		}
	}
};

int main() {
	HUAWEI_HJ36* hj36 = new HUAWEI_HJ36;
	hj36->Solution_1();
	return 0;
}
#endif

#if 0
// https://www.nowcoder.com/practice/2f6f9339d151410583459847ecc98446

class HUAWEI_HJ38 {
public:
	void Solution_1() {
		float height = 0; // 小球初始高度
		
		cin >> height;
		float sum = 0;
		for (int i = 0; i < 5; i++) {
			sum += height;
			height /= 2;
			sum += height;
		}
		cout << sum - height << endl << height / 2;
	}

	int Solution_2() {
		int a1;
		cin >> a1;
		cout << a1 * 23.0 / 8 << endl;
		cout << a1 / 32.0 << endl;
		return 0;
	}
};

int main() {
	HUAWEI_HJ38* hj38 = new HUAWEI_HJ38;
	hj38->Solution_1();
	return 0;
}

#endif

#if 0
// https://www.nowcoder.com/practice/f9a4c19050fc477e9e27eb75f3bfd49c

class HUAWEI_HJ41 {
public:
	int DP_ForWeightProblem(void) { // 01背包+DP
		int kinds; // the kinds of weights
		cin >> kinds;
		vector<int> weight(kinds, 0); // the weight of each weight
		vector<int> amount(kinds, 0); // the amount of each weight
		int total_weight = 0; // the total weight of all the weights
		for (int i = 0; i < kinds; i++) {
			cin >> weight[i];
		}
		for (int i = 0; i < kinds; i++) {
			cin >> amount[i];
			total_weight += amount[i] * weight[i];
		}
		vector<bool> dp(total_weight + 1, false);
		dp[0] = true;
		vector<int> combinations(1, 0);
		combinations.reserve(100);// 申请100个元素的内存空间
		for (int i = 0; i < kinds; i++) {
			int i_weight = weight[i];
			for (int j = 0; j < amount[i]; j++) {
				int cur_size = combinations.size();
				for (int k = 0; k < cur_size; k++) {
					int temp = i_weight + combinations[k];
					if (!dp[temp]) {
						combinations.push_back(i_weight + combinations[k]);
						dp[temp] = true;
					}
				}
			}
		}
		return combinations.size();
	}
};

int main() {
	HUAWEI_HJ41* hj41 = new HUAWEI_HJ41;
	cout << hj41->DP_ForWeightProblem() << endl;
	return 0;
}
#endif

#if 0
// https://www.nowcoder.com/practice/cf24906056f4488c9ddb132f317e03bc

int n, m;
vector<vector<int>> maze;
// 当从（0，0）到（n-1，m-1）有多条通路时，best_path记录最小的temp_path
// 本题只有一条通路，所以当到达（n-1,m-1）时，让best_temp = temp_path即可
vector<vector<int>> best_path;
vector<vector<int>> temp_path;

class  HUAWEI_HJ43 {
public:
	void dfs(int i, int j) {
		// 边界条件：1.数据越界 2.“墙壁”或已走过
		if (i < 0 || i >= n || j < 0 || j >= m || maze[i][j] == 1) {
			return;
		}
		maze[i][j] = 1;//该位置已走过标记为1
		temp_path.push_back({i,j});// 将该位置加入路径
		if (i == n - 1 && j == m - 1) { // 走到终点
			// 多条路径时best_path记录最小的temp_path
			//if (temp_path.size() < best_path.size() || best_path.empty()) {
				//best_path = temp_path;
			//}
			best_path = temp_path;
		}
		dfs(i - 1, j); // 上
		dfs(i + 1, j); // 下
		dfs(i, j - 1); // 左
		dfs(i, j + 1); // 右
		maze[i][j] = 0;// 该节点走不通时，恢复原场面
		temp_path.pop_back();//从该路径删除该节点
	}
};

int main() {
	HUAWEI_HJ43* hj43 = new HUAWEI_HJ43;
	while (cin >> n >> m) { // 一次测试中多个案例依次输入
		maze = vector<vector<int>>(n, vector<int>(m, 0));//设置地图的大小并初始化
		// 一次测试中多个案例依次输入时，每个案例执行完后将路径容器清空
		best_path.clear();
		temp_path.clear();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> maze[i][j];
			}
		}
		hj43->dfs(0, 0);
		for (vector<vector<int>>::iterator it = best_path.begin(); it != best_path.end(); it++) {
			cout << '(' << (*it)[0] << ',' << (*it)[1] << ')' << endl;
		}
	}
	return 0;
}
#endif

#if 0
// https://www.nowcoder.com/practice/02cb8d3597cf416d9f6ae1b9ddc4fde3

bool cmp1(pair<char, int> a, pair<char, int> b) { // 自定义比较函数
	return a.second > b.second;
}

class HUAWEI_HJ45 {

public:
	int beautility(string str) { // 计算漂亮度函数
		vector<int> vec;
		string tmp(str); // 字符串tmp保存字符串str的副本
		sort(str.begin(), str.end());
		str.erase(unique(str.begin(), str.end()),str.end()); // 对输入字符串str去重
		for (char c : str) {
			int count = 0;
			for (int i = 0; i < tmp.length(); i++) { // 计算字符串tmp中每种字符出现的次数
				if (c == tmp[i]) {
					count++;
				}
			}
			vec.push_back(count); // 容器vec保存每个字符出现的次数
		}
		vector<pair<char, int>> vec_pair; // 容器vec_pair记录每个字符及该字符出现的次数
		for (int i = 0; i < vec.size(); i++) {
			vec_pair.push_back(make_pair(str[i], vec[i]));
		}
		sort(vec_pair.begin(), vec_pair.end(), cmp1); // 按字符出现次数从大到小对容器vec_pair进行排序
		for (int i = 0; i < vec_pair.size(); i++) {
			vec_pair[i].second = 26 - i; // 要使漂亮度最大，就要使出现次数最多的字符漂亮度的值最大
		}
		int beautility = 0; //  保存输入字符串的最大漂亮度
		for (char c : tmp) {
			for (int i = 0; i < vec_pair.size(); i++) {
				if (c == vec_pair[i].first) {
					beautility += vec_pair[i].second; //累加字符串中每个字符的漂亮度
				}
			}
		}
		return beautility; // 返回输入字符串的漂亮度
	}
};

int main() {
	HUAWEI_HJ45* hj45 = new HUAWEI_HJ45;
	int n;
	while (cin >> n) {
		vector<string> vec;
		string str;
		for (int i = 0; i < n; i++) {
			cin >> str;
			vec.push_back(str);
		}
		for (int i = 0; i < n; i++) {
			cout << hj45->beautility(vec[i]) << endl;
		}
	}
	return 0;
}
#endif

#if 0
// https://www.nowcoder.com/practice/f96cd47e812842269058d483a11ced4f

class HUAWEI_HJ48 {
public:
	void Solution_1() {
		int n, head;
		cin >> n >> head; // 输入结点数和头结点的值
		forward_list<int> linklist; // 创建一个单向链表
		linklist.push_front(head); // 初始化头结点
		for (int i = 1; i < n; i++) {
			int front, back;
			cin >> back >> front;
			auto it = find(linklist.begin(), linklist.end(), front);
			linklist.insert_after(it, back); // 逐个插入结点
		}
		int last;
		cin >> last; // 输入要删除的结点值
		linklist.remove(last); // 移除具有该值的结点
		for (auto it = linklist.begin(); it != linklist.end(); it++) {
			cout << *it << " "; // 从头到尾输出链表的值
		}
		cout << endl;
	}
};

int main() {
	HUAWEI_HJ48* hj48 = new HUAWEI_HJ48;
	hj48->Solution_1();
	return 0;
}

#endif

#if 0
// https://www.nowcoder.com/practice/9999764a61484d819056f807d2a91f1e

//3 + 2 * {1 + 2 * [-4 / (8 - 6) + 7]}

class HUAWEI_HJ50 {
public:
	int compute(string& s, int left, int right) {
		char op = '+'; // 默认+开始
		int num = 0;
		vector<int> st;
		for (int i = left; i <= right; i++) {
			if (isdigit(s[i])) { // 数字
				num = num * 10 + s[i] - '0'; // 计算该部分数字总和
			}
			if (s[i] == '{' || s[i] == '[' || s[i] == '(') { // 进入左括号
				int layer = 0; // 统计左括号层数
				int j = i;
				while (j <= right) { // 遍历到右边
					if (s[j] == '{' || s[j] == '[' || s[j] == '(') {
						layer++; // 遇到左括号，层数累加
					}
					else if (s[j] == '}' || s[j] == ']' || s[j] == ')') {
						layer--; // 遇到右括号，层数递减
						if (layer == 0) { // 直到层数等于0
							break;
						}
					}
					j++;
				}
				num = compute(s, i + 1, j - 1); // 递归计算括号中的部分
				i = j + 1;
			}
			if (!isdigit(s[i]) || i == right) { // 遇到运算符或者结尾
				switch (op) { // 根据运算符开始计算 
				case '+': st.push_back(num); break; // 加减法加入到末尾
				case '-': st.push_back(-num); break; 
				case '*': st.back() *= num; break; // 乘除法与末尾计算 
				case '/': st.back() /= num; break; 
				}
				op = s[i]; // 修改为下一次的运算符
				num = 0;
			}
		}
		int res = 0;
		for (int x : st) { // 累加和
			res += x;
		}
		return res;
	}
};

int main() {
	HUAWEI_HJ50* hj50 = new HUAWEI_HJ50;
	string s;
	while (cin >> s) {
		cout << hj50->compute(s, 0, s.length() - 1) << endl;
	}
	return 0;
}
#endif

#if 0
// https://www.nowcoder.com/practice/3959837097c7413a961a135d7104c314

int f[1001][1001]; // s1中前i个字符与s2中前j个字符的编辑距离

class HUAWEI_HJ52 {
public:
	int Distance_1(string s1, string s2) {
		int n = s1.length(), m = s2.length();
		// 初始化f
		for (int i = 0; i < n; i++) {
			f[i][0] = i; // 要使s1中前i个字符与s2前0个字符相同，只能删除s1前i个
		}
		for (int j = 0; j < m; j++) {
			f[0][j] = j; // 同上，要使s1中前0个字符与s2前j个字符相同，只能s1增加j个
		}

		for (int i = 1; i < n; i++) { // 在输入字符串前加个‘ ’，所以是1~n
			for (int j = 1; j < m; j++) { // 同上
				f[i][j] = min(f[i - 1][j] + 1, f[i][j - 1] + 1); //  增加or删除
				if (s1[i] != s2[j]) {
					f[i][j] = min(f[i][j], f[i - 1][j - 1] + 1); // or 替换
				}
				else {
					f[i][j] = min(f[i][j], f[i - 1][j - 1]);
				}
			}
		}
		return f[n - 1][m - 1];
	}

	int Distance_2(string s1, string s2) {
		vector<int> dp(s2.size() + 1, 0);
		for (int i = 0; i <= s2.size(); i++) { // 初始化第一行
			dp[i] = i;
		}
		for (int i = 1; i < s1.size(); i++) {
			dp[0] = i; // 初始化dp[0],i->0需要i个删除操作
			int l = dp[0] - 1;
			for (int j = 1; j <= s2.size(); j++) {
				int curr = dp[j]; // 保留当前的值，作为dp[j+1]的左上角值
				dp[j] = min(min(dp[j] + 1, dp[j - 1] + 1), ((s1[i - 1] == s2[j - 1]) ? 0 : 1) + 1);
				l = curr; // 更新左上角值
			}
		}
		return dp[s2.size()];
	}

	int Distance_3(string s1, string s2) {
		vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
		for (int i = 1; i <= s2.size(); i++) { // s1从0个字符变成s2的i个字符需要i个插入操作
			dp[0][i] = i;
		}
		for (int i = 1; i < s1.size(); i++) { // s1从i个字符变成s2的0个字符也需要i个删除操作
			dp[i][0] = i;
		}
		for (int i = 1; i <= s1.size(); i++) {
			for (int j = 1; j <= s2.size(); j++) {
				int op1 = dp[i - 1][j] + 1;// 删除字符s1[i-1]
				int op2 = dp[i][j - 1] + 1; // 删除字符s2[j-1]
				int op3 = dp[i - 1][j - 1]; // 替换操作
				if (s1[i - 1] != s2[j - 1]) {
					op3++;
				}
				dp[i][j] = min(min(op1, op2) ,op3); // 替换操作和删除操作取最小
			}
		}
		return dp[s1.size()][s2.size()];
	}

};

int main() {
	HUAWEI_HJ52* hj52 = new HUAWEI_HJ52;
	string s1, s2;
	cin >> s1;
	s1 = ' ' + s1; // 小tip，在s前面加一个' '，之后计算编辑距离可以从下标1开始
	cin >> s2;
	s2 = ' ' + s2;
	cout << hj52->Distance_3(s1, s2) << endl;
	return 0;
}


#endif

#if 0
/*
1.
汽水瓶
某商店规定：三个空汽水瓶可以换一瓶汽水，允许向老板借空汽水瓶（但是必须要归还）。
小张手上有n个空汽水瓶，她想知道自己最多可以喝到多少瓶汽水。
数据范围：输入的正整数满足
1
≤
�
≤
100

1≤n≤100

注意：本题存在多组输入。输入的 0 表示输入结束，并不用输出结果。
时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32M，其他语言64M
输入描述：
输入文件最多包含 10 组测试数据，每个数据占一行，仅包含一个正整数 n（ 1<=n<=100 ），表示小张手上的空汽水瓶数。n=0 表示输入结束，你的程序不应当处理这一行。

输出描述：
对于每组测试数据，输出一行，表示最多可以喝的汽水瓶数。如果一瓶也喝不到，输出0。

示例1
输入例子：
3
10
81
0
输出例子：
1
5
40
例子说明：
样例 1 解释：用三个空瓶换一瓶汽水，剩一个空瓶无法继续交换
样例 2 解释：用九个空瓶换三瓶汽水，剩四个空瓶再用三个空瓶换一瓶汽水，剩两个空瓶，向老板借一个空瓶再用三个空瓶换一瓶汽水喝完得一个空瓶还给老板

*/
class HUAWEI_REAL_20230414_1 {
public:
	// 错误答案
	void Solution_1() {
		int num_nullcup = 0;
		vector<int> res;
		while (cin >> num_nullcup) {
			if (num_nullcup <= 0) break; // 输入0或负数直接返回
			int num_fullcup = 0; // 空汽水数量
			int num_lastcup = 0; // 
			while (num_nullcup / 3 > 0) {
				num_nullcup -= 3; num_lastcup++; num_fullcup++;
				if (num_nullcup < 3) {
					num_lastcup += num_nullcup % 3;
				}
				if (num_lastcup / 3 > 0 || num_lastcup == 2) {
					num_lastcup -= 3; num_fullcup++; num_lastcup++;
				}

			}
			res.push_back(num_fullcup);
		}
		for (auto it : res) {
			cout << it << endl;
		}
	}

	void Solution_2() {
		int n;
		vector<int> res;
		while (cin >> n && n != 0) { // 循环读入n，直到n为0
			int ans = 0; // 定义答案变量
			while (n >= 3) { // 当n>=3时可以继续兑换
				ans += n / 3; // 计算当前可以兑换的汽水瓶数量
				n = n / 3 + n % 3; // 更新剩余的空汽水瓶数量
			}
			if (n == 2) ans++; // 如果还剩2个空瓶，可以向老板借一个再兑换一瓶汽水
			res.push_back(ans);
		}
		for (auto it : res) {
			cout << it << endl;
		}
	}
};

/*
2.
明明的随机数
明明生成了
�
N个1到500之间的随机整数。请你删去其中重复的数字，即相同的数字只保留一个，把其余相同的数去掉，然后再把这些数从小到大排序，按照排好的顺序输出。

数据范围：
1
≤
�
≤
1000

1≤n≤1000  ，输入的数字大小满足
1
≤
�
�
�
≤
500

1≤val≤500
时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32M，其他语言64M
输入描述：
第一行先输入随机整数的个数 N 。
接下来的 N 行每行输入一个整数，代表明明生成的随机数。
具体格式可以参考下面的"示例"。
输出描述：
输出多行，表示输入数据处理后的结果

示例1
输入例子：
3
2
2
1
输出例子：
1
2
例子说明：
输入解释：
第一个数字是3，也即这个小样例的N=3，说明用计算机生成了3个1到500之间的随机整数，接下来每行一个随机数字，共3行，也即这3个随机数字为：
2
2
1
所以样例的输出为：
1
2
*/
class HUAWEI_REAL_20230414_2 {
public:
	void Solution_1() {
		int N; // 随机整数的个数
		cin >> N;
		int i = 0;
		vector<int> nums;
		int temp;
		while (i < N) {
			cin >> temp;
			nums.push_back(temp);
			i++;
		}
		set<int> s(nums.begin(), nums.end()); // 利用set去重
		vector<int> new_nums(s.begin(), s.end()); // 将去重后的数字存入到新的vector容器中
		sort(new_nums.begin(), new_nums.end()); // 对新的vector容器进行排序

		for (auto it : new_nums) {
			cout << it << endl;
		}
		
	}
};

/*
3.
进制转换
写出一个程序，接受一个十六进制的数，输出该数值的十进制表示。

数据范围：保证结果在
1
≤
�
≤
2
31
−
1

1≤n≤2
31
 −1
时间限制：C/C++ 1秒，其他语言2秒
空间限制：C/C++ 32M，其他语言64M
输入描述：
输入一个十六进制的数值字符串。

输出描述：
输出该数值的十进制字符串。不同组的测试用例用\n隔开。

示例1
输入例子：
0xAA
输出例子：
170
*/
class HUAWEI_REAL_20230414_3 {
public:
	void Solution_1(){
		string hex_str; // 十六进制数的字符串
		cin >> hex_str;
		int hex_str_len = hex_str.length(); // 十六进制位数

		int dec_num = 0; // 十进制整数
		for (int i = 0; i < hex_str_len; i++) {
			char ch = hex_str[i]; // 取十六进制的每个字符
			int digit; // 存字符对应的数值
			if (ch >= '0' && ch <= '9') {
				digit = ch - '0'; // 数字 -》 数字
			}
			else if (ch >= 'A' && ch <= 'F') {
				digit = ch - 'A' + 10; // 大写字母A:55 -》 数值
			}
			else if (ch >= 'a' && ch <= 'f') {
				digit = ch - 'a' + 10; // 小写字母a:97 -》数值
			}
			else {
				// 如果不是有效的十六进制数，则输出错误信息并退出程序
				cerr << "Invalid hex string" << endl;
			}
			dec_num += (digit * pow(16, hex_str_len - i - 1)); // 根据权值计算对应的十进制数
		}
		cout << dec_num << endl;
	}
};



int main() {
	//HUAWEI_REAL_20230414_1* hr1 = new HUAWEI_REAL_20230414_1;
	//hr1->Solution_2();

	//HUAWEI_REAL_20230414_2* hr2 = new HUAWEI_REAL_20230414_2;
	//hr2->Solution_1();

	HUAWEI_REAL_20230414_3* hr3 = new HUAWEI_REAL_20230414_3;
	hr3->Solution_1();


	return 0;
}

#endif

#if 1
class Solution_HJ55 {
public:
	bool ifSev(int num) {
		while (num > 0) {
			if (num % 10 == 7) {
				return true;
			}
			num /= 10;
		}
		return false;
	}

	int with7(int n) {
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (i % 7 == 0) {
				ans++;
				continue;
			}
			if (ifSev(i)) {
				ans++;
			}
		}
		return ans;
	}
};

int main() {
	Solution_HJ55* sol = new Solution_HJ55;
	int n;
	while (cin >> n) {
		cout << sol->with7(n) << endl;
	}
	return 0;
}
#endif