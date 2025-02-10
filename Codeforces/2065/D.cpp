#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0;
    std::cin >> n >> m;

    std::vector<std::vector<int>> arrays(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> arrays[i][j];
        }
    }

    std::vector<i64> pre(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pre[i] += arrays[i][j];
        }
    }

    std::vector<int> idx(n);
    std::iota(idx.begin(), idx.end(), 0);
    std::sort(idx.begin(), idx.end(), [&](int lhs, int rhs) { return pre[lhs] > pre[rhs]; });

    i64 ans = 0, fac = n * m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++, --fac) {
            ans += fac * arrays[idx[i]][j];
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
