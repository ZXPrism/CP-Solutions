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
	int longestZigZag(TreeNode *root) {
		int ans = 0;
		auto dfs = [&](this auto &&dfs, TreeNode *node, int dir) -> int {
			if (!node) {
				return -1;
			}
			int left = dfs(node->left, 0);
			int right = dfs(node->right, 1);
			ans = std::max(ans, std::max(left, right) + 1);
			if (dir == 0) {
				return right + 1;
			}
			return left + 1;
		};
		dfs(root, 0);
		dfs(root, 1);
		return ans;
	}
};
