#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0;
    std::cin >> n >> m;

    std::vector<int> req(m);
    for (int i = 0; i < m; i++) {
        std::cin >> req[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int t = 0;
            std::cin >> t;
            req[j] -= t;
        }
    }

    for (int i = 0; i < m; i++) {
        if (req[i] > 0) {
            std::cout << "No\n";
            return;
        }
    }

    std::cout << "Yes\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
