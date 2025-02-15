#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int x = 0, y = 0, k = 0;
    std::cin >> x >> y >> k;

    int m = std::min(x, y);
    std::cout << std::format("{} {} {} {}\n", 0, 0, m, m);
    std::cout << std::format("{} {} {} {}\n", 0, m, m, 0);
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
