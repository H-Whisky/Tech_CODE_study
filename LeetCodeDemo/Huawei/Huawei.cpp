// Huawei.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>
#include <stack>
#include <unordered_set>
#include <unordered_map>
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
#if 0
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

#if 0
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

#if 0
class Solution_739 {
public:
	// 暴力解法
	vector<int> dailyTemperatures_0(vector<int>& temperatures) {
		int temperatures_size = temperatures.size();
		vector<int> ans(temperatures_size, 0);
		for (int i = 0; i < temperatures_size; ++i) {
			for (int j = i + 1; j < temperatures_size; ++j) {
				if (temperatures[i] < temperatures[j]) {
					ans[i] = j - i;
					break;
				}
			}
		}
		return ans;
	}

	// 优化的暴力解法
	vector<int> dailyTemperatures_1(vector<int>& temperatures) {
		int temperatures_size = temperatures.size();
		vector<int> ans(temperatures_size), next(101, INT_MAX);
		for (int i = temperatures_size - 1; i >= 0; --i) {
			int warmerIndex = INT_MAX;
			for (int j = temperatures[i] + 1; j <= 100; ++j) {
				warmerIndex = min(warmerIndex, next[j]);
			}
			if (warmerIndex != INT_MAX) {
				ans[i] = warmerIndex - i;
			}
			next[temperatures[i]] = i;
		}
		return ans;
	}

	// 单调栈
	vector<int> dailyTemperatures_2(vector<int>& temperatures) {
		// 保存温度和天数的组合
		stack<pair<int, int>> S;
		// 初始化每个温度对应的结果
		vector<int> ans(temperatures.size(), 0);
		// 将第0个温度和天数0添加至栈
		S.push(make_pair(temperatures[0], 0));
		// 进入遍历的循环从第2个温度开始
		for (int i = 1; i < temperatures.size(); ++i) {
			// 只要栈顶的温度小于正在遍历的温度
			while (!S.empty() && S.top().first < temperatures[i]) {
				// 计算结果
				ans[S.top().second] = i - S.top().second;
				//  将栈顶弹出
				S.pop();
			}
			S.push(make_pair(temperatures[i],i));
		}
		return ans;
	}
};

void main() {
	Solution_739* sol_739 = new Solution_739;
	vector<int> temperatures = { 73,74,75,71,69,72,76,73 };
	//vector<int> ans = sol_739->dailyTemperatures_0(temperatures);
	//vector<int> ans = sol_739->dailyTemperatures_1(temperatures);
	vector<int> ans = sol_739->dailyTemperatures_2(temperatures);
	for (int i = 0; i <ans.size(); i++) {
		std::cout << ans[i] << " ";
	}
}
#endif

#if 0
class Solution_503 {
public:
	// 单调栈
	vector<int> nextGreaterElements_0(vector<int>& nums) {
		int nums_size = nums.size();
		stack<int> S;
		vector<int> ans(nums_size, -1);
		for (int i = 0; i < nums_size * 2 - 1; ++i) {
			while (!S.empty() && nums[S.top()] < nums[i % nums_size]) {
				ans[S.top()] = nums[i % nums_size];
				S.pop();
			}
			S.push(i % nums_size);
		}
		return ans;
	}

};

void main() {
	Solution_503* sol_503 = new Solution_503;
	vector<int> nums = { 1,2,3,4,3 };
	vector<int> ans = sol_503->nextGreaterElements_0(nums);
	for (int i = 0; i < ans.size(); i++) {
		std::cout << ans[i] << " ";
	}
}
#endif

// 四、并查集
#if 0
class Solution_547 {
public:
	int Find(vector<int>& parent, int index) {
		if (parent[index] != index) {
			parent[index] = Find(parent, parent[index]);
		}
		return parent[index];
	}

	void Union(vector<int>& parent, int index1, int index2) {
		parent[Find(parent, index1)] = Find(parent, index2);
	}

	// 并查集
	int findCircleNum_0(vector<vector<int>>& isConnected) {
		int cities = isConnected.size();
		vector<int> parent(cities);
		// 初始化
		for (int i = 0; i < cities; ++i) {
			parent[i] = i;
		}

		for (int i = 0; i < cities; i++) {
			for (int j = i + 1; j < cities; j++) {
				if (isConnected[i][j] == 1) {
					Union(parent, i, j);
				}
			}
		}
		int provinces = 0;
		for (int i = 0; i < cities; ++i) {
			if (parent[i] == i) {
				provinces++;
			}
		}
		return provinces;
	}
};

void main() {
	vector<vector<int>> isConnected = { {1,1,0}, {1,1,0}, {0,0,1} };
	Solution_547* sol_547 = new Solution_547;
	std::cout << sol_547->findCircleNum_0(isConnected) << std::endl;
}
#endif


