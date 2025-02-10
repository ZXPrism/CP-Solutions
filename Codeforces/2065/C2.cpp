#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0;
    std::cin >> n >> m;

    std::vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        std::cin >> b[i];
    }

    std::sort(b.begin(), b.end());

    a[0] = std::min(a[0], b[0] - a[0]);
    for (int i = 0; i < n - 1; i++) {
        auto iter = std::lower_bound(b.begin(), b.end(), a[i] + a[i + 1]);

        if (a[i] <= a[i + 1]) {
            if (iter != b.end()) {
                a[i + 1] = std::min(a[i + 1], *iter - a[i + 1]);
            }
        } else if (iter != b.end()) {
            a[i + 1] = *iter - a[i + 1];
        } else {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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
