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
	int maxAncestorDiff(TreeNode *root) {
		int ans = 0;
		constexpr int inf = 0x3f3f3f3f;
		auto dfs_min = [&](this auto &&dfs, TreeNode *node) -> int {
			if (!node) {
				return inf;
			}
			int min_desc = std::min(dfs(node->left), dfs(node->right));
			ans = std::max(ans, node->val - min_desc);
			return std::min(min_desc, node->val);
		};
		dfs_min(root);
		auto dfs_max = [&](this auto &&dfs, TreeNode *node) -> int {
			if (!node) {
				return -inf;
			}
			int max_desc = std::max(dfs(node->left), dfs(node->right));
			ans = std::max(ans, max_desc - node->val);
			return std::max(max_desc, node->val);
		};
		dfs_max(root);
		return ans;
	}
};
