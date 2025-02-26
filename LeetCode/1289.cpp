class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &grid) {
        int n = grid.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(n));
        for (int i = 0; i < n; i++) {
            dp[0][i] = grid[0][i];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int min_cost = std::numeric_limits<int>::max();
                for (int k = 0; k < n; k++) {
                    if (k != j) {
                        min_cost = std::min(min_cost, dp[i - 1][k]);
                    }
                }
                dp[i][j] = min_cost + grid[i][j];
            }
        }
        return *std::ranges::min_element(dp[n - 1]);
    }
};
