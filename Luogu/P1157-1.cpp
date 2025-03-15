#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, r = 0;
    std::cin >> n >> r;

    std::vector<int> res(r);
    auto dfs = [&](auto &&self, int prev, int remain) -> void {
        if (remain == 0) {
            for (auto elem : res) {
                std::cout << std::setw(3) << elem;
            }
            std::cout << '\n';
            return;
        }
        for (int i = prev + 1; i <= n; i++) {
            res[r - remain] = i;
            self(self, i, remain - 1);
        }
    };

    dfs(dfs, 1, r);
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
