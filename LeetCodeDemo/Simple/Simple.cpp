// Simple.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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

#if 0
class P {
	char nameP[30];
public:
	P(char* name = "123") {
		strcpy(nameP, name);
	}
	char* getName() {
		return nameP;
	}
	virtual char* getType() {
		return "P";
	}
};

class B :public P {
	char nameB[30];
public:
	B(char* n1, char* n2) :P(n1) {
		strcpy(nameB, n2);
	}
	char* getName() {
		return nameB;
	}
	char* getType() {
		return "B";
	}
};

void showP(P* p) {
	cout << p->getType() << ":" << p->getName() << endl;
}

int main() {
	B b("book1", "book2");
	showP(&b);

	return (0);
}
#endif

#if 0
typedef struct object object
struct object {
	char data[3];
};

int main(void) {
	object obj_array[3] = { {'a','b','c'}, {'d','e','f'},{'g','h','i'} };
	object* cur = obj_array;
	printf("%c %c\n", *(char*));
}
#endif

#if 0
class D {
	int d;
public:
	D(int x = 1) :d(x) {};
	~D() {
		std::cout << "D";
	}
};



int main() {
	D d[] = { D(3),D(3),D(3) };
	D* p = new D[2];
	delete[] p;
	//std::cin.get();
	return(0);
}
#endif

#if 0
struct A {
	A(int i) {
		std::cout << "A(int i)" << std::endl;
	}
	A(double d, int i) {}
};

struct B :A {
	using A::A;
	int d{ 0 };
	B(int i) :A{ i }, d{ i } {
		std::cout << "B(int i)" << std::endl;
	}
};

int main() {
	B b(1);
	std::cin.get();
	return (0);
}
#endif

#if 0
int main() {
	uint32_t n = 10110;
	// n&1判断奇数，奇数返1
	std::cout << (n & 1);
}
#endif // DEBUG

#if 0
// 计算32位二进制的汉明重量
int32_t swar(int32_t i)
{
	i = (i & 0x55555555) + ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	i = (i & 0x0F0F0F0F) + ((i >> 4) & 0x0F0F0F0F);
	i = (i * (0x01010101) >> 24);
	return i;
}

int hammingWeight(uint32_t n) {
	int ret = 0;
	for (int i = 0; i < 32; i++) {
		if (n & (1 << i)) {
			ret++;
		}
	}
	return ret;
}

void main() {
	//std::cout << swar(00000000000000000000000000001011) << std::endl;
	//std::cout << hammingWeight(00000000000000000000000000001011) << std::endl;
	
	std::cout << (1 << 0) << std::endl;
	std::cout << (1 << 1) << std::endl;
	std::cout << (1 << 2) << std::endl;
}
#endif // DEBUG

#if 0
int majorityElement(vector<int>& nums) {
	unordered_map<int, int> counts;
	int majority = 0, cnt = 0;
	for (int num : nums) {
		++counts[num];
		if (counts[num] > cnt) {
			majority = num;
			cnt = counts[num];
		}
	}
	return majority;
}

void main() {
	vector<int> nums(3);
	//for (int i = 0; i < nums.size(); i++) {z
	//	nums[i] = 1;
	//}
	nums[0] = 3;
	nums[1] = 2;
	nums[2] = 3;
	std::cout << majorityElement(nums) << std::endl;
}
#endif // DEBUG

#if 0
// 判断循环，使用快慢指针。
int bitSquareSum(int n) {
	int sum = 0;
	while (n > 0)
	{
		int bit = n % 10;
		sum += bit * bit;
		n = n / 10;
	}
	return sum;
}

bool isHappy(int n) {
	int slow = n, fast = n;//19
	do {
		slow = bitSquareSum(slow);
		fast = bitSquareSum(fast);
		fast = bitSquareSum(fast);
	} while (slow != fast);

	return slow == 1;
}

void main() {
	int num = 19;
	if (isHappy(num)) {
		std::cout << "true" << std::endl;
	}
	else {
		std::cout << "false" << std::endl;
	}
	std::cout << 1 % 10 << std::endl;
}
#endif // DEBUG

#if 0
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* removeElements(ListNode* head, int val) {
	if (head == nullptr) {
		return head;
	}
	head->next = removeElements(head->next, val);
	return head->val == val ? head->next : head;
}

void main() {
	ListNode* tmp = new ListNode(0);
	tmp->val = 1;
	std::cout << removeElements(tmp, 1);
}
#endif

#if 0
bool isIsomorphic(string s, string t) {
	unordered_map<char, char> s2t;
	unordered_map<char, char> t2s;
	int len = s.length();
	for (int i = 0; i < len; ++i) {
		char x = s[i], y = t[i];
		if ((s2t.count(x) && s2t[x] != y) || (t2s.count(y) && t2s[y] != x)) {
			return false;
		}
		s2t[x] = y;
		t2s[y] = x;
	}
	return true;
}

