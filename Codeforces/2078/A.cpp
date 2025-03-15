#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    // S <- S / L
    // |a| <- |a| / L
    // S' = |a| * x
    // S = x * |a| * L1 * L2 * ..
    // S = x * |a0| / L1 / L2 * L1 * L2 = x * |a0|
    int n = 0, x = 0;
    std::cin >> n >> x;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    int sum = std::reduce(v.begin(), v.end());
    std::cout << (sum == n * x ? "YES\n" : "NO\n");
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
