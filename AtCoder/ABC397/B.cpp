#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;

    int ans = 0, expect = 'i';
    for (auto ch : s) {
        if (ch != expect) {
            ++ans;
            if (ch == 'i') {
                expect = 'o';
            } else {
                expect = 'i';
            }
        } else if (expect == 'i') {
            expect = 'o';
        } else {
            expect = 'i';
        }
    }

    std::cout << ans + (expect == 'o') << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
