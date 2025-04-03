class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        std::vector<std::vector<int>> ans;
        std::vector<int> curr;
        auto dfs = [&](this auto &&dfs, int p) {
            if (curr.size() == k) {
                ans.push_back(curr);
                return;
            }
            for (int i = p; i <= n; i++) {
                curr.push_back(i);
                dfs(i + 1);
                curr.pop_back();
            }
        };
        dfs(1);
        return ans;
    }
};