#if 0
// 模板0：并查集
class UnionFind_0 {
private:
	// 节点数量 3 - 1000
	int n = 1005;
	int father[1005];

public:
	// 并查集初始化
	void init() {
		for (int i = 0; i < n; ++i) {
			father[i] = i;
		}
	}

	// 并查集寻根的过程
	int find(int u) {
		return u == father[u] ? u : father[u] = find(father[u]);
	}

	//  将v->u这条边加入并查集
	void join(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) {
			return;
		}
		father[v] = u;
	}

	//  判断u和v是否同根
	bool same(int u, int v) {
		u = find(u);
		v = find(v);
		return u == v;
	}
};

// 模板1：并查集 
class UnionFind_1 {
private:
	vector<int> parent;
	vector<int> rank;
	int count;

public:
	UnionFind_1(vector<vector<char>>& grid) {
		count = 0;
		int row = grid.size();
		int column = grid[0].size();
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				if (grid[i][j] == '1') {
					//  parent数组记录grid中每数的祖先
					parent.push_back(i * column + j);
					// 记录二维数组中“1”的个数
					++count;
				}
				else {
					parent.push_back(-1);
				}
				rank.push_back(0);
			}
		}
	}

	int find(int i) {
		if (parent[i] != i) {
			parent[i] = find(parent[i]);
		}
		return parent[i];
	}

	void unite(int x, int y) {
		int rootx = find(x);
		int rooty = find(y);
		if (rootx != rooty) {
			if (rank[rootx] < rank[rooty]) {
				swap(rootx, rooty);
			}
			parent[rooty] = rootx;
			if (rank[rootx] == rank[rooty]) {
				rank[rootx] += 1;
			}
			--count;
		}
	}

	int getCount() const {
		return count;
	}
};

class Solution_200_1 {
public:
	int numIslands_1(vector<vector<char>>& grid) {
		int row = grid.size();
		if (!row) {
			return 0;
		}
		int column = grid[0].size();

		UnionFind_1 uf_1(grid);
		int islands_num = 0;
		for (int r = 0; r < row; ++r) {
			for (int c = 0; c < column; ++c) {
				if (grid[r][c] == '1') {
					grid[r][c] = '0';
					// up
					if (r - 1 >= 0 && grid[r - 1][c] == '1') {
						uf_1.unite(r * column + c, (r - 1) * column + c);
					}		
					// down
					if (r + 1 < row && grid[r + 1][c] == '1') {
						uf_1.unite(r * column + c, (r + 1) * column + c);
					}	
					// left
					if (c - 1 >= 0 && grid[r][c - 1] == '1') {
						uf_1.unite(r * column + c, r * column + (c - 1));
					}
					// right
					if (c + 1 < column && grid[r][c + 1] == '1') {
						uf_1.unite(r * column + c, r * column + (c + 1));
					}
				}
			}
		}
		return uf_1.getCount();
	}
};

class Solution_200_2 {
public:
	// 遍历岛中二维数组，如果当前数为1，则进入感染函数并岛数+1
	int numIslands_2(vector <vector<char>>& grid) {
		int islandNum = 0;
		for (int i = 0; i < grid.size(); ++i) {
			for (int j = 0; j < grid[0].size(); ++j) {
				if (grid[i][j] == '1') {
					infect(grid, i, j);
					islandNum ++;
				}
			}
		}
		return islandNum;
	}

	// 感染函数（递归）
	void infect(vector<vector<char>>& grid, int i, int j) {
		if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] != '1') {
			return;
		}
		grid[i][j] = '2';
		infect(grid, i + 1, j);
		infect(grid, i - 1, j);
		infect(grid, i, j + 1);
		infect(grid, i, j - 1);
	}
};

void main() {
	// 法0：并查集

	// 法1：并查集
	vector<vector<char>> grid_1 = { {'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'} };
	Solution_200_1* sol_200_1 = new Solution_200_1;
	std::cout << sol_200_1->numIslands_1(grid_1) << std::endl;

	// 法2：感染函数
	vector<vector<char>> grid_2 = { {'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'} };
	Solution_200_2* sol_200_2 = new Solution_200_2;
	std::cout << sol_200_2->numIslands_2(grid_2) << std::endl;
}
#endif

#if 0
class UnionFind {
private:
	// 节点数量 3 - 1000
	int n = 1005;
	int father[1005];

public:
	// 并查集初始化
	void init() {
		for (int i = 0; i < n; ++i) {
			father[i] = i;
		}
	}

	// 并查集寻根的过程
	int find(int u) {
		return u == father[u] ? u : father[u] = find(father[u]);
	}

