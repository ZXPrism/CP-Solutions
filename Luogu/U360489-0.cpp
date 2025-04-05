#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    i64 ans = 0;
    for (int i = 0; i < 20; i++) {
        i64 f0 = 0, f1 = 0, tot = 0;
        for (int j = 0; j < n; j++) {
            if (v[j] >> i & 1) {
                std::tie(f0, f1) = std::make_tuple(f1, f0 + 1);
            } else {
                ++f0;
            }
            tot += f1;
        }
        ans += tot << i;
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
