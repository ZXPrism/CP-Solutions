class Solution {
public:
    int maxProductPath(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();

        std::vector<std::vector<long long>> dpMax(m, std::vector<long long>(n));
        std::vector<std::vector<long long>> dpMin(m, std::vector<long long>(n));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    dpMax[0][0] = grid[0][0];
                    dpMin[0][0] = grid[0][0];
                    continue;
                }
                if (i == 0) {
                    if (grid[i][j] >= 0) {
                        dpMax[i][j] = dpMax[i][j - 1] * grid[i][j];
                        dpMin[i][j] = dpMin[i][j - 1] * grid[i][j];
                    } else {
                        dpMax[i][j] = dpMin[i][j - 1] * grid[i][j];
                        dpMin[i][j] = dpMax[i][j - 1] * grid[i][j];
                    }
                } else if (j == 0) {
                    if (grid[i][j] >= 0) {
                        dpMax[i][j] = dpMax[i - 1][j] * grid[i][j];
                        dpMin[i][j] = dpMin[i - 1][j] * grid[i][j];
                    } else {
                        dpMax[i][j] = dpMin[i - 1][j] * grid[i][j];
                        dpMin[i][j] = dpMax[i - 1][j] * grid[i][j];
                    }
                } else {
                    if (grid[i][j] >= 0) {
                        dpMax[i][j] =
                            std::max(dpMax[i][j - 1] * grid[i][j], dpMax[i - 1][j] * grid[i][j]);
                        dpMin[i][j] =
                            std::min(dpMin[i][j - 1] * grid[i][j], dpMin[i - 1][j] * grid[i][j]);
                    } else {
                        dpMax[i][j] =
                            std::max(dpMin[i][j - 1] * grid[i][j], dpMin[i - 1][j] * grid[i][j]);
                        dpMin[i][j] =
                            std::min(dpMax[i][j - 1] * grid[i][j], dpMax[i - 1][j] * grid[i][j]);
                    }
                }
            }
        }

        return (dpMax[m - 1][n - 1] >= 0 ? dpMax[m - 1][n - 1] % 1'000'000'007 : -1);
    }
};
