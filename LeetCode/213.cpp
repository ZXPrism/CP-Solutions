class Solution {
public:
    int rob(vector<int> &nums) {
        // nums[n-1]?
        // 1: nums[n - 1] + [1, n - 3]
        // 0: [0, n - 2]
        auto F = [&](int left, int right) -> int {
            std::vector<int> dp(right + 3);
            for (int i = left; i <= right; i++) {
                dp[i + 2] = std::max(dp[i + 1], dp[i] + nums[i]);
            }
            return dp[right + 2];
        };

        int n = nums.size();
        return std::max(F(0, n - 2), nums[n - 1] + F(1, n - 3));
    }
};
