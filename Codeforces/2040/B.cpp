#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    if (n == 1) {
        std::cout << "1\n";
    } else if (n <= 4) {
        std::cout << "2\n";
    } else {
        int x = 4, ans = 2;
        while (x < n) {
            ++ans;
            x = (x << 1) + 2;
        }
        std::cout << ans << '\n';
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
