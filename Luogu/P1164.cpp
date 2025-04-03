#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    std::vector<std::vector<std::vector<i64>>> dp(
        21, std::vector<std::vector<i64>>(21, std::vector<i64>(21, -1)));
    auto dfs = [&](auto &&self, i64 a, i64 b, i64 c) -> i64 {
        if (a <= 0 || b <= 0 || c <= 0) {
            return 1;
        } else if (a > 20 || b > 20 || c > 20) {
            return self(self, 20, 20, 20);
        }
        if (dp[a][b][c] != -1) {
            return dp[a][b][c];
        }
        i64 res = 0;
        if (a < b && b < c) {
            res = self(self, a, b, c - 1) + self(self, a, b - 1, c - 1) - self(self, a, b - 1, c);
        } else {
            res = self(self, a - 1, b, c) + self(self, a - 1, b, c - 1) +
                  self(self, a - 1, b - 1, c) - self(self, a - 1, b - 1, c - 1);
        }
        return dp[a][b][c] = res;
    };
    i64 a = 0, b = 0, c = 0;
    while (1) {
        std::cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) {
            return;
        }
        std::cout << std::format("w({}, {}, {}) = {}\n", a, b, c, dfs(dfs, a, b, c));
    }
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
