#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, f = 0, k = 0;
    std::cin >> n >> f >> k;

    std::vector<int> v(n), cnt(101);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
        ++cnt[v[i]];
    }

    int target = v[f - 1], initial = cnt[target];
    std::ranges::sort(v, std::greater<>());

    for (int i = 0; i < k; i++) {
        --cnt[v[i]];
    }

    if (cnt[target] == initial) {
        std::cout << "NO\n";
    } else if (cnt[target] && cnt[target] != initial) {
        std::cout << "MAYBE\n";
    } else {
        std::cout << "YES\n";
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
