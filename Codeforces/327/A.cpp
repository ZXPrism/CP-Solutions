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

    int one = std::reduce(v.begin(), v.end());

    int mx = 0, ans = 0;
    for (int i = 0; i < n; i++) {
        int curr = (!v[i] ? 1 : -1);
        mx = std::max(mx + curr, curr);
        ans = std::max(ans, one + mx);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
