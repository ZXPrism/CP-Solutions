#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    int n = 0, m = 0, k = 0;
    std::cin >> n >> m >> k;

    std::string s;
    std::cin >> s;

    int zero = 0;
    std::vector<int> pos;
    for (int i = 0; i < n; i++) {
        zero += (s[i] - '0') ^ 1;
        if (i >= m - 1) {
            if (zero == m) {
                pos.push_back(i);
            }
            zero -= (s[i - m + 1] - '0') ^ 1;
        }
    }

    int ans = 0, left = -k;
    for (auto elem : pos) {
        if (left + k - 1 < elem - m + 1 || left > elem) {
            ++ans;
            left = elem;
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
