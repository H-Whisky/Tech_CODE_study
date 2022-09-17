// Huawei.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
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

#if 1
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


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
