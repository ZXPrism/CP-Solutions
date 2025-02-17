#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> vn(n), vk(n);
    for (int i = 0; i < n; i++) {
        std::cin >> vn[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> vk[i];
    }

    constexpr i64 MOD = 1'000'000'007;
    auto F = [](int k) -> i64 {
        i64 ans = 1, x = 2;
        while (k) {
            if (k & 1) {
                ans = (ans * x) % MOD;
            }
            x = (x * x) % MOD;
            k >>= 1;
        }
        return ans;
    };

    for (int i = 0; i < n; i++) {
        std::cout << F(vk[i]) << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
