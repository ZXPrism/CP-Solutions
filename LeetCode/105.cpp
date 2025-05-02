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
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		int n = preorder.size();
		std::vector<int> val2pos_in(6001);
		for (int i = 0; i < n; i++) {
			val2pos_in[inorder[i] + 3000] = i;
		}
		auto dfs = [&](this auto &&dfs, int pre_left, int pre_right,
		               int in_left, int in_right) -> TreeNode * {
			if (pre_left >= pre_right) {
				return nullptr;
			}
			int curr = preorder[pre_left];
			int in_mid = val2pos_in[curr + 3000];
			int pre_mid = pre_left + 1 + in_mid - in_left;
			return new TreeNode(curr,
			                    dfs(pre_left + 1, pre_mid, in_left, in_mid),
			                    dfs(pre_mid, pre_right, in_mid + 1, in_right));
		};
		return dfs(0, n, 0, n);
	}
};
