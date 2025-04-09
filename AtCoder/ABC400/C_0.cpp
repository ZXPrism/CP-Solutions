#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    i64 n = 0;
    std::cin >> n;

    i64 a = static_cast<i64>(sqrtl(n >> 1));
    i64 b = static_cast<i64>(sqrtl(n >> 2));
    std::cout << a + b << '\n';
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
