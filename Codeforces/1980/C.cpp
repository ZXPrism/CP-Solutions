#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> b[i];
    }

    int m = 0;
    std::cin >> m;

    int last = 0;
    std::map<int, int> cnt;
    for (int i = 0; i < m; i++) {
        std::cin >> last;
        ++cnt[last];
    }

    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            if (!cnt[b[i]]) {
                std::cout << "NO\n";
                return;
            }
            --cnt[b[i]];
        }
    }

    bool check = false;
    for (int i = 0; i < n; i++) {
        if (b[i] == last) {
            check = true;
        }
    }

    std::cout << (check ? "YES\n" : "NO\n");
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
