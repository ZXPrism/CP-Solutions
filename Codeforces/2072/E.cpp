#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int k = 0, tot = 0;
    std::cin >> k;
    std::vector<int> segment;
    while (k) {
        int delta = (1 + std::sqrt(1 + 8 * k)) / 2;
        k -= delta * (delta - 1) / 2;
        tot += delta;
        segment.push_back(delta);
    }

    std::cout << tot << '\n';

    int x = 0, y = 0;
    for (auto elem : segment) {
        for (int i = 0; i < elem; i++) {
            std::cout << x << ' ' << y << '\n';
            ++x;
        }
        ++y;
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
