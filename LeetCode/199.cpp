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
	vector<int> rightSideView(TreeNode *root) {
		std::vector<int> ans;
		auto dfs = [&](this auto &&dfs, TreeNode *node, int depth) -> void {
			if (!node) {
				return;
			}
			if (ans.size() == depth) {
				ans.push_back(node->val);
			}
			dfs(node->right, depth + 1);
			dfs(node->left, depth + 1);
		};
		dfs(root, 0);
		return ans;
	}
};
