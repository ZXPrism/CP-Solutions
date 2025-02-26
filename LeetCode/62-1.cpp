class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<int> dp(n + 1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dp[1] = 1;
                }
                dp[j + 1] += dp[j];
            }
        }
        return dp[n];
    }
};
