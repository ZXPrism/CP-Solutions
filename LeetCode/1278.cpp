class Solution {
public:
    int palindromePartition(string s, int k) {
        int n = s.size();

        std::vector<std::vector<int>> mismatch(n, std::vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                mismatch[i][j] = (s[i] != s[j]) + mismatch[i - 1][j + 1];
            }
        }

        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(k + 1, n));
        dp[0] = std::vector<int>(k);
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                for (int m = std::max(0, j - 1); m <= i; m++) {
                    dp[i + 1][j] = std::min(dp[i + 1][j], dp[m][j - 1] + mismatch[i][m]);
                }
            }
        }

        return dp[n][k];
    }
};
