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
	int kthSmallest(TreeNode *root, int k) {
		auto dfs = [&](this auto &&dfs, TreeNode *node) -> int {
			if (!node) {
				return -1;
			}
			int left = dfs(node->left);
			if (left != -1) {
				return left;
			}

			--k;
			if (!k) {
				return node->val;
			}

			return dfs(node->right);
		};
		return dfs(root);
	}
};
