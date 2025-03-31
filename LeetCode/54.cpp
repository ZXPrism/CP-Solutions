class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        std::vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        std::vector<std::vector<int>> vis(m + 2, std::vector<int>(n + 2));
        for (int i = 0; i < n + 2; i++) {
            vis[0][i] = vis[m + 1][i] = 1;
        }
        for (int i = 0; i < m + 2; i++) {
            vis[i][0] = vis[i][n + 1] = 1;
        }
        int i = 0, j = 0, d = 0;
        constexpr int di[] = {0, 1, 0, -1}, dj[] = {1, 0, -1, 0};
        for (int k = 0; k < m * n; k++) {
            vis[i + 1][j + 1] = 1;
            ans.push_back(matrix[i][j]);
            int ni = i + di[d], nj = j + dj[d];
            if (vis[ni + 1][nj + 1]) {
                d = (d + 1) % 4;
            }
            i = i + di[d], j = j + dj[d];
        }
        return ans;
    }
};
