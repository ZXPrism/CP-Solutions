#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, k = 0;
    std::cin >> n >> k;

    int comb[2][2] = {{1, 0}, {1, 1}};

    auto Calc = [&](auto &&self, int n, int m) -> int {
        if (m == 0) {
            return 1;
        }
        return (self(self, n / 2, m / 2) * comb[n & 1][m & 1]) & 1;
    };

    for (int i = 0; i < n; i++) {
        std::cout << Calc(Calc, n - 1, i) * k << " \n"[i == n - 1];
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
