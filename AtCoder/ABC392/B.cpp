#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0;
    std::cin >> n >> m;

    std::vector<int> cnt(n + 1);
    for (int i = 0; i < m; i++) {
        int t = 0;
        std::cin >> t;
        cnt[t] = 1;
    }

    std::vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (!cnt[i]) {
            ans.push_back(i);
        }
    }

    std::cout << ans.size() << '\n';
    for (auto elem : ans) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
