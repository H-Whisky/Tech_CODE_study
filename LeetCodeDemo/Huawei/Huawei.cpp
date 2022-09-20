// Huawei.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr){}
	ListNode(int x) : val(x), next(nullptr){}
	ListNode(int x, ListNode *next) : val(x), next(next){}
};

// 一、递归问题
#if 0
class Solution_70 {
public:
	int climbStairs_0(int n) {
		if (n == 1) {
			return 1;
		}
		else if (n == 2) {
			return 2;
		}
		else {
			return climbStairs_0(n - 1) + climbStairs_0(n - 2);
		}
	}

	int climbStairs_1(int n) {
		vector<int> f(n + 2);
		f[1] = 1, f[2] = 2;
		for (int i = 3; i <= n; ++i) {
			f[i] = f[i - 1] + f[i - 2];
		}
		return f[n];
	}
};

void main() {
	Solution_70* s_70 = new Solution_70();
	std::cout << s_70->climbStairs_0(5) << std::endl;
	std::cout << s_70->climbStairs_1(5) << std::endl;
}

#endif

#if 0
class Solution_112 {
public:
	//struct TreeNode {
	//	int val;
	//	TreeNode* left;
	//	TreeNode* right;
	//	TreeNode() : val(0), left(nullptr), right(nullptr){}
	//	TreeNode(int x) : val(x),left(nullptr), right(nullptr){}
	//	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right){}
	//};
	
	//深度优先遍历
	bool hasPathSum_0(TreeNode* root, int targetSum) {
		if (root == nullptr) {
			return false;
		}
		if (root->left == nullptr && root->right == nullptr) {
			return targetSum == root->val;
		}
		return hasPathSum_0(root->left, targetSum - root->val) || 
			hasPathSum_0(root->right, targetSum - root->val);
	}

	//广度优先遍历
	bool hasPathSum_1(TreeNode* root, int targetSum) {
		if (root == nullptr) {
			return false;
		}
		queue<TreeNode*> que_node;
		queue<int> que_val;
		que_node.push(root);
		que_val.push(root->val);
		while (!que_node.empty()) {
			TreeNode* now = que_node.front();
			int temp = que_val.front();
			que_node.pop();
			que_val.pop();
			if (now->left == nullptr && now->right == nullptr) {
				if (temp == targetSum) {
					return true;
				}
				continue;
			}
			if (now->left != nullptr) {
				que_node.push(now->left);
				que_val.push(now->left->val + temp);
			}
			if (now->right != nullptr) {
				que_node.push(now->right);
				que_val.push(now->right->val + temp);
			}
		}

	}
};

int main() {
	TreeNode* node0 = nullptr;
	node0->val = 1;
	TreeNode* node1 = nullptr;
	node1->val = 2;
	node0->left = node1;
	TreeNode* node2 = nullptr;
	node2->val = 3;
	node0->right = node2;

	Solution_112* s_112 = new Solution_112();
	std::cout << s_112->hasPathSum_0(node0, 2)<<std::endl;
}

#endif // 1

#if 0
class Solution_509 {
public:
	int fib(int n) {
		if (n == 0) {
			return 0;
		}

		if (n == 1) {
			return 1;
		}

		return (fib(n - 1) + fib(n - 2));
	}
};

void main() {
	Solution_509* sol_509 = new Solution_509();
	int n;
	std::cin >> n;
	std::cout << sol_509->fib(n) << std::endl;
}

#endif

// 二、分治问题
#if 0
class Solution_23 {
public:
	// 暴力解法
	ListNode* mergeKLists_0(vector<ListNode*>& lists) {
		vector<int> num;

		// 取出所有的节点的值
		for (auto a : lists) {
			while (a != NULL) {
				num.push_back(a->val);
				a = a->next;
			}
		}

		// 排序
		sort(num.begin(), num.end());

		// 如果为空直接返回
		if (num.size() == 0) {
			return NULL;
		}

		ListNode* res = new ListNode(0);
		ListNode* p = res;

		//创建新链表
		for (auto a : num) {
			p->next = new ListNode(a);
			p = p->next;
		}
		return res->next;
	}

	ListNode* mergeTwoLists(ListNode* a, ListNode* b) {
		if ((!a) || (!b)) {
			return a ? a : b;
		}
		ListNode head, *tail = &head, *aPtr = a, *bPtr = b;
		while (aPtr && bPtr) {
			if (aPtr->val < bPtr->val){
				tail->next = aPtr;
				aPtr = aPtr->next;
			}
			else {
				tail->next = bPtr;
				bPtr = bPtr->next;
			}
			tail = tail->next;
		}
		tail->next = (aPtr ? aPtr : bPtr);
		return head.next;
	}

