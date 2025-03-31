#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::string s, t;
    std::cin >> n >> s >> t;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            ++ans;
        }
    }
    std::cout << ans << '\n';
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
