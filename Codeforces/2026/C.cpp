#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<int> x;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            x.push_back(i);
        }
    }

    std::sort(x.rbegin(), x.rend());

    auto check = [&](int k) -> bool {
        for (int i = 0; i < k; i++) {
            if (x[i] - 2 * (k - i - 1) <= 0) {
                return false;
            }
        }
        return true;
    };

    int left = -1, right = x.size() + 1, mid = 0;
    while (left + 1 < right) {
        mid = (left + right) / 2;
        if (check(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    i64 ans = 1LL * (1 + n) * n / 2;
    for (int i = 0; i < left; i++) {
        ans -= (x[i] + 1);
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
