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

#if 0
/* 
编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。
示例 1：
输入：
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
输出：
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
*/
class Solution_day_20220930 {
public:
	// 使用标记数组
	void setZeroes_0(vector<vector<int>>& matrix) {
		int row_size = matrix.size();
		int column_size = matrix[0].size();
		vector<int> row(row_size), col(column_size);
		for (int i = 0; i < row_size; ++i) {
			for (int j = 0; j < column_size; ++j) {
				if (matrix[i][j] == 0) {
					row[i] = col[j] = true;
				}
			}
		}

		for (int i = 0; i < row_size;++i) {
			for (int j = 0; j < column_size;++j) {
				if (row[i] || col[j]) {
					matrix[i][j] = 0;
				}
			}
		}
	}

	// 使用两个标记变量
	void setZeroes_1(vector<vector<int>>& matrix) {
		int row_size = matrix.size();
		int column_size = matrix[0].size();
		int flag_col0 = false, flag_row0 = false;
		for (int i = 0; i < row_size; ++i) {
			if (matrix[i][0] == 0) {
				flag_col0 = true;
			}
		}		
		for (int j = 0; j < column_size; ++j) {
			if (matrix[0][j] == 0) {
				flag_row0 = true;
			}
		}

		for (int i = 1; i < row_size; ++i) {
			for (int j = 1; j < column_size; ++j) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = matrix[0][j] = 0;
				}
			}
		}

		for (int i = 1; i < row_size; ++i) {
			for (int j = 1; j < column_size; ++j) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
			}
		}

		if (flag_col0) {
			for (int i = 0; i < row_size; ++i) {
				matrix[i][0] = 0;
			}
		}

		if (flag_row0) {
			for (int j = 0; j < column_size; ++j) {
				matrix[0][j] = 0;
			}
		}
	}

	// 使用一个标记变量
	void setZeroes_2(vector<vector<int>>& matrix) {
		int row_size = matrix.size();
		int column_size = matrix[0].size();
		int flag_col0 = false;
		for (int i = 0; i < row_size; ++i) {
			if (matrix[i][0] == 0) {
				flag_col0 = true;
			}
			for (int j = 1; j < column_size; ++j) {
				if (matrix[i][j] == 0) {
					matrix[i][0] = matrix[0][j] = 0;
				}
			}
		}

		for (int i = row_size - 1; i >= 0; --i) {
			for (int j = 1; j < column_size; ++j) {
				if (matrix[i][0] == 0 || matrix[0][j] == 0) {
					matrix[i][j] = 0;
				}
			}
			if (flag_col0) {
				matrix[i][0] = 0;
			}
		}

	}
};

void main() {
	vector<vector<int>> matrix = { {1,1,1},{1,0,1},{1,1,1} };
	Solution_day_20220930* sol = new Solution_day_20220930;
	//sol->setZeroes_0(matrix);
	//sol->setZeroes_1(matrix);
	sol->setZeroes_2(matrix);

	for (int i = 0; i < matrix.size(); ++i) {
		for (int j = 0; j < matrix[0].size(); ++j) {
			cout << matrix[i][j] << " ";
			if (j == 2) {
				cout << endl;
			}
		}
	}

}

#endif

#if 1
/*
给你一个字符串形式的电话号码 number 。number 由数字、空格 ' '、和破折号 '-' 组成。

请你按下述方式重新格式化电话号码。

首先，删除 所有的空格和破折号。
其次，将数组从左到右 每 3 个一组 分块，直到 剩下 4 个或更少数字。剩下的数字将按下述规定再分块：
2 个数字：单个含 2 个数字的块。
3 个数字：单个含 3 个数字的块。
4 个数字：两个分别含 2 个数字的块。
最后用破折号将这些块连接起来。注意，重新格式化过程中 不应该 生成仅含 1 个数字的块，并且 最多 生成两个含 2 个数字的块。
返回格式化后的电话号码。

示例 1：
输入：number = "1-23-45 6"
输出："123-456"
解释：数字是 "123456"
步骤 1：共有超过 4 个数字，所以先取 3 个数字分为一组。第 1 个块是 "123" 。
步骤 2：剩下 3 个数字，将它们放入单个含 3 个数字的块。第 2 个块是 "456" 。
连接这些块后得到 "123-456" 。

示例 2：
输入：number = "123 4-567"
输出："123-45-67"
解释：数字是 "1234567".
步骤 1：共有超过 4 个数字，所以先取 3 个数字分为一组。第 1 个块是 "123" 。
步骤 2：剩下 4 个数字，所以将它们分成两个含 2 个数字的块。这 2 块分别是 "45" 和 "67" 。
连接这些块后得到 "123-45-67" 。
*/

class Solution_1694_day_20221001 {
public:
	string reformatNumber(string number) {
		string digits;
		for (char ch : number) {
			if (isdigit(ch)) {
				digits.push_back(ch);
			}
		}

		int n = digits.size();
		int pt = 0;
		string ans;
		while (n) {
			if (n > 4) {
				ans += digits.substr(pt, 3) + "-";
				pt += 3;
				n -= 3;
			}
			else {
				if (n == 4) {
					ans += digits.substr(pt, 2) + "-" + digits.substr(pt + 2, 2);
				}
				else {
					ans += digits.substr(pt, n);
				}
				break;
			}
		}
		return ans;
	}
};

void main() {
	string number = { "--17-5 229 35-39475 " };
	Solution_1694_day_20221001* sol = new Solution_1694_day_20221001;
	cout << sol->reformatNumber(number) << endl;
}

#endif