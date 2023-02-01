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
#include <numeric>      // std::iot
#include<math.h>

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

#if 0
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

#if 0
class Solution_1784_day_20221003 {
public:
	// 寻找01串
	bool checkOnesSegment_0(string s) {
		return s.find("01") == string::npos;
	}
	bool checkOnesSegment_1(string s) {
		bool zero = false;
		for (int i = 0, n = s.size(); i < n; ++i) {
			if (s[i] == '1') {
				if (zero) {
					return false;
				}
			} else {
				zero = true;
			}
		}
		return true;
	}

	// 模拟


};

void main() {
	string s = { "110" };
	Solution_1784_day_20221003* sol = new Solution_1784_day_20221003;
	//cout << sol->checkOnesSegment_0(s);
	cout << sol->checkOnesSegment_1(s);
}
#endif

#if 0
class Solution_811_day_20221005 {
public:
	// 哈希表
	vector<string> subdomainVisits(vector<string>& cpdomains) {
		unordered_map<string, int> mp;
		for (string s : cpdomains) {
			int pos = s.find(' '), cnt = stoi(s.substr(0, pos));
			while (pos != -1) {
				mp[s.substr(pos + 1)] += cnt;
				// 不断更行pos
				pos = s.find(".", pos + 1);
			}
		}
		vector<string> ans;
		for (auto kv : mp) {
			ans.push_back(to_string(kv.second) + ' ' + kv.first);
		}
		return ans;
	}
};

void main() {
	vector<string> cpdomains = { "9001 discuss.leetcode.com" };
	Solution_811_day_20221005* sol = new Solution_811_day_20221005;
	vector<string> ans = sol->subdomainVisits(cpdomains);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] <<" ";
	}
}
#endif

#if 0
class Solution_1800_day_20221007 {
public:
	// 动态规划
	int maxAscendingSum_0(vector<int>& nums) {
		int res = 0;
		int l = 0;
		while (l < nums.size()) {
			int curSum = nums[l++];
			while (l < nums.size() && nums[l] > nums[l - 1]) {
				curSum += nums[l++];
			}
			res = max(res, curSum);
		}
		return res;
	}

	// 暴力枚举
	int maxAscendingSum_1(vector<int>& nums) {
		int maxSum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			int curSum = nums[i];
			for (int j = i + 1; j < nums.size(); ++j) {
				if (nums[j] > nums[j - 1]) {
					curSum += nums[j];
				}
				else {
					break;
				}
			}
			if (maxSum < curSum) {
				maxSum = curSum;
			}
		}
		return maxSum;
	}
};

void main() {
	vector<int> nums = { 10,20,30,5,10,50 };
	Solution_1800_day_20221007* sol = new Solution_1800_day_20221007;
	cout << sol->maxAscendingSum_0(nums) << endl;
	cout << sol->maxAscendingSum_1(nums) << endl;
}
#endif

#if 0
class Solution_870_day_20221008 {
public:
	// 贪心
	vector<int> advantageCount_0(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		vector<int> idx1(n), idx2(n);
		iota(idx1.begin(), idx1.end(), 0);
		iota(idx2.begin(), idx2.end(), 0);
		sort(idx1.begin(), idx1.end(), [&](int i, int j) {return nums1[i] < nums1[j]; });
		sort(idx2.begin(), idx2.end(), [&](int i, int j) {return nums2[i] < nums2[j]; });
		
		vector<int> ans(n);
		int left = 0, right = n - 1;
		for (int i = 0; i < n; ++i) {
			if (nums1[idx1[i]] > nums2[idx2[left]]) {
				ans[idx2[left]] = nums1[idx1[i]];
				++left;
			}
			else {
				ans[idx2[right]] = nums1[idx1[i]];
				--right;
			}
		}
		return ans;
	}

	vector<int> advantageCount_1(vector<int>& A, vector<int>& B) {
		vector<int> vec;
		sort(A.begin(), A.end());
		for (int i = 0; i < B.size(); ++i) {
			bool flag = false;
			for (int j = 0; j < A.size(); ++j) {
				if (A[j] > B[i]) {
					vec.push_back(A[j]);
					A.erase(A.begin() + j);
					flag = true;
					break;
				}
			}
			if (!flag) {
				vec.push_back(A[0]);
				A.erase(A.begin());
			}
		}
		return vec;
	}
};

