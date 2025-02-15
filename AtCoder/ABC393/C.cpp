#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0;
    std::cin >> n >> m;

    int ans = 0;
    std::vector<std::set<int>> adj(n);
    for (int i = 0; i < m; i++) {
        int u = 0, v = 0;
        std::cin >> u >> v;
        --u, --v;
        if (u == v) {
            ++ans;
        } else {
            if (!adj[u].contains(v)) {
                adj[u].insert(v);
                adj[v].insert(u);
            } else {
                ++ans;
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
