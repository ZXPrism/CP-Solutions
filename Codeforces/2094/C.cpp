#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<std::vector<int>> grid(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> grid[i][j];
        }
    }

    std::vector<int> cnt(2 * n + 1);
    for (int i = 0; i < n; i++) {
        ++cnt[grid[0][i]];
        ++cnt[grid[n - 1][i]];
    }

    int odd = 0;
    for (int i = 1; i <= 2 * n; i++) {
        if (!cnt[i]) {
            odd = i;
            break;
        }
    }

    std::cout << odd << ' ';
    for (int i = 0; i < n; i++) {
        std::cout << grid[0][i] << ' ';
    }
    for (int i = 1; i < n; i++) {
        std::cout << grid[n - 1][i] << ' ';
    }
    std::cout << '\n';
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
