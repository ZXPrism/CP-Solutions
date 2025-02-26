class Solution {
public:
    int deleteAndEarn(vector<int> &nums) {
        int mx = *std::ranges::max_element(nums);
        std::vector<int> cnt(mx + 1);
        for (auto elem : nums) {
            ++cnt[elem];
        }
        // dp[i+2] = max(dp[i + 1], dp[i] + cnt[i] * i)
        // dp[<=2] = 0
        std::vector<int> dp(mx + 3);
        for (int i = 1; i <= mx; i++) {
            dp[i + 2] = std::max(dp[i + 1], dp[i] + cnt[i] * i);
        }

        return dp[mx + 2];
    }
};
