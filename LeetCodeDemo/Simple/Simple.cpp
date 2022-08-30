﻿// Simple.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <stack>
#include <set>
#include <algorithm>
#include <queue>

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

#if 1
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