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
class Solution {
public:
	bool isBalanced(TreeNode *root) {
		auto dfs = [&](this auto &&dfs, TreeNode *node) -> int {
			if (!node) {
				return 0;
			}
			int left = dfs(node->left);
			if (left == -1) {
				return -1;
			}
			int right = dfs(node->right);
			if (right == -1 || std::abs(left - right) > 1) {
				return -1;
			}
			return std::max(left, right) + 1;
		};
		return dfs(root) != -1;
	}
};
