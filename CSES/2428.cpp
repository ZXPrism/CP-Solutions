#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, k = 0;
    std::cin >> n >> k;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    i64 ans = 0;
    std::vector<int> dp(n + 2);

    auto Add = [&](int i, int x) -> void {
        while (i <= n) {
            dp[i] += x;
            i += i & -i;
        }
    };

    auto Get = [&](int i) -> int {
        int res = 0;
        while (i) {
            res += dp[i];
            i -= i & -i;
        }
        return res;
    };

    std::vector<int> tmp = v;
    std::ranges::sort(tmp);
    tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());
    std::vector<int> id(n);
    for (int i = 0; i < n; i++) {
        id[i] = std::ranges::lower_bound(tmp, v[i]) - tmp.begin();
    }

    std::vector<int> last(n, -1);
    for (int i = 0; i < n; i++) {
        Add(last[id[i]] + 2, 1);
        Add(i + 2, -1);

        int left = -1, right = i + 1, mid = 0;
        while (left + 1 < right) {
            mid = (left + right) >> 1;
            if (Get(mid + 1) <= k) {
                right = mid;
            } else {
                left = mid;
            }
        }
        ans += i + 1 - right;

        last[id[i]] = i;
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
