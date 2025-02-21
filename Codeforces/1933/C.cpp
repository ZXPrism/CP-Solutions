#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int a = 0, b = 0, l = 0;
    std::cin >> a >> b >> l;

    std::set<int> s;
    int a0 = 1;
    for (int x = 0; x < 20 && a0 <= l; x++) {
        int b0 = 1;
        for (int y = 0; y < 20 && b0 <= l; y++) {
            i64 t = 1LL * a0 * b0;
            if (l % t == 0) {
                s.insert(l / t);
            }
            b0 *= b;
        }
        a0 *= a;
    }

    std::cout << s.size() << '\n';
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
