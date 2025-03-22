#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0;
    std::cin >> n >> m;

    std::vector<int> v(m);
    for (int i = 0; i < m; i++) {
        std::cin >> v[i];
    }
    std::ranges::sort(v);

    std::vector<i64> pre(m + 1);
    std::vector<int> sub(m + 1);
    for (int i = 0; i < m; i++) {
        sub[i] = n - std::min(n - 1, v[i]);
        pre[i + 1] = pre[i] + sub[i];
    }

    i64 ans = 0;
    for (int i = 0; i < m; i++) {
        int a = std::min(n - 1, v[i]);
        int left = -1, right = i, mid = 0;
        while (left + 1 < right) {
            mid = (left + right) >> 1;
            if (sub[mid] <= a + 1) {
                right = mid;
            } else {
                left = mid;
            }
        }
        int b = right;

        ans += 2 * (1LL * (a + 1) * (i - b) - (pre[i] - pre[b]));
    }

    std::cout << ans << '\n';
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
