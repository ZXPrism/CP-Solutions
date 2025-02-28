#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, k = 0, p = 0;
    std::cin >> n >> k >> p;

    if (k < -n * p || k > n * p) {
        std::cout << "-1\n";
        return;
    }

    k = std::abs(k);
    std::cout << k / p + (k % p != 0) << '\n';
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