	//  将v->u这条边加入并查集
	void join(int u, int v) {
		u = find(u);
		v = find(v);
		if (u == v) {
			return;
		}
		father[v] = u;
	}	
	
	//  判断u和v是否同根
	bool same(int u, int v) {
		u = find(u);
		v = find(v);
		return u == v;
	}
};

class Solution_684 {
public:
	vector<int> findRedundantConnection(vector<vector<int>>& edges) {
		UnionFind* uf = new UnionFind;
		uf->init();
		for (int i = 0; i < edges.size(); ++i) {
			if (uf->same(edges[i][0], edges[i][1])) {
				return edges[i];
			}
			else {
				uf->join(edges[i][0], edges[i][1]);
			}
		}
		return {};
	}
};

void main() {
	vector<vector<int>> edges = { {1,2}, {1,3}, {2,3} };
	//vector<vector<int>> edges = { {1,2}, {2,3}, {3,4}, {1,4},{1,5} };
	int ans_size = edges[0].size();
	vector<int> ans (ans_size, 0);
	Solution_684* sol_684 = new Solution_684;
	ans = sol_684->findRedundantConnection(edges);
	for (int i = 0; i < ans_size; i++) {
		std::cout << ans[i] << std::endl;
	}
}
#endif

// 五、滑动窗口
#if 0
class Solution_209 {
public:
	// 暴力解法
	int minSubArrayLen_0(int target, vector<int>& nums) {
		int nums_size = nums.size();
		if (nums_size == 0) {
			return 0;
		}
		int ans = INT_MAX;
		for (int i = 0; i < nums_size; ++i) {
			int sum = 0;
			for (int j = i; j < nums_size; ++j) {
				sum += nums[j];
				if (sum >= target) {
					ans = min(ans, j - i + 1);
					break;
				}
			}
		}
		return ans == INT_MAX ? 0 : ans;
	}

	// 前缀和 + 二分查找
	int minSubArrayLen_1(int target, vector<int>& nums) {
		int nums_size = nums.size();
		if (nums_size == 0) {
			return 0;
		}
		int ans = INT_MAX;
		vector<int> sums(nums_size + 1, 0);

		// sums[]存储数组nums的前缀和
		for (int i = 1; i <= nums_size; ++i) {
			sums[i] = sums[i - 1] + nums[i - 1];
		}
		for (int i = 1; i <= nums_size; ++i) {
			int target_ = target + sums[i - 1];
			// lower_bond: 二分查找大于等于某个数的第一个位置
			auto bound = lower_bound(sums.begin(), sums.end(), target_);
			if (bound != sums.end()) {
				ans = min(ans, static_cast<int>((bound - sums.begin()) - (i - 1)));
			}
		}
		return ans == INT_MAX ? 0 : ans;
	}

	// 滑动窗口
	int minSubArrayLen_2(int target, vector<int>& nums) {
		int n = nums.size();
		if (n == 0) {
			return 0;
		}
		int ans = INT_MAX;
		int start = 0, end = 0;
		int sum = 0;
		while (end < n) {
			sum += nums[end];
			while (sum >= target) {
				ans = min(ans, end - start + 1);
				sum -= nums[start];
				start++;
			}
			end++;
		}
		return ans == INT_MAX ? 0 : ans;
	}
};

void main() {
	Solution_209* sol_209 = new Solution_209;
	vector<int> nums = {2,3,1,2,4,3};
	std::cout << sol_209->minSubArrayLen_0(7, nums) << std::endl;
	std::cout << sol_209->minSubArrayLen_1(7, nums) << std::endl;
	std::cout << sol_209->minSubArrayLen_2(7, nums) << std::endl;
}
#endif

#if 0
class Solution_3 {
public:
	// 滑动窗口
	int lengthOfLongestSubstring(string s) {
		// 哈希集合，记录每个字符是否出现
		unordered_set<char> occ;
		int s_size = s.size();
		// 右指针，初始值为-1，相当于我们在 字符串的左边界的左侧，还没有开始移动
		int rk = -1, ans = 0;
		// 枚举左指针的位置，初始值隐形地面表示为-1
		for (int i = 0; i < s_size; i++) {
			if (i != 0) {
				// 左指针向右移动一格，移除一个字符
				occ.erase(s[i - 1]);
			}
			while (rk + 1 < s_size && !occ.count(s[rk + 1])) {
				// 不断的移动右指针
				occ.insert(s[rk + 1]);
				++rk;
			}
			// 第i到rk个字符是一个极长的无重复字符字串
			ans = max(ans, rk - i + 1);
		}
		return ans;
	}
};

void main() {
	std::string s = { "abcabcbb" };
	Solution_3* sol_3 = new Solution_3;
	std::cout << sol_3->lengthOfLongestSubstring(s) << std::endl;

}
#endif

