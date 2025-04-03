#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, sum = 0;
    std::cin >> n >> sum;

    std::vector<int> dp(n);
    dp[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = i; j >= 1; j--) {
            dp[j] += dp[j - 1];
        }
    }

    int s = 0;
    bool found = false;
    std::vector<int> vis(n + 1);
    std::vector<int> ans(n);
    auto dfs = [&](auto &&self, int k) -> bool {
        if (s > sum) {
            return false;
        }
        if (k == n) {
            if (s == sum) {
                found = true;
                return true;
            }
            return false;
        }
        for (int i = 1; i <= n; i++) {
            if (!vis[i]) {
                vis[i] = 1;
                ans[k] = i;
                s += dp[k] * i;
                if (self(self, k + 1)) {
                    return true;
                }
                s -= dp[k] * i;
                vis[i] = 0;
            }
        }
        return false;
    };
    if (dfs(dfs, 0)) {
        for (int i = 0; i < n; i++) {
            std::cout << ans[i] << " \n"[i == n - 1];
        }
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
