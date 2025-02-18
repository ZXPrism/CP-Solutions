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

    i64 pos = 0, neg = 0;
    std::vector<i64> cnt;
    std::vector<int> sign;
    for (int left = 0; left < n;) {
        i64 sum = v[left];
        int right = left + 1;
        while (right < n && ((v[left] > 0) ^ (v[right] < 0))) {
            sum += v[right++];
        }
        cnt.push_back(std::abs(sum));
        sign.push_back(v[left] > 0);
        if (!sign.back()) {
            neg += cnt.back();
        }
        left = right;
    }

    int n_cnt = cnt.size();
    i64 ans = 0;
    for (int i = 0; i < n_cnt; i++) {
        if (sign[i]) {
            pos += cnt[i];
            ans = std::max(ans, pos + neg);
        } else {
            ans = std::max(ans, pos + neg);
            neg -= cnt[i];
        }
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
