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

    std::map<int, std::vector<int>> m;
    for (int i = 0; i < n; i++) {
        m[v[i]].push_back(i);
    }

    int ans = n + 1;
    for (auto &[val, pos] : m) {
        int n_pos = pos.size();
        for (int i = 1; i < n_pos; i++) {
            ans = std::min(ans, pos[i] - pos[i - 1] + 1);
        }
    }

    std::cout << (ans == n + 1 ? -1 : ans) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
