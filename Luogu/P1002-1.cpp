#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0, hx = 0, hy = 0;
    std::cin >> n >> m >> hx >> hy;

    std::vector<std::vector<i64>> dp(n + 1, std::vector<i64>(m + 1));
    dp[0][0] = 1;

    auto F = [&](int x, int y) -> void {
        if (x >= 0 && x <= n && y >= 0 && y <= m) {
            dp[x][y] = -1;
        }
    };
    F(hx, hy);
    for (auto dx : {-1, 1}) {
        for (auto dy : {-2, 2}) {
            F(hx + dx, hy + dy);
        }
    }
    for (auto dx : {-2, 2}) {
        for (auto dy : {-1, 1}) {
            F(hx + dx, hy + dy);
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (dp[i][j] != -1) {
                if (i != 0 && dp[i - 1][j] != -1) {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j != 0 && dp[i][j - 1] != -1) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
    }

    std::cout << dp[n][m] << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
