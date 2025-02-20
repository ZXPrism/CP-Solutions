#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n - 2; i++) {
        std::cin >> v[i];
    }

    int prev = -2;
    for (int left = 0; left < n;) {
        if (v[left] == 0) {
            ++left;
            continue;
        }
        int right = left + 1;
        while (right < n && v[left] == v[right]) {
            ++right;
        }
        if (left - 1 <= prev) {
            std::cout << "NO\n";
            return;
        }
        prev = right;
        left = right;
    }

    std::cout << "YES\n";
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