void main() {
	std::cout << isIsomorphic("add", "egg") << std::endl;
}
#endif // 1

#if 0
//反转链表：通过栈的先进后出
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* head) {
	if (head == nullptr) {
		return head;
	}
	stack<ListNode*> sk;
	ListNode* cur = head;
	// cur = cur->next;
	while (cur != nullptr) {
		sk.push(cur);
		cur = cur->next;
	}
	if (sk.empty()) {
		return nullptr;
	}

	ListNode* cur_ = sk.top();
	head = cur_;
	sk.pop();
	while (!sk.empty()) {
		ListNode* tmp = sk.top();
		cur_->next = tmp;
		cur_ = cur_->next;
		sk.pop();
	}
	cur_->next = nullptr;
	return head;
}
#endif

#if 0
bool containsDuplicate_0(vector<int>& nums) {
	set<int> st;
	for (int num : nums) {
		st.insert(num);
	}
	if (st.size() != nums.size()) {
		return true;
	}
	return false;

}

bool containsDuplicate_1(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	int nums_length = nums.size();
	for (int i = 0; i < nums_length - 1; ++i) {
		if (nums[i] == nums[i + 1]) {
			return true;
		}
	}
	return false;
}

bool containsDuplicate_2(vector<int>& nums) {
	unordered_set<int> nums_set;
	for (int x : nums) {
		if (nums_set.find(x) != nums_set.end()) {
			return true;
		}
		nums_set.insert(x);
	}
	return false;
}

bool containsNearbyDuplicate(vector<int>& nums, int k) {
	unordered_map<int, int> nums_map;
	int nums_length = nums.size();
	for (int i = 0; i < nums_length; ++i) {
		int num = nums[i];
		if (nums_map.count(num) && i - nums_map[num] <= k) {
			return true;
		}
		nums_map[num] = i;
	}
	return false;
}

void main() {
	vector<int> nums{ 1,2,3,1, 2, 3 };
	int k = 2;
	/*std::cout << containsDuplicate_0(nums) << std::endl;
	std::cout << containsDuplicate_1(nums) << std::endl;
	std::cout << containsDuplicate_2(nums) << std::endl;*/
	std::cout << containsNearbyDuplicate(nums,k) << std::endl;
}
#endif

#if 0
class MyStack_0 {
public:
	queue <int> queue1;
	queue <int> queue2;

	MyStack_0(){};

	void push(int x) {
		queue2.push(x);
		while (!queue1.empty()) {
			queue1.push(queue1.front());
			queue1.pop();
		}
		swap(queue1, queue2);
	}

	int pop() {
		int tmp = queue1.front();
		queue1.pop();
		return tmp;
	}

	int top() {
		int tmp = queue1.front();
		return tmp;
	}

	bool empty() {
		return queue1.empty();
	}
};

void main() {
	MyStack_0* obj = new MyStack_0();
	obj->push(1);
	int param_2 = obj->top();
	std::cout << param_2 << std::endl;
	//obj->pop();
	//int param_3 = obj->top();
	//std::cout << param_3 << std::endl;
	//bool param_4 = obj->empty();
}
#endif

#if 0
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0),left(nullptr),right(nullptr) {}
	TreeNode(int x) : val(x),left(nullptr),right(nullptr){}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(nullptr),right(nullptr){}
};
TreeNode* invertTree(TreeNode* root) {
	if (root == nullptr) {
		return nullptr;
	}

	TreeNode* left = invertTree(root->left);
	TreeNode* right = invertTree(root->right);
	root->left = right;
	root->right = left;
	return root;
}

void main() {
	TreeNode root = (4,2,7,1,3,6,9 );
	std::cout << invertTree(&root)->val << std::endl;
}
#endif

#if 0
class Solution {
public:
	bool wordPattern_0(string pattern, string str) {
		unordered_map<string, char> str2ch;
		unordered_map<char, string> ch2str;
		int str_len = str.length();
		int i = 0;
		for (auto ch : pattern) {
			if (i >= str_len) {
				return false;
			}
			int j = i;
			while (j < str_len && str[j] != ' ') j++;
			const string& tmp = str.substr(i, j - i);
			if (str2ch.count(tmp) && str2ch[tmp] != ch) {
				return false;
			}
			if (ch2str.count(ch) && ch2str[ch] != tmp) {
				return false;
			}
			str2ch[tmp] = ch;
			ch2str[ch] = tmp;
			i = j + 1;
		}
		return i >= str_len;
	}

