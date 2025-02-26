class Solution {
public:
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost) {
        int m = grid.size(), n = grid[0].size();

        std::vector<std::vector<int>> dp(m, std::vector<int>(n));
        for (int i = 0; i < n; i++) {
            dp[0][i] = grid[0][i];
        }
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int min_cost = std::numeric_limits<int>::max();
                for (int k = 0; k < n; k++) {
                    min_cost = std::min(min_cost, dp[i - 1][k] + moveCost[grid[i - 1][k]][j]);
                }
                dp[i][j] = min_cost + grid[i][j];
            }
        }

        return *std::ranges::min_element(dp[m - 1]);
    }
};
