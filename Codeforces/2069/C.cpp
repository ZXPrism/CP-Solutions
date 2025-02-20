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

    // let dp[i][j] = the number of subsequences in [0, i] whose state is j
    // dp[i][1] = dp[i - 1][1] + (1 if x == 1)
    // dp[i][2] = dp[i - 1][2] + (dp[i - 1][1] + dp[i - 1][2] if x == 2)
    // dp[i][3] = dp[i - 1][3] + (dp[i - 1][2] if x == 3)
    // reduced to : dp[x] += dp[x - 1] + (dp[x] if x == 2)

    constexpr int MOD = 998'244'353;
    std::vector<int> dp(4);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        int delta = dp[v[i] - 1];
        if (v[i] == 2) {
            delta += dp[2];
        }
        dp[v[i]] = (dp[v[i]] + delta) % MOD;
    }

    std::cout << dp[3] << '\n';
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
