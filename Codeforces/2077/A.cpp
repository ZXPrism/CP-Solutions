#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> v(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        std::cin >> v[i];
    }

    std::ranges::sort(v, std::greater<>());

    std::vector<i64> ans(2 * n + 1);

    int k = 0;
    for (int i = 0; i < 2 * n + 1; i += 2) {
        ans[i] = v[k++];
        ans[2 * n - 1] += ans[i];
    }

    for (int i = 1; i < 2 * n - 1; i += 2) {
        ans[i] = v[k++];
        ans[2 * n - 1] -= ans[i];
    }

    for (int i = 0; i < 2 * n + 1; i++) {
        std::cout << ans[i] << " \n"[i == 2 * n];
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
