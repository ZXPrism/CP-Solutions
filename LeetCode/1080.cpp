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
	TreeNode *sufficientSubset(TreeNode *root, int limit) {
		struct Info {
			int _Sum;
			bool _Del;
		};
		auto dfs = [&](this auto &&dfs, TreeNode *node, int sum) -> Info {
			if (!node) {
				return { -0x3f3f3f3f, false };
			}

			int curr = sum + node->val;
			if (!node->left && !node->right) {
				return { curr, curr < limit };
			}

			auto [left_sum, left_del] = dfs(node->left, curr);
			if (left_del) {
				node->left = nullptr;
			}

			auto [right_sum, right_del] = dfs(node->right, curr);
			if (right_del) {
				node->right = nullptr;
			}

			int check = std::max(left_sum, right_sum);
			return { check, check < limit };
		};
		auto [_, del] = dfs(root, 0);
		return (del ? nullptr : root);
	}
};
