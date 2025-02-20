#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int d = 0, n = 0;
    std::cin >> d >> n;

    int base = (d == 0 ? 1 : d == 1 ? 100 : 10000);
    std::cout << (n < 100 ? n : n + 1) * base << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