void main() {
	vector<int> nums1 = { 2,7,11,15 };
	vector<int> nums2 = { 1,10,4,11 };
	Solution_870* sol = new Solution_870;
	//vector <int> nums_0 = sol->advantageCount_0(nums1, nums2);
	vector <int> nums_1 = sol->advantageCount_1(nums1, nums2);
	//for (int i = 0; i < nums_0.size(); ++i) {
	//	cout << nums_0[i] << " ";
	//}	
	cout << endl;
	for (int i = 0; i < nums_1.size(); ++i) {
		cout << nums_1[i] << " ";
	}
}
#endif

#if 0
class Solution_856_day_20221009 {
public:
	// 栈
	int scoreOfParentheses_0(string s) {
		stack<int> st;
		st.push(0);
		for (auto c : s) {
			if (c == '(') {
				st.push(0);
			}
			else {
				int v = st.top();
				st.pop();
				st.top() += max(2 * v, 1);
			}
		}
		return st.top();
	}

	// 分治 ?
	int scoreOfParentheses_1(string s) {
		if (s.size() == 2) {
			return 1;
		}
		int bal = 0, n = s.size(), len;
		for (int i = 0; i < n; ++i) {
			bal += (s[i] == '('?1:-1);
			if (bal == 0) {
				len = i + 1;
				break;
			}
		}
		if (len == n) {
			return 2 * scoreOfParentheses_1(s.substr(1, n - 2));
		}
		else {
			return scoreOfParentheses_1(s.substr(0, len)) + scoreOfParentheses_1(s.substr(len, n - len));
		}
	}

	// 计算最终分数和
	int scoreOfParentheses_2(string s) {
		int bal = 0, n = s.size(), res = 0;
		for (int i = 0; i < n; ++i) {
			bal += (s[i] == '(' ? 1 : -1);
			if (s[i] == ')' && s[i - 1] == '(') {
				res += 1 << bal;
			}
		}
		return res;
	}

};

void main() {
	string s = {"(())()"};
	Solution_856_day_20221009* sol = new Solution_856_day_20221009;
	//cout << sol->scoreOfParentheses_0(s) << endl;
	//cout << sol->scoreOfParentheses_1(s) << endl;
	cout << sol->scoreOfParentheses_2(s) << endl;
}
#endif

#if 0
class Solution_1790_day_20221011 {
public:
	// 计数统计
	bool areAlmostEqual_0(string s1, string s2) {
		int n = s1.size();
		vector<int> diff;
		for (int i = 0; i < n; ++i) {
			if (s1[i] != s2[i]) {
				diff.emplace_back(i);
			}
		}
		if (diff.size() == 0) 
		{ 
			return true; 
		}
		if (diff.size() != 2) {
			return false;
		}
		return s1[diff[0]] == s2[diff[1]] && s1[diff[1]] == s2[diff[0]];
	}
};

void main() {
	Solution_1790_day_20221011* sol = new Solution_1790_day_20221011;
	string s1 = { "bank" }, s2 = { "kanb" };
	//string s1 = { "attack" }, s2 = { "defend" };
	cout << sol->areAlmostEqual_0(s1, s2) << endl;
}
#endif

#if 0
class Solution_904_day_20221017 {
public:
	// 滑动窗口(wrong)
	int totalFruit_0(vector<int>& fruits) {
		int left = 0, right = 0;
		set<int> bucket_set;
		int max_bucket_size = INT_MIN;
		while (left != fruits.size() - 1) {
			bucket_set.insert(fruits[right]);
			if (bucket_set.size() == 3) {
				right = left;
				bucket_set.clear();
			}
			else {
				max_bucket_size = max(max_bucket_size, right - left);
			}
			right++;
			if (right >= fruits.size()- left) {
				right = ++left;
			}
			
		}
		return max_bucket_size;
	}

