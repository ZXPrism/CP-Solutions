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

    int one = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] == 1) {
            ++one;
        }
    }

    if (one != 0 && one != n) {
        std::cout << "-1\n";
        return;
    }

    std::vector<std::pair<int, int>> ans;
    while (1) {
        int min_i = 0, max_i = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] < v[min_i]) {
                min_i = i;
            }
            if (v[i] > v[max_i]) {
                max_i = i;
            }
        }
        if (v[min_i] == v[max_i]) {
            break;
        }
        ans.push_back({max_i + 1, min_i + 1});
        v[max_i] = (v[max_i] + v[min_i] - 1) / v[min_i];
    }

    std::cout << ans.size() << '\n';
    for (auto [i, j] : ans) {
        std::cout << i << ' ' << j << '\n';
    }
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
