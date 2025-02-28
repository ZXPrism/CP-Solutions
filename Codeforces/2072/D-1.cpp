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

    int ans = n, left = -1, right = -1;
    for (int i = 0; i < n; i++) {
        int a = 0, b = 0;
        for (int j = i; j < n; j++) {
            if (v[j] > v[i]) {
                ++a;
            } else if (v[j] != v[i]) {
                ++b;
            }
            if (a - b < ans) {
                ans = a - b;
                left = i + 1;
                right = j + 1;
            }
        }
    }

    std::cout << left << ' ' << right << '\n';
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
