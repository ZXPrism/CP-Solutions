#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.size();
    constexpr int MOD = 1'000'000'007;

    int ans = 0, pre = 0;
    std::vector<int> cnt(2 * n + 1);
    std::vector<i64> sum(2 * n + 1);
    for (int right = 0; right < n; right++) {
        int eigen = 2 * (pre + (s[right] == '1')) - (right + 1);
        ans = (ans + 1LL * (n - right) * (sum[eigen + n] + cnt[eigen + n])) % MOD;

        ++cnt[2 * pre - right + n];
        sum[2 * pre - right + n] += right;
        pre += (s[right] == '1');
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
