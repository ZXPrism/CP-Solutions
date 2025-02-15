#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0;
    std::cin >> n;

    std::string s;
    std::cin >> s;

    std::vector<i64> pre1(n + 1);
    std::vector<i64> pre0(n + 1);
    std::vector<int> pre_cnt(n + 1);
    for (int i = 0; i < n; i++) {
        pre1[i + 1] = pre1[i];
        pre0[i + 1] = pre0[i];
        pre_cnt[i + 1] = pre_cnt[i];

        if (s[i] == '1') {
            pre1[i + 1] += i;
            ++pre_cnt[i + 1];
        } else {
            pre0[i + 1] += i;
        }
    }

    int one = pre_cnt[n];
    i64 ans = 1LL * n * n;
    std::deque<int> window;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            window.push_back(i);
        }

        if (i >= one - 1) {
            int left = i - one + 1, right = i;

            int k = pre_cnt[left];
            i64 curr = 0;
            if (k) {
                curr += (pre0[window[k - 1] + 1] - pre0[left]) - (pre1[left]);
            }
            if (pre_cnt[n] - pre_cnt[right + 1]) {
                curr += (pre1[n] - pre1[right + 1]) - (pre0[right + 1] - pre0[window[k]]);
            }

            ans = std::min(ans, curr);

            if (s[left] == '0') {
                window.pop_front();
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
