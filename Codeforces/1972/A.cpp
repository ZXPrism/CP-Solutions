#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    for (int i = 0; i <= n; i++) {
        bool flag = true;
        for (int j = 0; j < n - i; j++) {
            if (a[j] > b[i + j]) {
                flag = false;
            }
        }
        if (flag) {
            std::cout << i << '\n';
            return;
        }
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
