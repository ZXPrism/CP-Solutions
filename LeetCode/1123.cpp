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
    TreeNode *lcaDeepestLeaves(TreeNode *root) {
        auto dfs = [&](this auto &&dfs, TreeNode *node) -> std::pair<TreeNode *, int> {
            if (!node) {
                return {nullptr, 0};
            }
            auto [left, lh] = dfs(node->left);
            auto [right, rh] = dfs(node->right);
            if (lh < rh) {
                return {right, rh + 1};
            } else if (lh > rh) {
                return {left, lh + 1};
            }
            return {node, lh + 1};
        };
        return dfs(root).first;
    }
};
