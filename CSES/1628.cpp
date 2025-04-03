#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, x = 0;
    std::cin >> n >> x;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    i64 sum = 0;
    std::vector<i64> left_sum;
    auto dfs_left = [&](auto &&self, int k) -> void {
        if (k == n / 2) {
            left_sum.push_back(sum);
            return;
        }
        sum += v[k];
        self(self, k + 1);
        sum -= v[k];
        self(self, k + 1);
    };
    dfs_left(dfs_left, 0);

    sum = 0;
    std::vector<i64> right_sum;
    auto dfs_right = [&](auto &&self, int k) -> void {
        if (k == n) {
            right_sum.push_back(sum);
            return;
        }
        sum += v[k];
        self(self, k + 1);
        sum -= v[k];
        self(self, k + 1);
    };
    dfs_right(dfs_right, n / 2);

    std::ranges::sort(left_sum);
    std::ranges::sort(right_sum);

    i64 ans = 0;
    int left = 0, right = right_sum.size() - 1;
    while (left < left_sum.size() && right >= 0) {
        i64 sum = left_sum[left] + right_sum[right];
        if (sum > x) {
            --right;
        } else if (sum < x) {
            ++left;
        } else {
            int l = left;
            while (left < left_sum.size() && left_sum[left] == left_sum[l]) {
                ++left;
            }
            int r = right;
            while (right < right_sum.size() && right_sum[right] == right_sum[r]) {
                --right;
            }
            ans += 1LL * (left - l) * (r - right);
        }
    }

    std::cout << ans << '\n';
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
