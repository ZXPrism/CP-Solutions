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
	int longestUnivaluePath(TreeNode *root) {
		int ans = 0;

		auto dfs = [&](this auto &&dfs, TreeNode *node) -> int {
			if (!node) {
				return -1;
			}
			int left = dfs(node->left);
			int right = dfs(node->right);
			int curr = 0, max_len = -1;
			if (node->left && node->val == node->left->val) {
				curr += left + 1;
				max_len = std::max(max_len, left);
			}
			if (node->right && node->val == node->right->val) {
				curr += right + 1;
				max_len = std::max(max_len, right);
			}
			ans = std::max(ans, curr);
			return max_len + 1;
		};

		dfs(root);

		return ans;
	}
};
