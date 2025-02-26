class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        constexpr int MOD = 1'000'000'007;
        // dp[x] = dp[x - zero] + dp[x - one]
        // dp[0] = 1
        std::vector<int> dp(high + 1);
        dp[0] = 1;

        int ans = 0;
        for (int i = 0; i <= high; i++) {
            if (i >= zero) {
                dp[i] = (dp[i] + dp[i - zero]) % MOD;
            }
            if (i >= one) {
                dp[i] = (dp[i] + dp[i - one]) % MOD;
            }
            if (i >= low) {
                ans = (ans + dp[i]) % MOD;
            }
        }

        return ans;
    }
};
