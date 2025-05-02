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
	int pathSum(TreeNode *root, int targetSum) {
		int ans = 0;
		std::unordered_map<long long, int> cnt;
		++cnt[0];
		auto dfs = [&](this auto &&dfs, TreeNode *node, long long sum) -> void {
			if (!node) {
				return;
			}
			sum += node->val;
			ans += cnt[sum - targetSum];
			++cnt[sum];
			dfs(node->left, sum);
			dfs(node->right, sum);
			--cnt[sum];
		};
		dfs(root, 0);
		return ans;
	}
};
