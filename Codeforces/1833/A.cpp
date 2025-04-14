#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::unordered_set<std::string> hashset;
    for (int i = 0; i < n; i++) {
        if (i >= 1) {
            hashset.insert(s.substr(i - 1, 2));
        }
    }

    std::cout << hashset.size() << '\n';
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
