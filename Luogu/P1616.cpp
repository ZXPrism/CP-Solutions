#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int t = 0, m = 0;
    std::cin >> t >> m;

    std::vector<int> time(m), value(m);
    for (int i = 0; i < m; i++) {
        std::cin >> time[i] >> value[i];
    }

    std::vector<i64> dp(t + 1);
    for (int i = 0; i < m; i++) {
        for (int j = time[i]; j <= t; j++) {
            dp[j] = std::max(dp[j], dp[j - time[i]] + value[i]);
        }
    }

    std::cout << dp[t] << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
