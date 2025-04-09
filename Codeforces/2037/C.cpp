#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    if (n <= 4) {
        std::cout << "-1\n";
    } else {
        for (int i = 2; i <= n; i += 2) {
            if (i != 4) {
                std::cout << i << ' ';
            }
        }
        std::cout << "4 5 ";
        for (int i = 1; i <= n; i += 2) {
            if (i != 5) {
                std::cout << i << ' ';
            }
        }
        std::cout << '\n';
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
