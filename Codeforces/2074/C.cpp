#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    unsigned x = 0;
    std::cin >> x;
    int hb = 31 - __builtin_clz(x);
    int y = (1 << hb) - 1;
    if ((x & y) != 0 && y != 0 && y + (x ^ y) > x) {
        std::cout << y << '\n';
    } else {
        std::cout << "-1\n";
    }
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
