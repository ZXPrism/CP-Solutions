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

    bool flag = false;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i];
        if (v[i] % 3 == 1) {
            flag = true;
        }
    }

    int r = sum % 3;
    if (r == 0) {
        std::cout << "0\n";
    } else if (r == 1) {
        std::cout << (flag ? "1\n" : "2\n");
    } else {
        std::cout << "1\n";
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
