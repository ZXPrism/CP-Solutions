#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, a = 0, b = 0;
    std::cin >> n >> a >> b; // all 5e5

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    auto check = [&](int t) -> bool {
        i64 tot = 0;
        for (int i = 0; i < n; i++) {
            tot += (std::max(0LL, v[i] - 1LL * t * a) + b - 1) / b;
        }
        return tot <= t;
    };

    int left = 0, right = 500001, mid = 0;
    while (left + 1 < right) {
        mid = (left + right) >> 1;
        if (check(mid)) {
            right = mid;
        } else {
            left = mid;
        }
    }

    std::cout << right << '\n';
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
