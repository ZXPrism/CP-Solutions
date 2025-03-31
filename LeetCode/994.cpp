class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        std::vector<std::vector<int>> min_dist(m, std::vector<int>(n, -1));
        std::queue<std::pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    min_dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        constexpr int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx >= 0 && nx < m && ny >= 0 && ny < n && grid[nx][ny] == 1 &&
                    min_dist[nx][ny] == -1) {
                    min_dist[nx][ny] = min_dist[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (min_dist[i][j] != -1) {
                    ans = std::max(ans, min_dist[i][j]);
                } else if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return ans;
    }
};
