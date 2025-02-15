#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<int> v;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            v.push_back(i);
        }
    }
    int nv = v.size();

    auto check = [&](int k) -> bool {
        for (int left = nv - k, right = 0; right < n; right++) {
            if (right == v[left]) {
                if (right - 2 * (left - (nv - k)) < 1) {
                    return false;
                }
                ++left;
            }
        }
        return true;
    };

    int left = -1, right = v.size() + 1, mid = 0;
    while (left + 1 < right) {
        mid = (left + right) / 2;
        if (check(mid)) {
            left = mid;
        } else {
            right = mid;
        }
    }

    i64 ans = 1LL * (1 + n) * n / 2;
    for (int i = nv - left; i < nv; i++) {
        ans -= (v[i] + 1);
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
