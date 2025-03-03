#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    auto check = [](i64 x) -> bool {
        i64 sqr = static_cast<i64>(std::sqrt(x));
        return sqr * sqr == x;
    };

    if (check(1LL * n * (n + 1) / 2)) {
        std::cout << "-1\n";
        return;
    }

    std::vector<int> ans(n + 1);
    std::iota(ans.begin(), ans.end(), 0);

    i64 sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += ans[i];
        if (check(sum)) {
            sum += -ans[i] + ans[i + 1];
            std::swap(ans[i], ans[i + 1]);
        }
    }

    for (int i = 1; i <= n; i++) {
        std::cout << ans[i] << " \n"[i == n];
    }
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
