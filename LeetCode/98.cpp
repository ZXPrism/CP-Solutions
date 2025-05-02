/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

std::mt19937_64 engine;

auto init = []() {
	std::random_device rd;
	engine.seed(rd());
	return 114514;
}();

class Solution {
public:
	bool isValidBST(TreeNode *root) {
		using i64 = long long;
		constexpr i64 inf = std::numeric_limits<i64>::max() >> 1;

		std::uniform_int_distribution<int> dist(0, 2);
		int choice = dist(engine);

		if (choice == 0) {  // preorder
			auto dfs = [&](this auto &&dfs, TreeNode *node, i64 left,
			               i64 right) {
				if (!node) {
					return true;
				}
				if (node->val <= left || node->val >= right) {
					return false;
				}
				return dfs(node->left, left, node->val) &&
				       dfs(node->right, node->val, right);
			};
			return dfs(root, -inf, inf);
		} else if (choice == 1) {  // inorder
			i64 prev = -inf;
			auto dfs = [&](this auto &&dfs, TreeNode *node) {
				if (!node) {
					return true;
				}
				if (!dfs(node->left) || node->val <= prev) {
					return false;
				}
				prev = node->val;
				return dfs(node->right);
			};
			return dfs(root);
		} else {  // postorder
			auto dfs = [&](this auto &&dfs,
			               TreeNode *node) -> std::pair<i64, i64> {
				if (!node) {
					return { inf, -inf };
				}
				auto [l_min, l_max] = dfs(node->left);
				if (node->val <= l_max) {
					return { -inf, inf };
				}

				auto [r_min, r_max] = dfs(node->right);
				if (node->val >= r_min) {
					return { -inf, inf };
				}

				return { std::min(l_min, 1LL * node->val),
					     std::max(r_max, 1LL * node->val) };
			};
			return (dfs(root).second != inf);
		}

		return false;
	}
};
