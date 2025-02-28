#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int a = 0, b = 0;
    for (auto ch : s) {
        if (ch == '-') {
            ++a;
        } else {
            ++b;
        }
    }

    std::cout << 1LL * a / 2 * (a - a / 2) * b << '\n';
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
