#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, x = 0;
    std::cin >> n >> x;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    i64 pre = 0, ans = 0;
    std::map<i64, int> cnt;
    cnt[0] = 1;
    for (int i = 0; i < n; i++) {
        pre += v[i];
        ans += cnt[pre - x];
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