#if 0
class Solution_1004 {
public:
	// 滑动窗口:右边无脑滑动，左边看情况收缩
	int longestOnes_0(vector<int>& nums, int k) {
		int left = 0;
		int right = 0;
		int res = INT_MIN;
		while (right < nums.size()) {
			if (nums[right] == 0) k--;
			right++;
			// 左边界收缩
			while (k < 0) {
				if (nums[left] == 0) k++;
				left++;
			}
			res = max(res, right - left);
		}
		return res;
	}

};

void main() {
	Solution_1004* sol = new Solution_1004;
	vector<int> nums = { 1,1,1,0,0,0,1,1,1,1,0 };
	cout << sol->longestOnes_0(nums, 2) << endl;
}
#endif

#if 0
class Solution_1208 {
public:
	// 滑动窗口
	int equalSubstring(string s, string t, int maxCost) {
		int n = s.length();
		vector<int> diff(n, 0);
		for (int i = 0; i < n; ++i) {
			diff[i] = abs(s[i] - t[i]);
		}
		int maxLength = 0;
		int left = 0, right = 0;
		int sum = 0;
		while (right < n) {
			sum += diff[right];
			while (sum > maxCost) {
				sum -= diff[left];
				left++;
			}
			maxLength = max(maxLength, right - left + 1);
			right++;
		}
		return maxLength;
	}
};

void main() {
	Solution_1208* sol = new Solution_1208;
	string s = { "abcd" };
	string t = { "bcdf" };
	int maxCost = 3;
	cout << sol->equalSubstring(s, t, maxCost) << endl;
}
#endif

// 六、前缀和
#if 0
class Solution_724 {
public:
	// 暴力枚举
	int pivotIndex_0(vector<int>& nums) {
		int nums_size = nums.size();
		for (int i = 0; i < nums_size; i++) {
			int sum_before= 0;
			int sum_after= 0;
			for (int j = 0; j < i; j++) {
				sum_before += nums[j];
			}
			for (int j = i + 1; j < nums_size; j++) {
				sum_after += nums[j];
			}
			if (sum_before == sum_after) {
				return i;
			}
		}
		return -1;
	}

	// 前缀和
	int pivotIndex_1(vector<int>& nums) {
		int total = 0;
		for (int i = 0; i < nums.size(); ++i) {
			total += nums[i];
		}
		int sum = 0;
		for (int i = 0; i < nums.size(); ++i) {
			// 算法
			if (2 * sum + nums[i] == total) {
				return i;
			}
			sum += nums[i];
		}
		return -1;
	}
};

void main() {
	vector<int> nums_0 = { 1,7,3,6,5,6 };
	vector<int> nums_1 = { 1};
	Solution_724* sol = new Solution_724;
	cout << sol->pivotIndex_0(nums_0) << endl;
	cout << sol->pivotIndex_0(nums_1) << endl;
	cout << sol->pivotIndex_1(nums_1) << endl;
}
#endif

#if 0
class Solution_560 {
public:
	// 暴力枚举
	int subarraySum_0(vector<int>& nums, int k) {
		int ans = 0;
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == k) {
				ans += 1;
			}
			int temp = nums[i];
			for (int j = i + 1; j < nums.size(); ++j) {
				temp += nums[j];
				if (temp == k) {
					ans += 1;
				}
			}
		}
		return ans;
	}

	//前缀和 + 哈希表
	int subarraySum_1(vector<int>& nums, int k) {
		unordered_map<int, int> mp;
		mp[0] = 1;
		int count = 0, pre = 0;
		for (auto& x : nums) {
			pre += x;
			if (mp.find(pre - k) != mp.end()) {
				count += mp[pre - k];
			}
			mp[pre]++;
		}
		return count;
	 }
};

void main() {
	Solution_560* sol = new Solution_560;
	vector<int> nums = { 1,2,3 };
	cout << sol->subarraySum_0(nums, 3) << endl;
}
#endif

#if 1
class Solution_437 {
public:
	// 深度优先搜索
	int pathSum_0(TreeNode* root, int targetSum) {
		if (!root) {
			return 0;
		}

		int ret = rootSum(root, targetSum);
		ret += pathSum_0(root->left, targetSum);
		ret += pathSum_0(root->right, targetSum);
		return ret;
	}

	int rootSum(TreeNode* root, int targetSum) {
		if (!root) {
			return 0;
		}

		int ret = 0;
		if (root->val == targetSum) {
			ret++;
		}
		ret += rootSum(root->left, targetSum - root->val);
		ret += rootSum(root->right, targetSum - root->val);
		return ret;
	}
};

void main() {
	
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
