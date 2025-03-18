#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
    i64 n = 0;
    std::cin >> n;

    i64 sqrt_n = std::sqrt(n);
    for (i64 left = 1; left <= std::min(sqrt_n, 1'000'000LL); left++) {
        if (n % left == 0) {
            i64 right = n / left;
            i64 xy3 = right - left * left;
            if (xy3 > 0 && xy3 % 3 == 0) {
                i64 A = xy3 / 3, B = left;
                i64 L = 0, R = 1'000'000'001, M = 0;
                while (L + 1 < R) {
                    M = (L + R) >> 1;
                    if (M * M + B * M - A >= 0) {
                        R = M;
                    } else {
                        L = M;
                    }
                }
                if (R * R + B * R - A == 0) {
                    std::cout << R + B << ' ' << R << '\n';
                    return;
                }
            }
        }
    }

    std::cout << "-1\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
