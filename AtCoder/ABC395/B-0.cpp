#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<std::string> grid(n, std::string(n, '.'));

    constexpr int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
    for (int i = 0; i < n / 2; i++) {
        if (i % 2 == 0) {
            int x = i, y = i - 1, d = 0, cnt = 4 * (n - 2 * i) - 4, len = n - 2 * i;
            for (int j = 0; j < cnt; j++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < i || nx > i + len - 1 || ny < i || ny > i + len - 1) {
                    ++d;
                    nx = x + dx[d], ny = y + dy[d];
                }
                grid[nx][ny] = '#';
                x = nx, y = ny;
            }
        }
    }

    if (n % 4 == 1) {
        grid[n / 2][n / 2] = '#';
    }

    for (int i = 0; i < n; i++) {
        std::cout << grid[i] << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
