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

    std::vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + v[i];
    }

    int ans = std::numeric_limits<int>::min();

    std::deque<int> qmi;
    qmi.push_back(0);
    for (int i = 1; i <= n; i++) {
        while (qmi.front() < i - m) {
            qmi.pop_front();
        }

        ans = std::max(ans, pre[i] - pre[qmi.front()]);
        while (!qmi.empty() && pre[qmi.back()] >= pre[i]) {
            qmi.pop_back();
        }
        qmi.push_back(i);
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
