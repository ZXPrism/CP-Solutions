#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> v(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i + 1];
        v[i + 1] ^= v[i];
    }

    i64 ans = 0;
    for (int i = 0; i < 20; i++) {
        int cnt = 0;
        for (int j = 0; j <= n; j++) {
            cnt += v[j] >> i & 1;
        }
        ans += (1LL * cnt * (n + 1 - cnt)) << i;
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
