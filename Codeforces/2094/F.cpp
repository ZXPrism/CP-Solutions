#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0, k = 0;
    std::cin >> n >> m >> k;

    std::vector<std::vector<int>> grid(n, std::vector<int>(m));
    if (n % k != 0) {
        int p = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                grid[j][i] = 1 + p % k;
                ++p;
            }
        }
    } else if (m % k != 0) {
        int p = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                grid[i][j] = 1 + p % k;
                ++p;
            }
        }
    } else {
        for (int i = 0; i < n; i++) {
            if (i & 1) {
                int p = 0;
                for (int j = 0; j < m; j++) {
                    grid[i][j] = 1 + p % k;
                    ++p;
                }
            } else {
                int p = 1;
                for (int j = 0; j < m; j++) {
                    grid[i][j] = 1 + p % k;
                    ++p;
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << grid[i][j] << ' ';
        }
        std::cout << '\n';
    }
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
