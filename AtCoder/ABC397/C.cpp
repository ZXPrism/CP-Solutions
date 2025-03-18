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

    int ans = 0, left = 0;
    std::vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        if (++cnt[v[i]] == 1) {
            ++left;
        }
    }

    int right = 0;
    std::vector<int> curr(n + 1);
    for (int i = n - 1; i > 0; i--) {
        if (--cnt[v[i]] == 0) {
            --left;
        }
        if (++curr[v[i]] == 1) {
            ++right;
        }
        ans = std::max(ans, left + right);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
