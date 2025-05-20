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
	int rangeSumBST(TreeNode *root, int low, int high) {
		auto dfs = [&](this auto &&dfs, TreeNode *node) -> int {
			if (!node) {
				return 0;
			}
			int res = (node->val >= low && node->val <= high ? node->val : 0);
			if (high > node->val) {
				res += dfs(node->right);
			}
			if (low < node->val) {
				res += dfs(node->left);
			}
			return res;
		};
		return dfs(root);
	}
};
