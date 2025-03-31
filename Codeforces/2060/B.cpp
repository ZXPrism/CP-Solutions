#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0;
    std::cin >> n >> m;

    std::vector<std::vector<int>> v(n, std::vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> v[i][j];
        }
        std::ranges::sort(v[i]);
    }

    std::vector<int> idx(n);
    std::iota(idx.begin(), idx.end(), 0);
    std::ranges::sort(idx, [&](int lhs, int rhs) { return v[lhs][0] < v[rhs][0]; });

    int k = 0;
    std::vector<int> check(n * m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            check[k++] = v[idx[j]][i];
        }
    }

    if (std::is_sorted(check.begin(), check.end())) {
        for (int i = 0; i < n; i++) {
            std::cout << idx[i] + 1 << " \n"[i == n - 1];
        }
    } else {
        std::cout << "-1\n";
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