	// 滑动窗口(right)
	int totalFruit_1(vector<int>& fruits) {
		int n = fruits.size();
		unordered_map<int, int> cnt;

		int left = 0, ans = 0;
		for (int right = 0; right < n; ++right) {
			++cnt[fruits[right]];
			while (cnt.size() > 2) {
				auto it = cnt.find(fruits[left]);
				--it->second;
				if (it->second == 0) {
					cnt.erase(it);
				}
				++left;
			}
			ans = max(ans, right - left + 1);
		}
		return ans;
	}
};

void main() {
	Solution_904_day_20221017* sol = new Solution_904_day_20221017;
	//vector<int> fruits = { 1,2,1 };
	vector<int> fruits = { 0,1,2,2 };
	cout << sol->totalFruit_1(fruits) << endl;
}
#endif

#if 0
class Solution_902_day_20221018 {
public:
	// 数位DP
	/*
	1. 如果我们生成的数字的位数 是 小于 n的位数的话
	如果生成的数字有i位的话，那么就有digits.size()^i

	2. 我们生成的数字 位数 和 n的位数相同
		n = 7386 1 3 5 7 => rev(n):6837 num[0-3]
		n = 7133 1 3 5 7
	*/
	int power(int a, int b) {
		int res = 1;
		while (b--) res *= a;
		return res;
	}
	int atMostNGivenDigitSet_0(vector<string>& digits, int n) {
		// n转为字符串，截取每位数字
		string num = to_string(n);
		reverse(num.begin(), num.end());
		int res = 0;
		// 	1. 如果我们生成的数字的位数 是 小于 n的位数的话
		//	   如果生成的数字有i位的话，那么就有digits.size() ^ i
		for (int i = 1; i < num.size(); i++) res += power(digits.size(), i);

		// 2. 我们生成的数字 位数 和 n的位数相同
		//	  n = 7386 1 3 5 7 = > rev(n) :6837 num[0 - 3]
		//	  n = 7133 1 3 5 7
		bool flag = true;
		for (int i = num.size() - 1; i >= 0; i--) {
			int x = num[i] - '0';
			int cnt = power(digits.size(), i);
			int j;
			for (j = 0; j < digits.size(); j++) {
				if (digits[j][0] - '0' < x) {
					res += cnt;
				}
				else {
					break;
				}
			}
			if (j < digits.size() && digits[j][0] - '0' == x) continue;
			flag = false;
			break;
		}
		if (flag) res++;
		return res;
	}
};

void main() {
	vector<string> digits = { "1", "3", "5", "7" };
	int n = 100;
	Solution_902_day_20221018* sol = new Solution_902_day_20221018;
	cout << sol->atMostNGivenDigitSet_0(digits, n) << endl;
}
#endif

#if 0
class Solution_1700_day_20221019 {
public:
	// 计数器运用题
	int countStudents_0(vector<int>& students, vector<int>& sandwiches) {
		// sandwiches 入栈
		stack<int> sandwiches_t;
		for (auto it = sandwiches.rbegin(); it != sandwiches.rend(); it ++) {
			sandwiches_t.push(*it);
		}
		// students 入队列
		queue<int> students_q;
		for (auto it = students.begin();it!=students.end();it++) {
			students_q.push(*it);
		}

		clock_t start = clock();
		while (clock() - start < 1500 && !students_q.empty()) {
			int cur = students_q.front();
			students_q.pop();
			if (cur == sandwiches_t.top()) {
				sandwiches_t.pop();
			}
			else {
				students_q.push(cur);
			}
		}
		return students_q.size();
	}

	// 模拟
	int countStudents_1(vector<int>& students, vector<int>& sandwiches) {
		int s1 = accumulate(students.begin(), students.end(), 0 );
		int s0 = students.size() - s1;
		for (int i = 0; i < sandwiches.size(); i++) {
			if (sandwiches[i] == 0 && s0 > 0) {
				s0--;
			}
			else if (sandwiches[i] == 1 && s1 > 0) {
				s1--;
			}
			else {
				break;
			}
		}
		return s1 + s0;

	}
};

