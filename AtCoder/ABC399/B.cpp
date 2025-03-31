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

    std::vector<int> idx(n);
    std::iota(idx.begin(), idx.end(), 0);
    std::ranges::sort(idx, [&](int lhs, int rhs) { return v[lhs] > v[rhs]; });

    std::vector<int> ans(n);
    int left = 0, rank = 1;
    while (left < n) {
        int right = left + 1;
        while (right < n && v[idx[right]] == v[idx[left]]) {
            ++right;
        }
        for (int i = left; i < right; i++) {
            ans[idx[i]] = rank;
        }
        rank += right - left;
        left = right;
    }

    for (auto elem : ans) {
        std::cout << elem << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
