#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;
    std::vector<std::string> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    std::ranges::sort(v, [&](auto &lhs, auto &rhs) { return lhs.size() < rhs.size(); });
    for (int i = 0; i < n; i++) {
        std::cout << v[i];
    }
    std::cout << '\n';
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
