#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    int cnt = 0;
    for (auto elem : v) {
        cnt += elem & 1;
    }

    if (cnt == 0 || cnt == n) {
        std::cout << *std::ranges::max_element(v) << '\n';
    } else {
        std::cout << std::reduce(v.begin(), v.end(), 0LL) - cnt + 1 << '\n';
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
