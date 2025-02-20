#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0;
    std::cin >> n >> m;

    std::vector<std::vector<int>> v(m, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> v[j][i];
        }
    }

    for (int i = 0; i < m; i++) {
        std::ranges::sort(v[i], std::greater<>());
    }

    i64 ans = 0;
    for (int i = 0; i < m; i++) {
        i64 sum = std::accumulate(v[i].begin(), v[i].end(), 0LL);
        for (int j = 0; j < n; j++) {
            sum -= v[i][j];
            ans += 1LL * (n - j - 1) * v[i][j] - sum;
        }
    }

    std::cout << ans << '\n';
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
