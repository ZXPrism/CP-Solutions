#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    i64 n = 0;
    std::cin >> n;

    i64 ans = 0;
    for (int i = 1; i < 3; i++) {
        i64 left = 0, right = 1'000'000'000, mid = 0;
        while (left + 1 < right) {
            mid = (left + right) >> 1;
            if ((1 << i) * mid * mid <= n) {
                left = mid;
            } else {
                right = mid;
            }
        }
        ans += left;
    }

    std::cout << ans << '\n';
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
