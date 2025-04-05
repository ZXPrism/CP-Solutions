#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    i64 s = 0;
    std::cin >> n >> s;

    std::vector<int> price(n), need(n);
    for (int i = 0; i < n; i++) {
        std::cin >> price[i] >> need[i];
    }

    std::vector<int> idx(n);
    std::iota(idx.begin(), idx.end(), 0);
    std::ranges::sort(idx, [&](int lhs, int rhs) { return need[lhs] < need[rhs]; });

    i64 ans = 0;
    i64 tot = std::reduce(price.begin(), price.end(), 0LL);
    int left = 0, used = 0;
    while (left < n) {
        if (tot <= s) {
            for (int i = left; i < n; i++) {
                ans += 1LL * (need[idx[i]] - used) * price[idx[i]];
            }
            break;
        } else {
            ans += s * (need[idx[left]] - used);
            used = need[idx[left]];
            int right = left;
            while (right < n && need[idx[left]] == need[idx[right]]) {
                tot -= price[idx[right]];
                ++right;
            }
            left = right;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
