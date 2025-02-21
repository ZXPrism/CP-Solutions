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
    std::vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + v[i];
    }

    auto F = [&](int left, int x, int u) -> i64 {
        int tot = pre[x] - pre[left - 1];
        return 1LL * tot * u - 1LL * (tot - 1) * tot / 2;
    };

    int q = 0;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int l = 0, u = 0;
        std::cin >> l >> u;
        int left = l - 1, right = n + 1, mid = 0;
        while (left + 1 < right) {
            mid = (left + right) >> 1;
            if (pre[mid] - pre[l - 1] <= u) {
                left = mid;
            } else {
                right = mid;
            }
        }
        if (left == n) {
            std::cout << n << ' ';
        } else if (left == l - 1) {
            std::cout << l << ' ';
        } else if (F(l, left, u) >= F(l, left + 1, u)) {
            std::cout << left << ' ';
        } else {
            std::cout << left + 1 << ' ';
        }
    }

    std::cout << '\n';
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
