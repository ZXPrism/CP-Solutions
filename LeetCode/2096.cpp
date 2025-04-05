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
    string getDirections(TreeNode *root, int startValue, int destValue) {
        auto lca = [&](this auto &&lca, TreeNode *node) -> TreeNode * {
            if (!node || node->val == startValue || node->val == destValue) {
                return node;
            }
            auto left = lca(node->left);
            auto right = lca(node->right);
            if (left && right) {
                return node;
            }
            if (left) {
                return left;
            }
            return right;
        };
        auto mid = lca(root);
        std::string ans;
        auto dfs = [&](this auto &&dfs, TreeNode *node, int target) -> bool {
            if (node) {
                if (node->val == target) {
                    return true;
                }
                ans.push_back('L');
                if (dfs(node->left, target)) {
                    return true;
                }
                ans.pop_back();
                ans.push_back('R');
                if (dfs(node->right, target)) {
                    return true;
                }
                ans.pop_back();
            }

            return false;
        };
        dfs(mid, startValue);
        int n = ans.size();
        ans = std::string(n, 'U');
        dfs(mid, destValue);
        return ans;
    }
};
