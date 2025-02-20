#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int a = 0, b = 0;
    std::cin >> a >> b;
    if (a <= 8 && b <= 8) {
        std::cout << "Yay!\n";
    } else {
        std::cout << ":(\n";
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
