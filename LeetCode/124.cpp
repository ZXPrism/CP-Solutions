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
	int maxPathSum(TreeNode *root) {
		int ans = -0x3f3f3f3f;
		auto dfs = [&](this auto &&dfs, TreeNode *node) -> int {
			if (!node) {
				return 0;
			}
			int lm = dfs(node->left);
			int rm = dfs(node->right);
			ans = std::max(ans, lm + rm + node->val);
			return std::max(0, std::max(lm, rm) + node->val);
		};
		dfs(root);
		return ans;
	}
};
