#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> val(n);
    for (int i = 0; i < n; i++) {
        std::cin >> val[i];
    }

    std::string ans(n, '0');
    std::vector<std::vector<int>> adj(n);
    for (int i = 1; i < n; i++) {
        int u = 0, v = 0;
        std::cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        if (val[u] == val[v]) {
            ans[val[u] - 1] = '1';
        }
    }

    for (int i = 0; i < n; i++) {
        std::map<int, int> cnt;
        for (auto neighbor : adj[i]) {
            ++cnt[val[neighbor]];
        }
        for (auto [value, times] : cnt) {
            if (times >= 2) {
                ans[value - 1] = '1';
            }
        }
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
