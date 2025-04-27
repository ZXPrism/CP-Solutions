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
	int goodNodes(TreeNode *root, int curr_max = -0x3f3f3f3f) {
		if (!root) {
			return 0;
		}
		int new_max = std::max(curr_max, root->val);
		return goodNodes(root->left, new_max) +
		       goodNodes(root->right, new_max) + (root->val >= curr_max);
	}
};
