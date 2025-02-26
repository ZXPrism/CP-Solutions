class Solution {
public:
    int goodBinaryStrings(int minLength, int maxLength, int oneGroup, int zeroGroup) {
        std::vector<int> dp(maxLength + 1);
        dp[0] = 1;
        constexpr int MOD = 1'000'000'007;
        int ans = 0;
        for (int i = 0; i <= maxLength; i++) {
            if (i >= oneGroup) {
                dp[i] = (dp[i] + dp[i - oneGroup]) % MOD;
            }
            if (i >= zeroGroup) {
                dp[i] = (dp[i] + dp[i - zeroGroup]) % MOD;
            }
            if (i >= minLength) {
                ans = (ans + dp[i]) % MOD;
            }
        }
        return ans;
    }
};
