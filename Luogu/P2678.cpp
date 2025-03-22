#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int l = 0, n = 0, m = 0;
    std::cin >> l >> n >> m;

    std::vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        std::cin >> pos[i];
    }

    auto check = [&](int lb) -> bool {
        int prev = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (pos[i] - prev < lb) {
                ++cnt;
            } else {
                prev = pos[i];
            }
        }
        cnt += (l - prev < lb);
        return cnt <= m;
    };

    int left = 0, right = l + 1, mid = 0;
    while (left + 1 < right) {
        mid = (left + right) >> 1;
        (check(mid) ? left : right) = mid;
    }

    std::cout << left << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
