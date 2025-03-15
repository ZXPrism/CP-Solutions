#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0;
    std::cin >> n >> m;

    std::vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        std::cin >> pos[i];
    }

    std::vector<int> radius(n);
    for (int i = 0; i < n; i++) {
        std::cin >> radius[i];
    }

    i64 ans = 0;

    std::map<int, i64> cnt;
    for (int i = 0; i < n; i++) {
        int lb = pos[i] - radius[i], rb = pos[i] + radius[i];
        for (int j = lb; j <= rb; j++) {
            int left = 0, right = radius[i] + 1, mid = 0;
            while (left + 1 < right) {
                mid = (left + right) >> 1;
                if (1LL * (j - pos[i]) * (j - pos[i]) + 1LL * mid * mid <=
                    1LL * radius[i] * radius[i]) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            cnt[j] = std::max(cnt[j], 1LL * left);
        }
    }

    for (auto &[x, num] : cnt) {
        ans += num * 2;
    }
    ans += cnt.size();

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
