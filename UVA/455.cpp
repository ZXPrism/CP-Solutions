#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve(bool last = false) {
    std::string s;
    std::cin >> s;

    int n = s.size();
    std::vector<u64> pre(n + 1), power(n + 1, 1);
    constexpr u64 BASE = 233;
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] * BASE + s[i] - 'a';
        power[i + 1] = power[i] * BASE;
    }

    auto H = [&](int left, int right) -> u64 {
        return pre[right + 1] - pre[left] * power[right - left + 1];
    };

    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            u64 prefix = H(0, i - 1);
            bool flag = true;
            for (int j = i; j < n; j += i) {
                if (prefix != H(j, j + i - 1)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                std::cout << i << (last ? "\n" : "\n\n");
                return;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    std::cin >> t;
    while (t--) {
        if (t == 0) {
            solve(true);
        } else {
            solve();
        }
    }

    return 0;
}
