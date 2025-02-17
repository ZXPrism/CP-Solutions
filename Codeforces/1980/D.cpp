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

    std::vector<int> seq(n - 1);
    for (int i = 0; i < n - 1; i++) {
        seq[i] = std::gcd(v[i], v[i + 1]);
    }

    int pmax = 0;
    for (int i = 0; i < n - 2; i++) {
        if (seq[i] <= seq[i + 1]) {
            pmax = i + 1;
        } else {
            break;
        }
    }

    int smax = n - 2;
    for (int i = n - 2; i >= 1; i--) {
        if (seq[i - 1] <= seq[i]) {
            smax = i - 1;
        } else {
            break;
        }
    }

    if (smax <= 1 || pmax >= n - 3) {
        std::cout << "YES\n";
    } else {
        for (int i = 1; i < n - 1; i++) {
            if (pmax >= i - 2 && smax <= i + 1) {
                int t = std::gcd(v[i - 1], v[i + 1]);
                if ((i == 1 || t >= seq[i - 2]) && (i == n - 2 || t <= seq[i + 1])) {
                    std::cout << "YES\n";
                    return;
                }
            }
        }
        std::cout << "NO\n";
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
