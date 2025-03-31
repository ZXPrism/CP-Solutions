#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    int need_val = -1;
    bool need = false;
    int extra = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        if (a[i] >= b[i]) {
            extra = std::min(extra, a[i] - b[i]);
        } else if (!need) {
            need = true;
            need_val = b[i] - a[i];
        } else {
            std::cout << "NO\n";
            return;
        }
    }

    if (!need || need_val <= extra) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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
