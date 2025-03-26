class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>> &grid) {
        int n = grid.size();
        for (int k = 0; k < 2 * n - 1; k++) {
            std::vector<int> diag;
            int lb = std::max(0, k - n + 1), ub = std::min(n - 1, k);
            for (int i = lb; i <= ub; i++) {
                diag.push_back(grid[i][i - k + n - 1]);
            }
            if (k < n - 1) {
                std::ranges::sort(diag);
            } else {
                std::ranges::sort(diag, std::greater<>());
            }
            for (int i = lb; i <= ub; i++) {
                grid[i][i - k + n - 1] = diag[i - lb];
            }
        }
        return grid;
    }
};
