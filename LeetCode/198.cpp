class Solution {
public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        // dp[x + 2] = max(dp[x + 1], dp[x] + nums[x])
        // dp[1] = dp[0] = 0
        std::vector<int> dp(n + 2);
        for (int i = 0; i < n; i++) {
            dp[i + 2] = std::max(dp[i + 1], dp[i] + nums[i]);
        }
        return dp[n + 1];
    }
};
