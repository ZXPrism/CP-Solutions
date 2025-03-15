#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, r = 0;
    std::cin >> n >> r;

    std::vector<int> res(r);

    auto dfs = [&](auto &&self, int curr, int remain) -> void {
        if (remain == 0) {
            for (auto elem : res) {
                std::cout << std::setw(3) << elem;
            }
            std::cout << '\n';
            return;
        }

        if (curr > n) {
            return;
        }

        res[r - remain] = curr;
        self(self, curr + 1, remain - 1);
        self(self, curr + 1, remain);
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
