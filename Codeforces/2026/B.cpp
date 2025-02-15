#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<i64> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    if (n == 1) {
        std::cout << "1\n";
        return;
    }

    i64 ans = 0;
    if (n % 2 == 0) {
        for (int i = 0; i < n; i += 2) {
            ans = std::max(ans, v[i + 1] - v[i]);
        }
    } else {
        ans = std::numeric_limits<i64>::max();
        std::vector<i64> sufMax(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            if (i % 2 == 1) {
                sufMax[i] = std::max(sufMax[i + 2], v[i + 1] - v[i]);
            }
        }

        i64 preMax = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 1) {
                ans = std::min(ans, std::max(preMax, std::max(v[i + 1] - v[i - 1], sufMax[i + 2])));
                preMax = std::max(preMax, v[i] - v[i - 1]);
            } else {
                ans = std::min(ans, std::max(preMax, sufMax[i + 1]));
            }
        }
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
