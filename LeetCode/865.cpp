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
    TreeNode *subtreeWithAllDeepest(TreeNode *root) {
        auto LCA = [&](this auto &&LCA, TreeNode *node) -> std::pair<int, TreeNode *> {
            if (!node) {
                return {0, nullptr};
            }
            auto [lh, left] = LCA(node->left);
            auto [rh, right] = LCA(node->right);
            if (lh < rh) {
                return {rh + 1, right};
            } else if (lh > rh) {
                return {lh + 1, left};
            }
            return {lh + 1, node};
        };
        return LCA(root).second;
    }
};
