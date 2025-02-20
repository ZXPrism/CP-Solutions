#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0;
    std::cin >> n >> m;

    std::vector<std::vector<int>> grid(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> grid[i][j];
        }
    }

    std::vector<int> exist(n * m + 1), extra(n * m + 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            exist[grid[i][j]] = 1;
            if (i < n - 1 && grid[i][j] == grid[i + 1][j]) {
                extra[grid[i][j]] = 1;
            }
            if (j < m - 1 && grid[i][j] == grid[i][j + 1]) {
                extra[grid[i][j]] = 1;
            }
        }
    }

    std::cout << std::accumulate(exist.begin(), exist.end(), 0) +
                     std::accumulate(extra.begin(), extra.end(), 0) - 1 - std::ranges::max(extra)
              << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
