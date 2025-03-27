#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;

    std::vector<int> cnt(26);
    for (auto ch : s) {
        ++cnt[ch - 'a'];
    }

    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= 100) {
            std::cout << std::string(100, i + 'a') << '\n';
            return;
        }
    }

    int n = s.size();
    std::vector<std::vector<int>> dp(n, std::vector<int>(n));

    for (int i = n - 1; i >= 0; i--) {
        dp[i][i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = std::max(dp[i][j - 1], dp[i + 1][j]);
            }
        }
    }

    std::string t;
    int i = 0, j = n - 1;
    while (i < j && t.size() < 50) {
        if (s[i] == s[j]) {
            t.push_back(s[i]);
            ++i, --j;
        } else if (dp[i + 1][j] == dp[i][j]) {
            ++i;
        } else {
            --j;
        }
    }

    std::string rev = t;
    std::reverse(rev.begin(), rev.end());

    if (i == j && t.size() < 50) {
        t.push_back(s[i]);
    }

    std::cout << t << rev << '\n';
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
