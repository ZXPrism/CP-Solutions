#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, k = 0;
    std::cin >> n >> k;

    if (k & 1) {
        for (int i = 0; i < n - 1; i++) {
            std::cout << n << ' ';
        }
        std::cout << n - 1 << '\n';
    } else {
        for (int i = 0; i < n - 2; i++) {
            std::cout << n - 1 << ' ';
        }
        std::cout << n << ' ' << n - 1 << '\n';
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
