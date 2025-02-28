#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, x = 0;
    std::cin >> n >> x;

    std::vector<int> ans(n);
    for (int i = 0; i < n; i++) {
        if ((x & i) == i) {
            ans[i] = i;
        } else {
            for (int j = i; j < n - 1; j++) {
                ans[j] = 0;
            }
            ans[n - 1] = x;
            break;
        }
    }

    int check = 0;
    for (int i = 0; i < n; i++) {
        check |= ans[i];
    }
    if (check != x) {
        ans[n - 1] = x;
    }

    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << ' ';
    }
    std::cout << '\n';
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