	// 顺序合并 不理解
	ListNode* mergeKlists_1(vector<ListNode*>& lists) {
		ListNode* ans = nullptr;
		for (size_t i = 0; i < lists.size(); ++i) {
			ans = mergeTwoLists(ans, lists[i]);
		}
		return ans;
	}	

	// 分治合并
	ListNode* merge(vector <ListNode*>& lists, int l, int r) {
		if (l == r) {
			return lists[1];
		}

		if (l > r) {
			return nullptr;
		}
		int mid = (l + r) >> 1;
		return mergeTwoLists(merge(lists, l, mid), merge(lists, mid + 1, r));
	}

	ListNode* mergeKLists_2(vector<ListNode*>& lists) {
		return merge(lists, 0, lists.size() - 1);
	}

	void main() {

	}
};
#endif

#if 0
class Solution_169 {
public:
	// 排序法
	int majorityElement_0(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		return nums[nums.size() / 2];
	}

	// 摩尔投票法
	int majorityElement_1(vector<int>& nums) {
		if (nums.size() == 0) {
			return 0;
		}
		int targetNum = nums[0];
		int cnt = 0;

		for (auto n : nums) {

			if (targetNum == n) {
				cnt += 1;
			}
			else {
				cnt -= 1;
			}
			std::cout << "n = " << n << std::endl;
			std::cout << "targetNum = " << targetNum << std::endl;
			std::cout << "cnt = " << cnt << std::endl;
			std::cout  << std::endl;
			if (cnt == -1) {
				targetNum = n;
				cnt = 0;
			}
		}
		return targetNum;
	}

	// 分治法
	int count_in_range(vector<int>& nums, int target, int lo, int hi) {
		int count = 0;
		for (int i = lo; i <= hi; ++i) {
			if (nums[i] == target) {
				++count;
			}
		}
		return count;
	}

	int majority_element_rec(vector<int>& nums, int lo, int hi) {
		if (lo == hi) {
			return nums[lo];
		}
		int mid = (lo + hi) / 2;
		int left_majority = majority_element_rec(nums, lo, mid);
		int right_majority = majority_element_rec(nums, mid + 1, hi);
		if (count_in_range(nums, left_majority, lo, hi) > (hi - lo + 1)/2) {
			return left_majority;
		}		
		if (count_in_range(nums, right_majority, lo, hi) > (hi - lo + 1)/2) {
			return right_majority;
		}
		return -1;

	}

	int majorityElement_2(vector<int>& nums) {
		return majority_element_rec(nums, 0, nums.size() - 1);
	}

};

void main() {
	Solution_169* sol_169 = new Solution_169();
	vector<int> nums = { 1,3,1,2 };
	//std::cout << sol_169->majorityElement_0(nums) << std::endl;
	//std::cout << sol_169->majorityElement_1(nums) << std::endl;
	std::cout << sol_169->majorityElement_2(nums) << std::endl;
}
#endif

#if 0
class Solution_240 {
public:
	// 直接遍历
	bool searchMatrix_0(vector<vector<int>>& matrix, int target) {
		for (const auto& row : matrix) {
			for (int element : row) {
				if (element == target) {
					return true;
				}
			}
		}
		return false;
	}

	// 分治
	bool searchMatrix_1(vector<vector<int>>& matrix, int target) {
		int matrix_row_len = matrix.size();
		std::cout << "matrix row length: " << matrix_row_len << std::endl;
		int matrix_column_len = matrix[0].size();
		std::cout << "matrix column length: " << matrix_column_len << std::endl;
		if (matrix_row_len == 0) {
			return false;
		}
		if (matrix_column_len == 0) {
			return false;
		}
		int row = matrix_row_len - 1;
		int column = 0;
		while (row >= 0 && column < matrix_column_len) {
			if (matrix[row][column] == target) {
				return true;
			}
			else if (matrix[row][column] < target) {
				column += 1;
			}
			else {
				row -= 1;
			}
		}
		return false;
	}
};

void main() {
	vector<vector<int>> matrix = { {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30} };
	Solution_240* sol_240 = new Solution_240();
	std::cout << sol_240->searchMatrix_0(matrix, 5) << std::endl;
	std::cout << sol_240->searchMatrix_1(matrix, 5) << std::endl;
}
#endif

