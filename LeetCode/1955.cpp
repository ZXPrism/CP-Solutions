class Solution {
public:
    int countSpecialSubsequences(vector<int> &nums) {
        int n = nums.size();
        constexpr int MOD = 1'000'000'007;
        std::vector<int> dp(4);
        dp[0] = 1;
        for (int i = 0; i < n; i++) {
            dp[nums[i] + 1] = (1LL * dp[nums[i] + 1] + dp[nums[i] + 1] + dp[nums[i]]) % MOD;
        }
        return dp[3];
    }
};
