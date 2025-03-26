class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<int>> ans(m, std::vector<int>(n));
        std::vector<std::vector<int>> cnt(m + n - 1, std::vector<int>(51));
        std::vector<int> distinct(m + n - 1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                distinct[i + n - 1 - j] += (++cnt[i + n - 1 - j][grid[i][j]] == 1);
            }
        }
        std::vector<std::vector<int>> cnt_pre(m + n - 1, std::vector<int>(51));
        std::vector<int> distinct_pre(m + n - 1);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                distinct[i + n - 1 - j] -= (--cnt[i + n - 1 - j][grid[i][j]] == 0);
                ans[i][j] = std::abs(distinct[i + n - 1 - j] - distinct_pre[i + n - 1 - j]);
                distinct_pre[i + n - 1 - j] += (++cnt_pre[i + n - 1 - j][grid[i][j]] == 1);
            }
        }
        return ans;
    }
};
