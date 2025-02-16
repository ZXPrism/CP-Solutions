#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    std::vector<int> a(6), b(6);
    for (int i = 0; i < 6; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < 6; i++) {
        std::cin >> b[i];
    }

    auto intersect = [](int ax1, int ax2, int bx1, int bx2) { return ax2 > bx1 && bx2 > ax1; };

    if (intersect(a[0], a[3], b[0], b[3]) && intersect(a[1], a[4], b[1], b[4]) &&
        intersect(a[2], a[5], b[2], b[5])) {
        std::cout << "Yes\n";
    } else {
        std::cout << "No\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
