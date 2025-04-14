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

    std::vector<int> cnt(30);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 30; j++) {
            cnt[j] += v[i] >> j & 1;
        }
    }

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        i64 curr = 0;
        for (int j = 0; j < 30; j++) {
            if (v[i] >> j & 1) {
                curr += 1LL * (n - cnt[j]) << j;
            } else {
                curr += 1LL * cnt[j] << j;
            }
        }
        ans = std::max(ans, curr);
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
