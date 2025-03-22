#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, k = 0;
    std::cin >> n >> k;

    int ans = 0;

    if (n & 1) {
        n -= std::min(n, k);
        ++ans;
    }

    while (n) {
        int sub = std::min(n, k - 1);
        ans += n / sub;
        n %= sub;
    }

    std::cout << ans << '\n';
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
