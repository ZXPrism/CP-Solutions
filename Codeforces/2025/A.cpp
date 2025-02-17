#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    std::string s, t;
    std::cin >> s >> t;

    int ns = s.size(), nt = t.size(), maxLen = std::min(ns, nt);
    for (int i = 0; i < ns && i < nt; i++) {
        if (s[i] != t[i]) {
            maxLen = i;
            break;
        }
    }

    if (maxLen >= 2) {
        std::cout << 1 + ns + nt - maxLen << '\n';
    } else {
        std::cout << ns + nt << '\n';
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