void main() {
	Solution_1700_day_20221019* sol = new Solution_1700_day_20221019;
	vector<int> students = { 1,1,0,0 };
	vector<int> sandwiches = { 0 , 1, 0 ,1 };
	cout << sol->countStudents_0(students, sandwiches);
}
#endif

#if 0
class Solution_779_day_20221020 {
public:
	// 找规律 + 递归
	int kthGrammar_0(int n, int k) {
		if (n == 1) {
			return 0;
		}
		if (k > (1 << (n - 2))) {
			return 1 ^ (kthGrammar_0(n - 1, k - (1 << (n - 2))));
		}
		return kthGrammar_0(n - 1, k);
	}

	// 找规律 + 位运算
	int kthGrammar_1(int n, int k) {
		k--;
		int res = 0;
		while (k > 0) {
			k &= k - 1;
			res ^= 1;
		}
		return res;
	}
};

void main() {
	Solution_779_day_20221020* sol = new Solution_779_day_20221020;
	int n = 2, k = 2;
	cout << sol->kthGrammar_0(n, k) << endl;
	cout << sol->kthGrammar_1(n, k) << endl;

}
#endif

#if 0
/*
                -  
      - 
    -         -
  -     -   -
-         - 
1 2 3 4 5 6 7 8 9
*/
/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
class Solution_901_day_20221021 {
private :
	stack<pair<int, int>> stk;
	int idx;
public:
	// 单调栈
	Solution_901_day_20221021() {
		this->stk.emplace(-1, INT_MAX);
		this->idx = -1;

	}

	int next(int price) {
		idx++;
		while (price >= stk.top().second) {
			stk.pop();
		}
		int ret = idx - stk.top().first;
		stk.emplace(idx, price);
		return ret;
	}
};

void main() {
	Solution_901_day_20221021* sol = new Solution_901_day_20221021;
	cout << sol->next(NULL) << endl;
	cout << sol->next(100) << endl;
	cout << sol->next(80)<< endl;
	cout << sol->next(60)<< endl;
	cout << sol->next(70)<< endl;
	cout << sol->next(60)<< endl;
	cout << sol->next(75)<< endl;
	cout << sol->next(85)<< endl;

}
#endif

#if 0
class Solution_915_day_20221024 {
public:
	// 两次遍历
	int partitionDisjoint_0(vector<int>& nums) {
		int n = nums.size();
		vector<int> minRight(n);
		minRight[n - 1] = nums[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			minRight[i] = min(nums[i], minRight[i + 1]);
		}
		int maxLeft = 0;
		for (int i = 0; i < n - 1; i++) {
			maxLeft = max(maxLeft, nums[i]);
			if (maxLeft <= minRight[i + 1]) {
				return i + 1;
			}
		}
		return n - 1;
	}

	// 一次遍历
	int partitionDisjoint_1(vector<int>& nums) {
		int n = nums.size();
		int leftMax = nums[0], leftPos = 0, curMax = nums[0];
		for (int i = 1; i < n - 1; i++) {
			curMax = max(curMax, nums[i]);
			if (nums[i] < leftMax) {
				leftMax = curMax;
				leftPos = i;
			}
		}
		return leftPos + 1;
	}
};

void main() {
	Solution_915_day_20221024* sol = new Solution_915_day_20221024;
	vector<int> nums = { 5,0,3,8,6 };
	//cout << sol->partitionDisjoint_0(nums) << endl;
	cout << sol->partitionDisjoint_1(nums) << endl;
}

#endif

#if 0
class Solution_1822_day_20221027 {
public:
	// 暴力枚举
	int arraySign_0(vector<int>& nums) {
		int res = 1;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) {
				return 0;
			}
			res *= nums[i];
		}
		if (res > 0) {
			return 1;
		}
		else {
			return -1;
		}
	}

	// 算负数个数
	int arraySign_1(vector<int>& nums) {
		int negSum = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] == 0) {
				return 0;
			}
			else if (nums[i] < 0) {
				negSum++;
			}
		}
		if (negSum % 2 == 0) {
			return 1;
		}
		else {
			return -1;
		}
	}

	// 取反
	int arraySign_2(vector<int>& nums) {
		int sign = 1;
		for (auto num : nums) {
			if (num == 0) {
				return 0;
			}
			if (num < 0) {
				sign = -sign;
			}
		}
		return sign;
	}
};

