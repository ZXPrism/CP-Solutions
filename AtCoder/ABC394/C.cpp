#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;

    int n = s.size();

    std::vector<int> bad;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == 'W' && s[i] == 'A') {
            bad.push_back(i - 1);
        }
    }

    for (auto elem : bad) {
        s[elem + 1] = 'C';
        while (elem >= 0 && s[elem] == 'W') {
            s[elem] = 'C';
            --elem;
        }
        s[elem + 1] = 'A';
    }

    std::cout << s << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
