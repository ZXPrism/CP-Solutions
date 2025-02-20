#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int h = 0, w = 0, d = 0;
    std::cin >> h >> w >> d;

    std::vector<std::string> grid(h);
    for (int i = 0; i < h; i++) {
        std::cin >> grid[i];
    }

    constexpr int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> dist(h, std::vector<int>(w, h * w + 1));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == 'H') {
                dist[i][j] = 0;
                q.push({i, j}); // 1. multiple source?
            }
        }
    }

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k], ny = y + dy[k];
            if (nx >= 0 && nx < h && ny >= 0 && ny < w && grid[nx][ny] != '#' &&
                dist[nx][ny] == h * w + 1) {
                dist[nx][ny] = dist[x][y] + 1; // 2. don't need to use `min`!
                q.push({nx, ny});
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (dist[i][j] <= d) {
                ++ans;
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