	bool wordPattern_1(string pattern, string s) {
		vector<string> str;
		// 直接截取字符串的函数
		stringstream iss(s);
		std::cout << "iss: "<<iss.str() << std::endl;
		string word;
		// 把字符串放入
		while (iss >> word) {
			std::cout << word << std::endl;
			str.push_back(word);
		}
		// 判断是不是满射
		if (str.size() != pattern.size()) {
			return false;
		}
		// 判断是不是单射
		unordered_map<char, string> pw;
		// 判断是不是映射
		unordered_map<string, char> wp;
		for (int i = 0; i < pattern.size(); i++) {
			auto a = pattern[i];
			auto b = str[i];
			// 如果存在该字母对应的字符串不一致，则返回false
			if (pw.count(a) && pw[a] != b) {
				return false;
			}
			// 存入哈希表
			pw[a] = b;
			// 如果存在该字符串对应的单词有多个（不一致），返回false
			if (wp.count(b) && wp[b] != a) {
				return false;
			}
			// 存入哈希表
			wp[b] = a;
		}
		return true;
	}
};

void main() {
	std::string pattern = "abba";
	std::string s = "dog cat cat dog";
	Solution* obj = new Solution();
	std::cout << obj->wordPattern_0(pattern, s) << std::endl;
	std::cout << obj->wordPattern_1(pattern, s) << std::endl;
}

#endif

#if 0
class NumArray {
public:
	vector<int> sums;

	NumArray(vector<int>& nums) {
		int n = nums.size();
		sums.resize(n + 1);
		for (int i = 0; i < n; i++) {
			sums[i + 1] = sums[i] + nums[i];
		}
	}

	int sumRange(int left, int right) {
		return sums[right + 1] - sums[left];
	}
};
#endif

#if 0
// LCCUP'22 1. 气温变化趋势

//力扣城计划在两地设立「力扣嘉年华」的分会场，气象小组正在分析两地区的气温变化趋势，对于第 i ~ (i+1) 天的气温变化趋势，将根据以下规则判断：
//
//若第 i+1 天的气温 高于 第 i 天，为 上升 趋势
//若第 i+1 天的气温 等于 第 i 天，为 平稳 趋势
//若第 i+1 天的气温 低于 第 i 天，为 下降 趋势
//已知 temperatureA[i] 和 temperatureB[i] 分别表示第 i 天两地区的气温。
//组委会希望找到一段天数尽可能多，且两地气温变化趋势相同的时间举办嘉年华活动。请分析并返回两地气温变化趋势相同的最大连续天数。
//
//即最大的 n，使得第 i~i+n 天之间，两地气温变化趋势相同

// 示例1：
// 输入：
//temperatureA = [21, 18, 18, 18, 31]
//temperatureB = [34, 32, 16, 16, 17]
//
//输出：2
//
//解释：如下表所示， 第 2～4 天两地气温变化趋势相同，且持续时间最长，因此返回 4 - 2 = 2

class Solution_lccup22_1 {
public:
	int temperatureTrend_0(vector<int>& temperatureA, vector<int>& temperatureB) {
		int tempA_size = temperatureA.size();
		int tempB_size = temperatureB.size();
		int tempA_tread_size = tempA_size - 1;
		int tempB_tread_size = tempB_size - 1;

		// 0:平稳
		// 1:上升
		// -1:下降
		vector<int> tempA_tread (tempA_tread_size, 0 );
		vector<int> tempB_tread ( tempB_tread_size, 0 );

		for (int i = 0; i < tempA_tread_size; ++i) {
			if (temperatureA[i] > temperatureA[i + 1]) {
				tempA_tread[i] = -1;
				continue;
			}
			else if (temperatureA[i] < temperatureA[i + 1]) {
				tempA_tread[i] = 1;
				continue;
			}
			else if (temperatureA[i] == temperatureA[i + 1]) {
				tempA_tread[i] = 0;
				continue;
			}
		}

		for (int i = 0; i < tempB_tread_size; ++i) {
			if (temperatureB[i] > temperatureB[i + 1]) {
				tempB_tread[i] = -1;
				continue;
			}
			else if (temperatureB[i] < temperatureB[i + 1]) {
				tempB_tread[i] = 1;
				continue;
			}
			else if (temperatureB[i] == temperatureB[i + 1]) {
				tempB_tread[i] = 0;
				continue;
			}
		}

		int ans = 0;
		int max_ans = 0;

		for (int i = 0; i < tempA_tread.size(); ++i) {
			if (tempA_tread[i] == tempB_tread[i]) {
				ans+=1;
			}
			else {
				ans = 0;
			}
			max_ans = max(ans, max_ans);
		}
		return max_ans;
	}

