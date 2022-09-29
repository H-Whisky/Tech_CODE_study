// OneDayOneQuestion.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
#include <map>

using namespace std;

// 每日一题
#if 0
/*
	20220927
	给定两个字符串 s1 和 s2，请编写一个程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。
	示例 1：
	输入 : s1 = "abc", s2 = "bca"
	输出 : true
	示例 2：
	输入 : s1 = "abc", s2 = "bad"
	输出 : false
*/
class Solution_day_20220927 {
public:


	// 排序
	bool CheckPermutation_0(string s1, string s2) {
		if (s1.length() != s2.length()) {
			return false;
		}

		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());

		return s1 == s2;
	}

	// 哈希表
	bool CheckPermutation_1(string s1, string s2) {
		if (s1.length() != s2.length()) {
			return false;
		}
		vector<int> ans(128, 0);

		for (auto it : s1) {
			ans[it]++;

		}

		for (auto it : s2) {
			ans[it]--;
			if (ans[it] < 0) {
				return false;
			}
		}
		return true;
	}

};

void main() {
	string s1 = { "abcq" };
	string s2 = { "bcaq" };
	Solution_day_20220927* sol_day = new Solution_day_20220927;
	cout << sol_day->CheckPermutation_0(s1, s2) << endl;
	cout << sol_day->CheckPermutation_1(s1, s2) << endl;

}
#endif

#if 0
/*
有些数的素因子只有 3，5，7，请设计一个算法找出第 k 个数。
注意，不是必须有这些素因子，而是必须不包含其他的素因子。
例如，前几个数按顺序应该是 1，3，5，7，9，15，21。

示例 1:
输入: k = 5
输出: 9
*/
class Solution_day_20220928 {
public:
	// 最小堆
	int getKthMagicNumber_0(int k) {
		vector<int> factors = { 3, 5, 7 };
		unordered_set<long> seen;
		// 小顶堆 根小叶大
		priority_queue<long, vector<long>, greater<long>> small_heap;
		// 大顶堆 根大叶小
		//priority_queue<long, vector<long>, less<long>> heap;
		seen.insert(1L);
		small_heap.push(1L);
		int magic = 0;
		for (int i = 0; i < k; i++) {
			long curr = small_heap.top();
			small_heap.pop();
			magic = (int)curr;
			for (int factor : factors) {
				long next = curr * factor;
				if (!seen.count(next)) {
					seen.insert(next);
					small_heap.push(next);
				}
			}
		}
		return magic;
	}

	// 动规
	int getKthMagicNumber_1(int k) {
		vector<int> dp(k + 1);
		dp[1] = 1;
		int p3 = 1, p5 = 1, p7 = 1;
		for (int i = 2; i <= k; ++i) {
			int num3 = dp[p3] * 3, num5 = dp[p5] * 5, num7 = dp[p7] * 7;
			dp[i] = min(min(num3, num5), num7);
			if (dp[i] == num3) {
				p3++;
			}
			if (dp[i] == num5) {
				p5++;
			}
			if (dp[i] == num7) {
				p7++;
			}
		}
		return dp[k];
	}

};

void main() {
	Solution_day_20220928* sol_0928 = new Solution_day_20220928;
	cout << sol_0928->getKthMagicNumber_0(5)<<endl;
	cout << sol_0928->getKthMagicNumber_1(5)<<endl;
}
#endif

#if 0
/*
字符串轮转。给定两个字符串s1和s2，
请编写代码检查s2是否为s1旋转而成（比如，waterbottle是erbottlewat旋转后的字符串）。
示例1:
 输入：s1 = "waterbottle", s2 = "erbottlewat"
 输出：True
示例2:
 输入：s1 = "aa", s2 = "aba"
 输出：False
*/
class Solution_day_20220929 {
public:
	// 模拟
	bool isFlipedString_0(string s1, string s2) {
		int s1_len = s1.length();
		int s2_len = s2.length();
		if (s1_len != s2_len) {
			return false;
		}
		if (s1_len == 0) {
			return true;
		}
		for (int i = 0; i < s1_len; ++i) {
			bool flag = true;
			for (int j = 0; j < s1_len; ++j) {
				if (s1[(i + j) % s1_len] != s2[j]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				return true;
			}
		}
		return false;
	}

	// 搜索子字符串
	int  isFlipedString_1(string s1, string s2) {
		return s1.size() == s2.size() && (s1 + s2).find(s2) != string::npos;
	}

};

void main() {
	Solution_day_20220929* sol = new Solution_day_20220929;
	string s1 = {"waterbottle"};
	string s2 = {"erbottlewat"};
	string s3 = {"aa"};
	string s4 = {"aba"};
	cout << sol->isFlipedString_0(s1, s2) << endl;
	//cout << sol->isFlipedString_0(s3, s4) << endl;
}
#endif