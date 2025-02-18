#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    std::vector<int> cnt(n + 1);
    for (int i = 0; i < n; i++) {
        ++cnt[v[i]];
    }

    int ans = 0, l = -1, r = -1;
    for (int left = 0; left < n;) {
        if (cnt[v[left]] != 1) {
            ++left;
            continue;
        }
        int right = left + 1;
        while (right < n && cnt[v[right]] == 1) {
            ++right;
        }
        if (right - left > ans) {
            l = left;
            r = right - 1;
            ans = right - left;
        }
        left = right;
    }

    if (l != -1) {
        std::cout << l + 1 << ' ' << r + 1 << '\n';
    } else {
        std::cout << "0\n";
    }
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
