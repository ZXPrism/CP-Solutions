#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0;
    std::cin >> n >> m;

    std::vector<std::vector<i64>> values(n, std::vector<i64>(3));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            std::cin >> values[i][j];
        }
    }

    i64 ans = 0;
    for (int i = 0; i < 8; i++) {
        std::vector<i64> v(n);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 3; k++) {
                if (i >> k & 1) {
                    v[j] += values[j][k];
                } else {
                    v[j] -= values[j][k];
                }
            }
        }

        std::ranges::sort(v, std::greater<>());
        i64 curr = 0;
        for (int j = 0; j < m; j++) {
            curr += v[j];
        }
        ans = std::max(ans, curr);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
