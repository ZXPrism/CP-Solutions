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
	vector<int> findFrequentTreeSum(TreeNode *root) {
		std::vector<int> ans;
		std::unordered_map<int, int> cnt;
		auto dfs = [&](this auto &&dfs, TreeNode *node) -> int {
			if (!node) {
				return 0;
			}
			int res = dfs(node->left) + dfs(node->right) + node->val;
			++cnt[res];
			return res;
		};
		dfs(root);
		int max_cnt = 0;
		for (auto &[_, c] : cnt) {
			if (c > max_cnt) {
				max_cnt = c;
			}
		}
		for (auto &[x, c] : cnt) {
			if (c == max_cnt) {
				ans.push_back(x);
			}
		}
		return ans;
	}
};
