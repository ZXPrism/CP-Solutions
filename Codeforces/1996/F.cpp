#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, k = 0;
    std::cin >> n >> k;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    auto check = [&](int val) -> bool {
        i64 tot = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= val) {
                tot += (a[i] - val) / b[i] + 1;
            }
        }
        return tot >= k;
    };

    int left = 0, right = 1'000'000'001, mid = 0;
    while (left + 1 < right) {
        mid = left + (right - left) / 2;
        if (check(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    i64 ans = 0, least = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] >= left) {
            int cnt = (a[i] - left + b[i] - 1) / b[i];
            ans += (1LL * cnt * a[i] - 1LL * cnt * (cnt - 1) / 2 * b[i]);
            least += cnt;
        }
    }

    std::cout << ans + 1LL * (k - least) * left << '\n';
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