	int temperatureTrend_1(vector<int>& a, vector<int>& b) {
		int n = a.size();
		int cur = 0, ans = 0;
		for (int i = 1; i < n; i++) {
			int ta = (a[i] > a[i - 1]) - (a[i] < a[i - 1]);
			int tb = (b[i] > b[i - 1]) - (b[i] < b[i - 1]);
			if (ta != tb) cur = 0;
			else cur++;
			ans = max(ans, cur);
		}
		return ans;
	}


};

void main() {
	vector<int> temperatureA = { 21, 18, 18 ,18, 31};
	vector<int> temperatureB = { 34, 32, 16, 16, 17};
	Solution_lccup22_1* lccup22_1 = new Solution_lccup22_1();
	std::cout << lccup22_1->temperatureTrend_0(temperatureA, temperatureB) << std::endl;
	std::cout << lccup22_1->temperatureTrend_1(temperatureA, temperatureB) << std::endl;

}
#endif

#if 0
//LCCUP'22 2. 交通枢纽

//为了缓解「力扣嘉年华」期间的人流压力，组委会在活动期间开设了一些交通专线。path[i] = [a, b] 表示有一条从地点 a通往地点 b 的 单向 交通专线。
//若存在一个地点，满足以下要求，我们则称之为 交通枢纽：
//
//所有地点（除自身外）均有一条 单向 专线 直接 通往该地点；
//该地点不存在任何 通往其他地点 的单向专线。
//请返回交通专线的 交通枢纽。若不存在，则返回 - 1。
//
//注意：
//
//对于任意一个地点，至少被一条专线连通。
//示例 1：
//
//输入：path = [[0, 1], [0, 3], [1, 3], [2, 0], [2, 3]]
//
//输出：3
//
//解释：如下图所示：
//地点 0, 1, 2 各有一条通往地点 3 的交通专线，
//且地点 3 不存在任何通往其他地点的交通专线。
class Solution_lccup22_2 {
public:
	int transportationHub(vector<vector<int>>& path) {
		int n = path.size();
		vector <int> qwq;
		vector <int> a(1001, 0), b(1001, 0);
		for (int i = 0; i < n; i++) {
			int u = path[i][0];
			int v = path[i][1];
			a[v]++, b[u] ++;
			qwq.push_back(u);
			qwq.push_back(v);
		}
		sort(qwq.begin(), qwq.end());
		int nd = unique(qwq.begin(), qwq.end()) - qwq.begin();
		for (int i = 0; i < nd; i++)
			if (a[i] == nd - 1 && b[i] == 0)
				return i;
		return -1;

	}
	
};

void main() {
	vector<vector<int>> path = { {0,1},{0,3},{1,3},{2,0},{2,3} };
	Solution_lccup22_2* sol_lccip22_2 = new Solution_lccup22_2();
	std::cout << sol_lccip22_2->transportationHub(path)<<std::endl;

}
#endif

#if 1
class LeetBook_Array_String {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		set<int> row, col;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (matrix[i][j] == 0) {
					row.insert(i);
					col.insert(j);
				}
			}
		}

		for (auto it : col) {
			for (int i = 0; i < matrix.size(); i++) {
				matrix[i][it] = 0;
			}
		}

		for (auto it : row) {
			for (int j = 0; j < matrix[0].size(); j++) {
				matrix[it][j] = 0;
			}
		}

		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				cout << matrix[i][j] << " ";
				if (j == matrix[0].size() - 1) {
					cout << endl;
				}
			}
		}
	}

	vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
		int row = mat.size();
		int col = mat[0].size();
		vector<int> res;

		for (int i = 0, idx = 0; i < row + col - 1; i++) {
			// 偶数对角线，从下往上遍历
			if (i % 2 == 0) {
				for (int x = min(i, row - 1); x >= max(0, i - col + 1); x--) {
					//res[idx++] = mat[x][i - x];
					res.push_back(mat[x][i - x]);
				}
			}
			// 奇数对角线，从上往下遍历
			else {
				for (int x = max(0, i - col + 1); x <= min(i, row - 1); x++) {
					//res[idx++] = mat[x][i - x];
					res.push_back(mat[x][i - x]);
				}
			}
		}
		return res;
	}
};

void main() {
	vector<vector<int>> matrix = { {1,1,1},{1,0,1},{1,1,1} };
	vector<vector<int>> matrix1 = { {0,1,2,0} ,{3,4,5,2},{1,3,1,5} };
	LeetBook_Array_String* sol = new LeetBook_Array_String;
	/*
	sol->setZeroes(matrix);
	sol->setZeroes(matrix1);
	*/
	for (auto it : sol->findDiagonalOrder(matrix)) {
		cout << it << " ";
	}
	





}
#endif