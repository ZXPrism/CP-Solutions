#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, k = 0;
    std::cin >> n >> k;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    std::ranges::sort(v);

    std::vector<int> seg, val;
    for (int left = 0; left < n;) {
        int right = left + 1;
        while (right < n && v[right] == v[left]) {
            ++right;
        }
        seg.push_back(right - left);
        val.push_back(v[left]);
        left = right;
    }

    int ans = 0, nSeg = seg.size();
    std::vector<int> pre(nSeg + 1);
    for (int i = 0; i < nSeg; i++) {
        pre[i + 1] = pre[i] + seg[i];
    }

    auto GetAns = [&](int left, int right) -> int {
        int res = 0;
        for (int i = left; i <= right; i++) {
            res = std::max(res, pre[std::min(right + 1, i + k)] - pre[i]);
        }
        return res;
    };

    for (int left = 0; left < nSeg;) {
        int right = left + 1;
        while (right < nSeg && val[right] == val[right - 1] + 1) {
            ++right;
        }
        ans = std::max(ans, GetAns(left, right - 1));
        left = right;
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
