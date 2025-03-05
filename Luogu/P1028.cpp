#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + 1 + pre[i / 2];
    }

    std::cout << 1 + pre[n / 2] << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
