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
	int sumNumbers(TreeNode *root, int num = 0) {
		if (!root) {
			return 0;
		}
		int new_num = num * 10 + root->val;
		if (!root->left && !root->right) {
			return new_num;
		}
		return sumNumbers(root->left, new_num) +
		       sumNumbers(root->right, new_num);
	}
};
