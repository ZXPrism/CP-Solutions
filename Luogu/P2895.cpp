#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    constexpr int INF = std::numeric_limits<int>::max();
    std::vector<std::vector<int>> dist(302, std::vector<int>(302, INF));

    constexpr int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};

    int m = 0;
    std::cin >> m;
    for (int i = 0; i < m; i++) {
        int x = 0, y = 0, t = 0;
        std::cin >> x >> y >> t;
        dist[x][y] = std::min(dist[x][y], t);
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0) {
                dist[nx][ny] = std::min(dist[nx][ny], t);
            }
        }
    }

    if (!dist[0][0]) {
        std::cout << "-1\n";
        return;
    }

    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && ny >= 0 && dist[x][y] + 1 < dist[nx][ny]) {
                if (dist[nx][ny] == INF) {
                    std::cout << dist[x][y] + 1 << '\n';
                    return;
                }
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }

    std::cout << "-1\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
