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
	void flatten(TreeNode *root) {
		TreeNode *fa = nullptr;

		auto dfs = [&](this auto &&dfs, TreeNode *node) -> void {
			if (!node) {
				return;
			}

			if (fa) {
				fa->left = nullptr;
				fa->right = node;
			}
			fa = node;

			auto right = node->right;
			dfs(node->left);
			dfs(right);
		};

		dfs(root);
	}
};
