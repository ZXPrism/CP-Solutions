class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> ans;
        std::vector<int> curr;
        auto dfs = [&](this auto &&dfs, int p) {
            if (k - curr.size() > n - p + 1) {
                return;
            }
            if (p == n + 1) {
                if (curr.size() == k) {
                    ans.push_back(curr);
                }
                return;
            }
            curr.push_back(p);
            dfs(p + 1);
            curr.pop_back();
            dfs(p + 1);
        };
        dfs(1);
        return ans;
    }
};
