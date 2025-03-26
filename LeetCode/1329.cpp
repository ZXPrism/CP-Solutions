class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        for (int k = 0; k < m + n - 1; k++) {
            std::vector<int> diag;
            int lb = std::max(0, k - n + 1), ub = std::min(m - 1, k);
            for (int i = lb; i <= ub; i++) {
                diag.push_back(mat[i][i + n - 1 - k]);
            }
            std::ranges::sort(diag);
            for (int i = lb; i <= ub; i++) {
                mat[i][i + n - 1 - k] = diag[i - lb];
            }
        }
        return mat;
    }
};
