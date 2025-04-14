#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    std::string p, s;
    std::cin >> p >> s;

    std::vector<std::pair<int, int>> segments;
    int np = p.size(), ns = s.size();

    int left = 0;
    while (left < np) {
        int right = left + 1;
        while (right < np && p[left] == p[right]) {
            ++right;
        }
        segments.push_back({p[left], right - left});
        left = right;
    }

    int match = 0, n_seg = segments.size();
    left = 0;
    while (left < ns) {
        int right = left + 1;
        while (right < ns && s[left] == s[right]) {
            ++right;
        };
        if (match < n_seg && s[left] == segments[match].first &&
            right - left >= segments[match].second && right - left <= 2 * segments[match].second) {
            ++match;
        } else {
            std::cout << "NO\n";
            return;
        }
        left = right;
    }

    std::cout << (match == n_seg ? "YES\n" : "NO\n");
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
