#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0, k = 0;
    std::cin >> n >> m >> k;

    std::vector<int> exclude(m);
    for (int i = 0; i < m; i++) {
        std::cin >> exclude[i];
    }

    int missing = 0;
    std::vector<int> answer(k);
    for (int i = 0; i < k; i++) {
        std::cin >> answer[i];
        missing ^= answer[i];
    }

    for (int i = 1; i <= n; i++) {
        missing ^= i;
    }

    if (n - k >= 2) {
        std::cout << std::string(m, '0') << '\n';
    } else if (n == k) {
        std::cout << std::string(m, '1') << '\n';
    } else {
        for (int i = 0; i < m; i++) {
            std::cout << (exclude[i] == missing ? '1' : '0');
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