// 三、单调栈
#if 1
class Solution_84 {
public:
	// 暴力枚举【宽度】
	int largestRectangleArea_0(vector<int>& heights) {
		int n = heights.size();
		int ans = 0;
		// 枚举左边界
		for (int left = 0; left < n; ++left) {
			int minHeight = INT_MAX;
			//  枚举右边界
			for (int right = left; right < n; ++right) {
				// 确定高度
				minHeight = min(minHeight, heights[right]);
				// 计算面积
				ans = max(ans, (right - left + 1) * minHeight);
			}
		}
		return ans;
	}

	// 暴力枚举【高度】
	int largestRectangleArea_1(vector<int>& heights) {
		int n = heights.size();
		int ans = 0;
		for (int mid = 0; mid < n; ++mid) {
			// 枚举高
			int height = heights[mid];
			int left = mid, right = mid;
			// 确定左右边界
			while (left - 1 >= 0 && heights[left - 1] >= height) {
				--left;
			}
			while (right + 1 < n && heights[right + 1] >= height) {
				++right;
			}
			// 计算面积
			ans = max(ans, (right - left + 1) * height);
		}
		return ans;
	}

	// 单调栈
	int largestRectangleArea_2(vector<int>& heights) {
		int n = heights.size();
		//std::cout << "n: " << n << std::endl;
		vector<int> left(n), right(n);

		stack<int> mono_stack;
		for (int i = 0; i < n; ++i) {
			while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
				mono_stack.pop();
			}
			left[i] = (mono_stack.empty() ? -1 : mono_stack.top());
			mono_stack.push(i);
		}

		mono_stack = stack<int>();
		for (int i = n - 1; i >= 0; --i) {
			while (!mono_stack.empty() && heights[mono_stack.top()] >= heights[i]) {
				mono_stack.pop();
			}
			right[i] = (mono_stack.empty() ? n : mono_stack.top());
			mono_stack.push(i);
		}

		int ans = 0;
		for (int i = 0; i < n; ++i) {
			ans = max(ans, (right[i] - left[i] - 1) * heights[i]);
		}
		return ans;
	}
};
#if 0
void main() {
	vector<int> heights = { 2,1,5,6,2,3 };
	Solution_84* sol_84 = new Solution_84();
	std::cout << sol_84->largestRectangleArea_0(heights) << std::endl;
	std::cout << sol_84->largestRectangleArea_1(heights) << std::endl;
	std::cout << sol_84->largestRectangleArea_2(heights) << std::endl;
}
#endif
#endif

#if 1
class Solution_85 {
public:
	// No.84题求解柱状图的最大面积，此题矩形可拆解为多个柱状图
	int maximalRectangle_0(vector<vector<char>>& matrix) {
		Solution_84* sol_84 = new Solution_84;
		std::cout << matrix.size() << std::endl;
		std::cout << matrix[0].size() << std::endl;
		if (matrix.size() == 0 || matrix[0].size() == 0) {
			return 0;
		}
		int col = matrix.size();
		int row = matrix[0].size();
		vector<int> heights(row);
		int ans = 0;
		for (int i = 0; i < col; ++i) {
			for (int j = 0; j < row; ++j) {
				if (matrix[i][j] == '1') {
					heights[j] += 1;
				}
				else {
					heights[j] = 0;
				}
			}
			ans = max(ans, sol_84->largestRectangleArea_2(heights));
		}
		return ans;
	}

	// 优化No.84暴力算法
	int maximalRectangle_1(vector<vector<char>>& matrix) {
		int matrix_row = matrix.size();
		if (matrix_row == 0) {
			return 0;
		}
		int matrix_col = matrix[0].size();
		vector<vector<int>> left(matrix_row, vector<int>(matrix_row, 0));

		for (int i = 0; i < matrix_row; i++) {
			for (int j = 0; j < matrix_col; j++) {
				if (matrix[i][j] == '1') {
					left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
				}
			}
		}

		int ret = 0;
		for (int i = 0; i < matrix_row; i++) {
			for (int j = 0; j < matrix_col; j++) {
				if (matrix[i][j] == '0') {
					continue;
				}
				int width = left[i][j];
				int area = width;
				for (int k = i - 1; k >= 0; k--) {
					width = min(width, left[k][j]);
					area = max(area, (i - k + 1) * width);
				}
				ret = max(ret, area);
			}
		}
		return ret;
	}
};

void main() {
	Solution_85* sol_85 = new Solution_85;
	vector<vector<char>> matrix = { {1,0,1,0,0},{1,0,1,1,1},{1,1,1,1,1},{1,0,0,1,0}};
	//std::cout << sol_85->maximalRectangle_0(matrix) << std::endl;
	std::cout << sol_85->maximalRectangle_1(matrix) << std::endl;
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
