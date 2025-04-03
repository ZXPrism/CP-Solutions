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

    i64 pre = 0, ans = 0, bias = 1'000'000'000LL * n;
    std::vector<int> cnt(n);
    cnt[0] = 1;
    for (int i = 0; i < n; i++) {
        pre = (pre + v[i] + bias) % n;
        ans += cnt[pre];
        ++cnt[pre];
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
