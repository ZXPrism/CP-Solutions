/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        auto dfs = [&](this auto &&dfs, TreeNode *node, TreeNode *target,
                       std::vector<TreeNode *> &seq) -> bool {
            if (node) {
                seq.push_back(node);
                if (node == target) {
                    return true;
                }
                if (dfs(node->left, target, seq) || dfs(node->right, target, seq)) {
                    return true;
                }
                seq.pop_back();
            }
            return false;
        };
        std::vector<TreeNode *> p_seq, q_seq;
        dfs(root, p, p_seq);
        dfs(root, q, q_seq);
        TreeNode *ans = root;
        int n = std::min(p_seq.size(), q_seq.size());
        for (int i = 0; i < n; i++) {
            if (p_seq[i] == q_seq[i]) {
                ans = p_seq[i];
            }
        }
        return ans;
    }
};
