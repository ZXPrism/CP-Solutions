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
    std::ranges::sort(v);

    std::vector<std::vector<int>> factors(100001);
    for (auto elem : v) {
        int sqr = static_cast<int>(std::sqrt(elem));
        for (int i = 1; i <= sqr; i++) {
            if (elem % i == 0) {
                factors[i].push_back(elem);
                if (i * i != elem) {
                    factors[elem / i].push_back(elem);
                }
            }
        }
    }

    for (int i = 100000; i >= 1; i--) {
        if (factors[i].size() >= 3) {
            for (int j = 0; j < 3; j++) {
                std::cout << factors[i][j] << " \n"[j == 3];
            }
            return;
        }
    }
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
