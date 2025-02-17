#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0;
    std::cin >> n >> m;

    std::string s;
    std::cin >> s;

    std::vector<int> cnt(7);
    for (auto ch : s) {
        ++cnt[ch - 'A'];
    }

    int ans = 0;
    for (int i = 0; i < 7; i++) {
        ans += std::max(0, m - cnt[i]);
    }

    std::cout << ans << '\n';
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
