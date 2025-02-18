#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    int ans = 0;
    for (int left = 0; left < n;) {
        int right = left + 1;
        while (right < n && s[right] == s[left]) {
            ++right;
        }
        if (s[left] == '1') {
            ans += 2;
        }
        left = right;
    }

    if (s.back() == '1') {
        --ans;
    }

    std::cout << ans << '\n';
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
