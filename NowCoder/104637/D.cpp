#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int x = 0, y = 0;
    std::cin >> x >> y;
    // 0 <= x ^ y = x + y - 2(x & y) <= x + y
    // 0 <= x & y <= min(x, y)
    // 0 <= x | y <= x + y
    // 1 <= gcd(x, y) <= min(x, y)

    // gcd(x, gcd(x, y)) = gcd(x, y)
    // ans <= 3
    // ans == 1 --> x == y
    // ans == 2 --> brute force
    // otherwise, ans = 3

    int a = x ^ y, b = x & y, c = x | y, d = std::gcd(x, y);
    if (a == 0 || b == 0) {
        std::cout << "1\n";
    } else {
        auto check = [&](int t) -> int {
            return ((t ^ x) == 0) || (((t ^ y) == 0)) || ((t & x) == 0) || (((t & y) == 0));
        };
        if (check(a) || check(b) || check(c) || check(d)) {
            std::cout << "2\n";
        } else {
            std::cout << "3\n";
        }
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
