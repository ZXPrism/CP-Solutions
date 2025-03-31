#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, k = 0;
    std::cin >> n >> k;

    std::map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int t = 0;
        std::cin >> t;
        ++cnt[t];
    }

    std::vector<int> segments;
    for (auto [_, elem] : cnt) {
        segments.push_back(elem);
    }

    std::ranges::sort(segments);

    int ans = segments.size();
    for (auto elem : segments) {
        if (k >= elem) {
            k -= elem;
            --ans;
        } else {
            break;
        }
    }

    std::cout << std::max(1, ans) << '\n';
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
