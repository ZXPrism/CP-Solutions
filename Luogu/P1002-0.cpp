#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0, hx = 0, hy = 0;
    std::cin >> n >> m >> hx >> hy;

    auto check = [&](int x, int y) -> bool {
        if (x == hx && y == hy) {
            return false;
        }
        for (auto dx : {-1, 1}) {
            for (auto dy : {-2, 2}) {
                if (hx + dx == x && hy + dy == y) {
                    return false;
                }
            }
        }
        for (auto dx : {-2, 2}) {
            for (auto dy : {-1, 1}) {
                if (hx + dx == x && hy + dy == y) {
                    return false;
                }
            }
        }
        return true;
    };

    std::vector<i64> dp(m + 1);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i == 0 && j == 0) {
                dp[0] = check(0, 0);
                continue;
            }

            i64 top = dp[j];
            dp[j] = 0;
            if (check(i, j)) {
                if (i != 0) {
                    dp[j] += top;
                }
                if (j != 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }
    }

    std::cout << dp[m] << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
