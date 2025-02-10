#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.size();
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == s[i]) {
            std::cout << "1\n";
            return;
        }
    }

    std::cout << n << '\n';
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
