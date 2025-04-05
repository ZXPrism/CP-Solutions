#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.size();
    if (n == 1) {
        std::cout << "-1\n";
    } else {
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                std::cout << s[i] << s[i] << '\n';
                return;
            }
        }
        for (int i = 0; i < n - 2; i++) {
            if (s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i] != s[i + 2]) {
                std::cout << s.substr(i, 3) << '\n';
                return;
            }
        }
        std::cout << "-1\n";
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
