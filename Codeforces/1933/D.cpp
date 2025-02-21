#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    int x = v[0];
    for (int i = 1; i < n; i++) {
        x = std::gcd(x, v[i]);
    }

    for (int i = 0; i < n; i++) {
        v[i] /= x;
    }

    std::ranges::sort(v);

    if (v[0] == v[1] && v[0] == 1) {
        std::cout << "NO\n";
    } else {
        std::cout << "YES\n";
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
