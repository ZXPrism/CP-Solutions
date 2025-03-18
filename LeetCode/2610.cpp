class Solution {
public:
    vector<vector<int>> findMatrix(vector<int> &nums) {
        int n = nums.size(), mx = 0;
        std::vector<int> cnt(n + 1);
        for (auto elem : nums) {
            ++cnt[elem];
            mx = std::max(mx, cnt[elem]);
        }
        std::vector<std::vector<int>> ans(mx);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < cnt[i]; j++) {
                ans[j].push_back(i);
            }
        }
        return ans;
    }
};
