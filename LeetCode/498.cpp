class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        std::vector<int> ans(m * n);
        int ptr = 0;
        for (int k = 0; k < m + n - 1; k++) {
            int lb = std::max(0, k - n + 1), ub = std::min(m - 1, k);
            if (k % 2 == 0) {
                for (int i = ub; i >= lb; i--) {
                    ans[ptr++] = mat[i][k - i];
                }
            } else {
                for (int i = lb; i <= ub; i++) {
                    ans[ptr++] = mat[i][k - i];
                }
            }
        }
        return ans;
    }
};