void main() {
	Solution_1822_day_20221027* sol = new Solution_1822_day_20221027;
	vector<int> nums = { -1,-2,-3,-4,3,2,1 };
	cout << sol->arraySign_0(nums) << endl;
	cout << sol->arraySign_1(nums) << endl;
	cout << sol->arraySign_2(nums) << endl;
}
#endif

#if 0
class Solution_907_day_20221028 {
public:
	// 单调栈
	int sunSubarrayMins_0(vector<int>& arr) {
		int n = arr.size();
		// 单调栈，求上一个更小元素
		stack<int> stk;
		// dp[i] 表示以i结尾的子数组的最小值之和
		vector<int> dp(n);
		for (int i = 0; i < n; i++) {
			while (!stk.empty() && arr[stk.top()] >= arr[i]) {
				stk.pop();
			}
			// 上一个更小元素
			int preIdx = stk.empty() ? -1 : stk.top();
			stk.push(i);

			if (preIdx == -1) {
				// 如果没有上一个更小元素，则以i结尾的i+1区间的最小值都为arr[i]
				dp[i] = arr[i] * (i + 1);
			}
			else {
				// 如果存在上一个更小元素，则[preIdx,i]之间的所有子区间的最小值都为arr[i]
				dp[i] = dp[preIdx] + arr[i] * (i - preIdx);
			}
		}
		int res = 0;
		long mod = 1e9 + 7;
		for (int cnt : dp) {
			res = (res + cnt) % mod;
		}
		return res;
	}
};

int main() {
	Solution_907_day_20221028* sol = new Solution_907_day_20221028;
	vector<int> arr = { 3,1,2,4 };
	cout << sol->sunSubarrayMins_0(arr) << endl;
}
#endif

#if 0
class Solution_1773_day_20221029 {
public:
	// ?
	int countMatches_0(vector<vector<string>>& items, string ruleKey, string ruleValue) {
		// type color name
		int index;
		if (ruleKey == "type") {
			index = 0;
		}
		else if (ruleKey == "color") {
			index = 1;
		}
		else {
			index = 2;
		}

		unordered_map<string, int> map;
		for (int i = 0; i < items.size(); ++i) {
			++map[items[i][index]];
		}
		return  map.find(ruleValue)->second;
	}

	// 模拟
	int countMatches_1(vector<vector<string>>& items, string ruleKey, string ruleValue) {
		unordered_map<string, int> dic = { {"type",0},{"color",1},{"name",2} };
		int res = 0, index = dic[ruleKey];
		for (auto&& item : items) {
			if (item[index] == ruleValue) {
				res++;
			}
		}
		return res;
	}
};

void main() {
	Solution_1773_day_20221029* sol = new Solution_1773_day_20221029;
	vector<vector<string>> items = { {"phone","blue","pixel"}, {"computer","silver","lenovo"},{"phone","gold","iphone"} };
	//vector<vector<string>> items = { { "phone","blue","pixel"},{"computer","silver","phone"},{"phone","gold","iphone"} };
	string ruleKey = "color";
	string ruleValue = "silver";
	//string ruleKey = "type";
	//string ruleValue = "phone";
	cout << sol->countMatches_0(items, ruleKey, ruleValue);
	cout << sol->countMatches_1(items, ruleKey, ruleValue);
}
#endif

#if 0
class Solution_784_day_20221030 {
	vector<string> res;
	int len;
public:
	// 回溯
	vector<string> letterCasePermutation(string s) {
		this->len = s.size();
		dfs(0, s);
		return res;

	}

	void dfs(int pos, string& s) {
		if (pos == len) {
			res.push_back(s);
			return;
		}

		if (s[pos] >= '0' && s[pos] <= '9') {
			dfs(pos + 1, s);
			return;
		}

		dfs(pos + 1, s);

		if (s[pos] >= 'a' && s[pos] <= 'z') {
			s[pos] -= 32;
		}
		else if (s[pos] >= 'A' && s[pos] <= 'Z') {
			s[pos] += 32;
		}
		dfs(pos + 1, s);
	}
};

