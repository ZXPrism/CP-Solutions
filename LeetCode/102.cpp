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
	vector<vector<int>> levelOrder(TreeNode *root) {
		std::vector<std::vector<int>> ans;
		if (!root) {
			return ans;
		}
		std::queue<TreeNode *> q;
		q.push(root);
		while (!q.empty()) {
			ans.emplace_back();
			auto &layer = ans.back();

			int cnt = q.size();
			for (int i = 0; i < cnt; i++) {
				TreeNode *front = q.front();
				q.pop();
				layer.push_back(front->val);
				if (front->left) {
					q.push(front->left);
				}
				if (front->right) {
					q.push(front->right);
				}
			}
		}
		return ans;
	}
};
