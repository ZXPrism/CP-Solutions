class Solution {
public:
    int minimumEffortPath(vector<vector<int>> &heights) {
        int n = heights.size(), m = heights[0].size();
        constexpr int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
        auto check = [&](int lim) -> bool {
            std::vector<std::vector<int>> vis(n, std::vector<int>(m));
            std::queue<std::pair<int, int>> q;
            q.push({0, 0});
            vis[0][0] = 1;
            while (!q.empty()) {
                auto [x, y] = q.front();
                q.pop();
                for (int i = 0; i < 4; i++) {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] &&
                        std::abs(heights[x][y] - heights[nx][ny]) <= lim) {
                        vis[nx][ny] = 1;
                        q.push({nx, ny});
                    }
                }
            }
            return vis[n - 1][m - 1];
        };
        int left = -1, right = 1'000'001, mid = 0;
        while (left + 1 < right) {
            mid = (left + right) / 2;
            if (check(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
        return right;
    }
};
