#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    int prev = -1, tot = 0;
    for (int i = 0; i < n; i++) {
        int t = 0, v = 0;
        std::cin >> t >> v;
        if (prev != -1) {
            tot = std::max(0, tot - (t - prev));
        }
        prev = t;
        tot += v;
    }

    std::cout << tot << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
