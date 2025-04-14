#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    std::string s1, s2, s3;
    std::cin >> s1 >> s2 >> s3;
    std::cout << s1[0] << s2[0] << s3[0] << '\n';
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