void main() {
	Solution_784_day_20221030* sol = new Solution_784_day_20221030;
	string s = "a1b2";
	for (auto it : sol->letterCasePermutation(s)) {
		cout << it << endl;
	}
}
#endif

#if 0
class Sol_481_day_20221031 {
public:
	// 构造字符串
	// 小技巧：字符 '1' 变 '2'，'2' 变 '1' 可以用「异或 3」来实现。
	//	'1' 的 ASCII 码为 49，'2' 的 ASCII 码为 50。
	//	转换为二进制就是 '1' = 0011 0001，'2' = 0011 0010。
	//	可以看到只有最后两位是不同的，而 0 变 1，1 变 0 可以用「异或 1 」来实现。
	//	所以 01 ^ 11 = 10，10 ^ 11 = 01。
	int magicalString_0(int n) {
		string s = "122";
		char c = '1';
		for (int i = 2; i < n; i++) {
			if (s[i] == '1') {
				s += string(1, c);
			}
			else {
				s += string(2, c);
			}
			// c = c == '1' ? '2' : '1';
			c ^= 3;
		}
		return count(s.begin(), s.begin() + n, '1');
	}

	// 边构造边统计
	int magicalString_1(int n) {
		string s = "122";
		char c = '1';
		int i = 2, cnt = 1;
		while (s.size() < n) {
			s += c;
			cnt += c == '1';
			if (s[i] == '2' && s.size() < n) {
				// 如果s[i] 是 2 就多加一个c
				// 如果s.size() == n时，不再统计
				s += c;
				cnt += c == '1';
			}
			i++;
			c ^= 3;
		}
		return cnt;
	}
};

void main() {
	Sol_481_day_20221031* sol = new Sol_481_day_20221031;
	cout << sol->magicalString_0(6) << endl;
	cout << sol->magicalString_1(6) << endl;
}
#endif

#if 0
class Solution_1662_day_20221101 {
public:
	// 字符串拼接
	bool arrayStringsAreEqual_0(vector<string>& word1, vector<string>& word2) {
		string word1_str, word2_str;
		for (auto it : word1) {
			word1_str += it;
		}		
		for (auto it : word2) {
			word2_str += it;
		}
		if (word1_str == word2_str) {
			return true;
		}
		return false;
	}

	// 遍历
	bool arrayStringsAreEqual_1(vector<string>& word1, vector<string>& word2) {
		int p1 = 0, p2 = 0, i = 0, j = 0;
		while (p1 < word1.size() && p2 < word2.size()) {
			if (word1[p1][i] != word2[p2][j]) {
				return false;
			}
			i++;
			if (i == word1[p1].size()) {
				p1++;
				i = 0;
			}
			j++;
			if (j == word2[p2].size()) {
				p2++;
				j = 0;
			}
		}
		return p1 == word1.size() && p2 == word2.size();
	}
};

void main() {
	Solution_1662_day_20221101* sol = new Solution_1662_day_20221101;
	vector<string> word1 = { "ab","c" };
	vector<string> word2 = { "a", "bc" };
	cout << sol->arrayStringsAreEqual_0(word1, word2) << endl;
	cout << sol->arrayStringsAreEqual_1(word1, word2) << endl;
}
#endif

#if 0
class Sol_1620_day_20221102 {
public:
	// 遍历
	vector<int> baseCoordinate_0(vector<vector<int>>& towers, int radius) {
		int maxq = 0, resx = 0, resy = 0;
		for (int i = 0; i < towers.size(); i++) {
			for (int j = 0; j < towers.size(); j++) {
				int quality = 0;
				for (auto tower : towers) {
					int x = tower[0], y = tower[1], q = tower[2];
					int d2 = (x - i) * (x - i) + (y - j) * (y - j);
					if (d2 <= radius * radius) {
						quality += (int)(q / (1 + sqrt(d2)));
					}
				}

				//int origin_x = towers[i][0], origin_y = towers[i][1];
				//int des_x = towers[j][0], des_y = towers[j][1];
				//int dis = (des_x - origin_x) * (des_x - origin_x) + (des_y - origin_y) * (des_y - origin_y);
				//if (dis <= radius * radius) {
				//	quality += (int)(towers[j][2] / (1 + sqrt(dis)));
				//}
				if (maxq < quality) {
					maxq = quality;
					resx = i;
					resy = j;
				}
			}
		}
		return { resx, resy };
	}
};

