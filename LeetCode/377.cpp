class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        int n = nums.size();
        // dp[x] += dp[x - nums[i]]
        // dp[0] = 1
        std::vector<unsigned long long> dp(target + 1);
        dp[0] = 1;

        for (int i = 0; i <= target; i++) {
            for (int j = 0; j < n; j++) {
                if (i >= nums[j]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }

        return dp[target];
    }
};
