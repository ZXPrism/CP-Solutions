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
	bool isSymmetric(TreeNode *root) {
		auto dfs = [&](this auto &&dfs, TreeNode *left, TreeNode *right) -> bool {
			if ((left && !right) || !left && right) {
				return false;
			}
			return (!left && !right) ||
			       (left->val == right->val &&
			        dfs(left->right, right->left) &&
			        dfs(left->left, right->right));
		};
		return dfs(root->left, root->right);
	}
};
