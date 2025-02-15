#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.size(), ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'B') {
            for (int j = 1; i - j >= 0 && i + j < n; j++) {
                if (s[i - j] == 'A' && s[i + j] == 'C') {
                    ++ans;
                }
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
