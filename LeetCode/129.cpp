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
	int sumNumbers(TreeNode *root) {
		int ans = 0;
		auto dfs = [&](this auto &&dfs, TreeNode *curr, int num) -> void {
			if (!curr) {
				return;
			}

			num = num * 10 + curr->val;
			if (!curr->left && !curr->right) {
				ans += num;
				return;
			}
			dfs(curr->left, num);
			dfs(curr->right, num);
		};
		dfs(root, 0);
		return ans;
	}
};
