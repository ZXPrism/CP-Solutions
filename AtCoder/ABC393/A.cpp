#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    std::string s1, s2;
    std::cin >> s1 >> s2;

    if (s1 == "sick") {
        if (s2 == "sick") {
            std::cout << "1\n";
        } else {
            std::cout << "2\n";
        }
    } else {
        if (s2 == "sick") {
            std::cout << "3\n";
        } else {
            std::cout << "4\n";
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
