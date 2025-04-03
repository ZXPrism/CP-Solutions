class Solution {
public:
    vector<vector<int>> permute(vector<int> &nums) {
        int n = nums.size();
        std::vector<std::vector<int>> ans;
        std::vector<int> curr(n);
        std::vector<int> vis(n);
        auto dfs = [&](this auto &&dfs, int k) {
            if (k == n) {
                ans.push_back(curr);
                return;
            }
            for (int i = 0; i < n; i++) {
                if (!vis[i]) {
                    vis[i] = 1;
                    curr[k] = nums[i];
                    dfs(k + 1);
                    vis[i] = 0;
                }
            }
        };
        dfs(0);
        return ans;
    }
};
