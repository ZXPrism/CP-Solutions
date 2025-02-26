class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size(), ans = std::numeric_limits<int>::min();
        std::vector<int> dp(n + 1);
        for (int i = 0; i < n; i++) {
            dp[i + 1] = std::max(dp[i] + nums[i], nums[i]);
            ans = std::max(ans, dp[i + 1]);
        }
        return ans;
    }
};
