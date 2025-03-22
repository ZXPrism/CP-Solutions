#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, k = 0;
    std::cin >> n >> k;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    if (k >= 2) {
        std::ranges::sort(v, std::greater<>());
        std::cout << std::reduce(v.begin(), v.begin() + k + 1, 0LL) << '\n';
    } else {
        i64 ans = v.front() + v.back();
        int mx = std::max(v.front(), v.back());
        for (int i = 1; i < n - 1; i++) {
            ans = std::max(ans, 1LL * v[i] + mx);
        }
        std::cout << ans << '\n';
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
