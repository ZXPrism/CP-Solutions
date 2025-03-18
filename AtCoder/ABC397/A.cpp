#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    double x = 0;
    std::cin >> x;
    if (x >= 38) {
        std::cout << "1\n";
    } else if (x >= 37.5) {
        std::cout << "2\n";
    } else {
        std::cout << "3\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
