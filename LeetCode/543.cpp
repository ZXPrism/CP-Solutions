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
	int diameterOfBinaryTree(TreeNode *root) {
		int ans = 0;

		auto dfs = [&](this auto &&dfs, TreeNode *node) -> int {
			if (!node) {
				return -1;
			}
			int lm = dfs(node->left);
			int rm = dfs(node->right);
			ans = std::max(ans, lm + rm + 2);
			return std::max(lm, rm) + 1;
		};
		dfs(root);

		return ans;
	}
};
