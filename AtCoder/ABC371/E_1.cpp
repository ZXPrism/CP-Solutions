#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    std::vector<std::vector<int>> pos(n + 1);
    for (int i = 0; i < n; i++) {
        pos[v[i]].push_back(i);
    }

    auto SubarrayCnt = [](int len) -> i64 { return 1LL * (len + 1) * len / 2; };

    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
        int n_pos = pos[i].size();
        if (n_pos) {
            i64 curr = SubarrayCnt(n);
            curr -= SubarrayCnt(pos[i].front()) + SubarrayCnt(n - 1 - pos[i].back());
            for (int j = 1; j < n_pos; j++) {
                curr -= SubarrayCnt(pos[i][j] - pos[i][j - 1] - 1);
            }
            ans += curr;
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
