class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        std::vector<int> dp(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0 && !obstacleGrid[i][j]) {
                    dp[j] = 1;
                } else if (!obstacleGrid[i][j]) {
                    if (i == 0 || j != 0) {
                        dp[j] += dp[j - 1];
                    }
                } else {
                    dp[j] = 0;
                }
            }
        }
        return dp[n - 1];
    }
};
