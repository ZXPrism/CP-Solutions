#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, k = 0;
    std::cin >> n >> k;

    std::vector<int> pre(n + 2);
    std::iota(pre.begin(), pre.begin() + std::min(n + 2, k + 1), 0);

    constexpr int MOD = 1'000'000'000;
    for (int i = k; i <= n; i++) {
        pre[i + 1] = (1LL * pre[i] + pre[i] - pre[i - k] + MOD) % MOD;
    }

    std::cout << (pre[n + 1] - pre[n] + MOD) % MOD << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
