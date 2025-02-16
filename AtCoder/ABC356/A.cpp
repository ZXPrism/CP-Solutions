#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, l = 0, r = 0;
    std::cin >> n >> l >> r;

    std::vector<int> v(n);
    std::iota(v.begin(), v.end(), 1);

    std::reverse(v.begin() + l - 1, v.begin() + r);

    for (auto elem : v) {
        std::cout << elem << ' ';
    }
    std::cout << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
