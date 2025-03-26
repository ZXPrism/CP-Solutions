#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0;
    std::cin >> n >> m;

    std::vector<std::vector<int>> v(n);
    for (int i = 0; i < n; i++) {
        int k = 0;
        std::cin >> k;
        v[i].resize(k);
        for (int j = 0; j < k; j++) {
            std::cin >> v[i][j];
        }
        std::sort(v[i].begin(), v[i].end());
    }

    int q = 0;
    std::cin >> q;

    for (int i = 0; i < q; i++) {
        int a = 0, b = 0;
        std::cin >> a >> b;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            int n_vj = v[j].size();
            int x = std::lower_bound(v[j].begin(), v[j].end(), a) - v[j].begin();
            int y = std::lower_bound(v[j].begin(), v[j].end(), b) - v[j].begin();
            if (x != n_vj && y != n_vj && v[j][x] == a && v[j][y] == b) {
                ++cnt;
            }
        }
        std::cout << cnt << '\n';
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
