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
        int id_used = 0, timestamp = 0;
        std::unordered_map<TreeNode *, int> id;
        std::vector<int> in, out;
        auto dfs = [&](this auto &&dfs, TreeNode *node) -> void {
            if (node) {
                ++timestamp;
                in.push_back(timestamp);
                out.push_back(timestamp);
                id[node] = id_used++;
                dfs(node->left);
                dfs(node->right);
                out[id[node]] = timestamp;
            }
        };
        dfs(root);

        auto is_ancestor = [&](TreeNode *des, TreeNode *ans) -> bool {
            int des_id = id[des], ans_id = id[ans];
            return in[ans_id] <= in[des_id] && out[des_id] <= out[ans_id];
        };

        int max_depth = 0;
        TreeNode *ans = root;
        auto dfs2 = [&](this auto &&dfs, TreeNode *node, int depth) -> void {
            if (node) {
                if (is_ancestor(p, node) && is_ancestor(q, node)) {
                    if (depth > max_depth) {
                        max_depth = depth;
                        ans = node;
                    }
                }
                dfs(node->left, depth + 1);
                dfs(node->right, depth + 1);
            }
        };
        dfs2(root, 0);

        return ans;
    }
};
