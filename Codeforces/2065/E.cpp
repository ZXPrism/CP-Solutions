#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0, k = 0;
    std::cin >> n >> m >> k;

    if (std::abs(n - m) > k || (n < k && m < k)) {
        std::cout << "-1\n";
        return;
    }

    int next = 1;
    std::string ans;
    if (n >= m) {
        next = 0;
    }

    while (n || m) {
        if (!next) {
            for (int i = 0; i < std::min(n, k); i++) {
                ans.push_back('0');
            }
            n -= std::min(n, k);
        } else {
            for (int i = 0; i < std::min(m, k); i++) {
                ans.push_back('1');
            }
            m -= std::min(m, k);
        }
        next = 1 - next;
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
