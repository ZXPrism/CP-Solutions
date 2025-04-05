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

    constexpr int MOD = 1'000'000'007;
    i64 sum = std::reduce(v.begin(), v.end(), 0LL);

    auto pow2 = [](int p) -> i64 {
        i64 res = 1, x = 2;
        while (p) {
            if (p & 1) {
                res = (res * x) % MOD;
            }
            p >>= 1;
            x = (x * x) % MOD;
        }
        return res;
    };

    std::cout << ((sum % MOD) * pow2(n - 1)) % MOD << '\n';
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
