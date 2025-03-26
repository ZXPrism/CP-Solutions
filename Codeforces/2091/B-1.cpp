#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, x = 0;
    std::cin >> n >> x;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }
    std::ranges::sort(v, std::greater<>());

    int left = 0, ans = 0;
    while (left < n) {
        int right = left;
        while (right < n) {
            if (1LL * v[right] * (right - left + 1) >= x) {
                ++ans;
                break;
            }
            ++right;
        }
        left = right + 1;
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
