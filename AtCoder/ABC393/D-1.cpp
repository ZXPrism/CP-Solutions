#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<int> v;
    int one = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            v.push_back(one);
        } else {
            ++one;
        }
    }

    i64 ans = 0;
    for (auto elem : v) {
        ans += std::min(elem, one - elem);
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