void main() {
	Sol_1620_day_20221102* sol = new Sol_1620_day_20221102;
	vector<vector<int>> towers = { {1,2,5},{2,1,7},{3,1,9} };
	int radius = 2;
	auto res = sol->baseCoordinate_0(towers, radius);
	for (auto it : res) {
		cout << it << endl;
	}
}

#endif


#if 0
class Solution_1668_day_20221103 {
public:
	// 简单枚举
	int maxRepeating_0(string sequence, string word) {
		int ans = 0;
		string t = word;
		int x = sequence.size() / word.size();
		for (int k = 1; k <= x; ++k) {
			// 从小到大枚举重复值
			if (sequence.find(t) != string::npos) {
				ans = k;
			}
			t += word;
		}
		return ans;
	}
};

void main() {
	Solution_1668_day_20221103* sol = new Solution_1668_day_20221103;
	//string sequence = "ababc", word = "ab";
	string sequence = "ababc", word = "ba";
	cout << sol->maxRepeating_0(sequence, word);
}
#endif

#if 0
class Sol_754_day_20221104 {
public:

	// 分析+数学
	int reachNumber(int target) {
		target = abs(target);
		int k = 0;
		while (target > 0) {
			k++;
			target -= k;
		}
		return target % 2 == 0 ? k : k + 1 + k % 2;
	}
};

void main() {
	Sol_754_day_20221104* sol = new Sol_754_day_20221104;
	cout << sol->reachNumber(2) << endl;
}
#endif

#if 0
class Sol_1971_day_20221219 {
public:
	// 广度优先搜索
	bool validPath_0(int n, vector<vector<int>>& edges, int source, int destination) {
		vector<vector<int>> adj(n);
		for (auto&& edge : edges) {
			int x = edge[0], y = edge[1];
			adj[x].emplace_back(y);
			adj[y].emplace_back(x);
		}
		vector<bool> visited(n, false);
		queue<int> qu;
		qu.emplace(source);
		visited[source] = true;
		while (!qu.empty()) {
			int vertex = qu.front();
			qu.pop();
			if (vertex == destination) {
				break;
			}
			for (int next : adj[vertex]) {
				if (!visited[next]) {
					qu.emplace(next);
					visited[next] = true;
				}
			}
		}
		return visited[destination];
	}

	// 深度优先搜索
	bool validPath_1(int n, vector<vector<int>>& edges, int source, int destination) {
		vector<vector<int>> adj(n);
		for (auto& edge : edges) {
			int  x = edge[0], y = edge[1];
			adj[x].emplace_back(y);
			adj[y].emplace_back(x);
		}
		vector<bool> visited(n, false);
		return dfs(source, destination, adj, visited);
	}

	bool dfs(int source, int destination, vector<vector<int>>& adj, vector<bool>& visited) {
		if (source == destination) {
			return true;
		}
		visited[source] = true;
		for (int next : adj[source]) {
			if (!visited[next] && dfs(next, destination, adj, visited)) {
				return true;
			}
		}
		return false;
	}
};

void main() {
	Sol_1971_day_20221219* sol = new Sol_1971_day_20221219;
	vector<vector<int>> edges = { {0,1},{1,2},{2,0} };
	int n=3, source = 0, destination = 2;
	cout << sol->validPath_0(n, edges, source, destination) << endl;
	cout << sol->validPath_1(n, edges, source, destination) << endl;
	
}
#endif

#if 0
// 不同变量共享同一地址空间
int main() {
	int x = 5;
	int* p1 = &x;
	int* p2 = &x;
	*p1 = 10;
	std::cout << *p2 << std::endl;
	return 0;
}
#endif