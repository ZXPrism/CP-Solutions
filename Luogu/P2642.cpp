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

    constexpr i64 INF = std::numeric_limits<i64>::max();
    std::vector<i64> dp(n + 1);
    std::vector<i64> pre_max(n + 1, -INF);
    for (int i = 0; i < n; i++) {
        dp[i + 1] = std::max(dp[i], 0LL) + v[i];
        pre_max[i + 1] = std::max(pre_max[i], dp[i + 1]);
    }

    i64 dp_suf = 0, ans = -INF;
    for (int i = n - 1; i >= 2; i--) {
        dp_suf = std::max(dp_suf, 0LL) + v[i];
        ans = std::max(ans, dp_suf + pre_max[i - 1]);
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
