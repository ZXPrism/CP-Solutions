class Solution {
public:
    int countHousePlacements(int n) {
        constexpr int MOD = 1'000'000'007;
        // dp[k + 2] = dp[k + 1] + dp[k]
        // dp[0] = dp[1] = 1
        std::vector<int> dp(n + 2);
        dp[0] = dp[1] = 1;
        for (int i = 0; i < n; i++) {
            dp[i + 2] = (dp[i + 1] + dp[i]) % MOD;
        }
        return (1LL * dp[n + 1] * dp[n + 1]) % MOD;
    }
};
