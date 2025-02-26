class Solution {
public:
    int maxMoves(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();

        std::vector<std::vector<int>> dp(n, std::vector<int>(m, -1));
        for (int i = 0; i < m; i++) {
            dp[0][i] = 0;
        }

        int ans = 0;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (j != 0) {
                    if (dp[i - 1][j - 1] != -1 && grid[j][i] > grid[j - 1][i - 1]) {
                        dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 1);
                    }
                }
                if (j != m - 1) {
                    if (dp[i - 1][j + 1] != -1 && grid[j][i] > grid[j + 1][i - 1]) {
                        dp[i][j] = std::max(dp[i][j], dp[i - 1][j + 1] + 1);
                    }
                }
                if (dp[i - 1][j] != -1 && grid[j][i] > grid[j][i - 1]) {
                    dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + 1);
                }

                ans = std::max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};
