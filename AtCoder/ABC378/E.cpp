#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0;
    std::cin >> n >> m;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    i64 ans = 0;

    std::vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = (pre[i] + v[i]) % m;
    }

    i64 pre2 = 0;
    for (int i = 0; i < n; i++) {
        ans += 1LL * (i + 1) * pre[i + 1] - pre2;
        pre2 += pre[i + 1];
    }

    i64 inv_cnt = 0;

    std::vector<int> temp(n + 1);
    auto Merge = [&](int left, int right) {
        int mid = (left + right) >> 1;
        int i = left, j = mid + 1, k = 0;
        while (i <= mid && j <= right) {
            if (pre[i] <= pre[j]) {
                temp[k++] = pre[i++];
            } else {
                inv_cnt += mid - i + 1;
                temp[k++] = pre[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = pre[i++];
        }
        while (j <= right) {
            temp[k++] = pre[j++];
        }
        std::copy(temp.begin(), temp.begin() + k, pre.begin() + left);
    };

    auto MergeSort = [&](auto &&self, int left, int right) -> void {
        if (left < right) {
            int mid = (left + right) >> 1;
            self(self, left, mid);
            self(self, mid + 1, right);
            Merge(left, right);
        }
    };

    MergeSort(MergeSort, 0, n);

    std::cout << ans + inv_cnt * m << '\n';
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
