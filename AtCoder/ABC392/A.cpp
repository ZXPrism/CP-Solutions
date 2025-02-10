#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    std::vector<int> v(3);
    for (int i = 0; i < 3; i++) {
        std::cin >> v[i];
    }

    for (int i = 0; i < 3; i++) {
        if (v[i] * v[(i + 1) % 3] == v[(i + 2) % 3]) {
            std::cout << "Yes\n";
            return;
        }
    }

    std::cout << "No\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
