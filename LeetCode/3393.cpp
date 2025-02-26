class Solution {
public:
    int countPathsWithXorValue(vector<vector<int>> &grid, int k) {
        constexpr int MOD = 1'000'000'007;
        int m = grid.size(), n = grid[0].size();
        std::vector<std::array<int, 16>> dp(n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    ++dp[j][grid[i][j]];
                    continue;
                }

                auto old = dp[j];
                dp[j] = {};
                for (int k = 0; k < 16; k++) {
                    auto &curr = dp[j][k ^ grid[i][j]];
                    if (i != 0) {
                        curr = (curr + old[k]) % MOD;
                    }
                    if (j != 0) {
                        curr = (curr + dp[j - 1][k]) % MOD;
                    }
                }
            }
        }

        return dp[n - 1][k];
    }
};
