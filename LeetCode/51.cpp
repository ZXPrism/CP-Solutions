class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> ans;
        std::vector<std::string> grid(n, std::string(n, '.'));
        int col_mask = 0, diag_mask = 0, subdiag_mask = 0;
        auto dfs = [&](this auto &&dfs, int row) {
            if (row == n) {
                ans.push_back(grid);
                return;
            }
            for (int col = 0; col < n; col++) {
                int diag = row + n - 1 - col, subdiag = row + col;
                if (!(col_mask >> col & 1 || diag_mask >> diag & 1 ||
                      subdiag_mask >> subdiag & 1)) {
                    col_mask ^= 1 << col;
                    diag_mask ^= 1 << diag;
                    subdiag_mask ^= 1 << subdiag;
                    grid[row][col] = 'Q';
                    dfs(row + 1);
                    grid[row][col] = '.';
                    col_mask ^= 1 << col;
                    diag_mask ^= 1 << diag;
                    subdiag_mask ^= 1 << subdiag;
                }
            }
        };
        dfs(0);
        return ans;
    }
};
