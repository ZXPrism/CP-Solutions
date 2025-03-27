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

    std::ranges::sort(v);

    std::vector<int> left(n);
    for (int l = 0, r = 0; r < n; r++) {
        while (v[r] - v[l] > k) {
            ++l;
        }
        left[r] = l;
    }

    // This DP solution should only work for segment num = 2...?
    constexpr int INF = 0x3f3f3f3f;
    std::vector<std::vector<int>> dp(3, std::vector<int>(n + 1));
    for (int i = 1; i <= 2; i++) {
        dp[i][0] = -INF;
        for (int j = 0; j < n; j++) {
            dp[i][j + 1] = std::max(dp[i][j], dp[i - 1][left[j]] + j - left[j] + 1);
        }
    }

    std::cout << dp[2][n] << '\n';
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
