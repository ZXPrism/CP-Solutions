class Solution {
public:
    int longestLine(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int j = 0;
            while (j < n) {
                int right = j + 1;
                while (right < n && mat[i][j] == mat[i][right]) {
                    ++right;
                }
                if (mat[i][j] == 1) {
                    ans = std::max(ans, right - j);
                }
                j = right;
            }
        }
        for (int j = 0; j < n; j++) {
            int i = 0;
            while (i < m) {
                int right = i + 1;
                while (right < m && mat[i][j] == mat[right][j]) {
                    ++right;
                }
                if (mat[i][j] == 1) {
                    ans = std::max(ans, right - i);
                }
                i = right;
            }
        }
        for (int k = 0; k < m + n - 1; k++) {
            int lb = std::max(0, k - n + 1), ub = std::min(m - 1, k);
            while (lb <= ub) {
                int right = lb + 1;
                while (right <= ub && mat[lb][k - lb] == mat[right][k - right]) {
                    ++right;
                }
                if (mat[lb][k - lb] == 1) {
                    ans = std::max(ans, right - lb);
                }
                lb = right;
            }
        }
        for (int k = 0; k < m + n - 1; k++) {
            int lb = std::max(0, k - n + 1), ub = std::min(m - 1, k);
            while (lb <= ub) {
                int right = lb + 1;
                while (right <= ub && mat[lb][lb - k + n - 1] == mat[right][right - k + n - 1]) {
                    ++right;
                }
                if (mat[lb][lb - k + n - 1] == 1) {
                    ans = std::max(ans, right - lb);
                }
                lb = right;
            }
        }
        return ans;
    }
};
