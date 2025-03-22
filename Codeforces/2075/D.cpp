#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

constexpr i64 INF = 1LL << 61;
std::vector<std::vector<i64>> dp(61, std::vector<i64>(61, INF));

void solve() {
    i64 x = 0, y = 0;
    std::cin >> x >> y;

    i64 ans = INF;
    for (int i = 0; i < 60; i++) {
        for (int j = 0; j < 60; j++) {
            if (x >> i == y >> j) {
                ans = std::min(ans, dp[i][j]);
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    dp[0][0] = 0;
    for (int i = 0; i < 60; i++) {
        for (int j = 59; j >= 0; j--) {
            for (int k = 59; k >= 0; k--) {
                if (j >= i) {
                    dp[j][k] = std::min(dp[j][k], dp[j - i][k] + (1LL << i));
                }
                if (k >= i) {
                    dp[j][k] = std::min(dp[j][k], dp[j][k - i] + (1LL << i));
                }
            }
        }
    }

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
