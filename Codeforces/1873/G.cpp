#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;

    std::vector<std::pair<int, int>> segments;
    int i = 0, n = s.size();
    int a = 0;
    while (i < n) {
        int j = i + 1;
        while (j < n && s[i] == s[j]) {
            ++j;
        }

        if (s[i] == 'A') {
            segments.push_back({j - i, 1});
            ++a;
        } else {
            segments.push_back({j - i, 2});
        }
        i = j;
    }

    int n_segments = segments.size(), b = n_segments - a;
    if (n_segments == 1) {
        std::cout << "0\n";
        return;
    }

    bool ok = false;
    int ans = 0, min_len = n;
    for (auto [len, type] : segments) {
        if (type == 1) {
            ans += len;
            min_len = std::min(min_len, len);
        } else {
            if (len >= 2) {
                ok = true;
            }
        }
    }

    if (a > b && !ok) {
        ans -= min_len;
    }

    std::cout << ans << '\n';
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
