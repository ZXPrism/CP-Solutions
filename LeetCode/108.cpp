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
	TreeNode *sortedArrayToBST(vector<int> &nums) {
		int n = nums.size();
		auto dfs = [&](this auto &&dfs, int left, int right) -> TreeNode * {
			if (left >= right) {
				return nullptr;
			}
			int mid = (left + right) >> 1;
			return new TreeNode(nums[mid], dfs(left, mid), dfs(mid + 1, right));
		};
		return dfs(0, n);
	}
};
