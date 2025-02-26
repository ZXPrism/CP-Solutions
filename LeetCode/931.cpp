class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &matrix) {
        int n = matrix.size();
        std::vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            dp[i] = matrix[0][i];
        }
        for (int i = 1; i < n; i++) {
            int t = 0;
            for (int j = 0; j < n; j++) {
                int tt = dp[j];
                if (j == 0) {
                    dp[j] = std::min(dp[j], dp[j + 1]) + matrix[i][j];
                } else if (j == n - 1) {
                    dp[j] = std::min(t, dp[j]) + matrix[i][j];
                } else {
                    dp[j] = std::min({t, dp[j], dp[j + 1]}) + matrix[i][j];
                }
                t = tt;
            }
        }
        return *std::ranges::min_element(dp);
    }
};
