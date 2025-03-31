#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0;
    std::cin >> n >> m;

    int cc = n;
    std::vector<int> fa(n, -1);
    auto Find = [&](auto &&self, int x) -> int {
        return (fa[x] < 0 ? x : fa[x] = self(self, fa[x]));
    };
    auto Unite = [&](int from, int to) -> void {
        from = Find(Find, from);
        to = Find(Find, to);
        if (from != to) {
            fa[from] = to;
            --cc;
        }
    };

    for (int i = 0; i < m; i++) {
        int u = 0, v = 0;
        std::cin >> u >> v;
        --u, --v;
        Unite(u, v);
    }

    std::cout << m - n + cc;
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
