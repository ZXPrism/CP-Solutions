#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::string a, b;
    std::cin >> a >> b;

    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            c1 += (a[i] - '0') ^ 1;
            c2 += (b[i] - '0') ^ 1;
        } else {
            c2 += (a[i] - '0') ^ 1;
            c1 += (b[i] - '0') ^ 1;
        }
    }

    std::cout << (c1 >= (n + 1) / 2 && c2 >= n / 2 ? "YES\n" : "NO\n");
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
