#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

constexpr int N = 1'000'000;
std::vector<int> min_pfac(N + 1);
std::vector<int> primes;

void euler_sieve() {
    for (int i = 2; i <= N; i++) {
        min_pfac[i] = i;
    }
    for (int i = 2; i <= N; i++) {
        if (min_pfac[i] == i) {
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > N) {
                break;
            }
            min_pfac[i * p] = p;
            if (i % p == 0) {
                break;
            }
        }
    }
}

void solve() {
    i64 x = 0;
    std::cin >> x;

    auto fpow = [](i64 x, int y) -> i64 {
        i64 res = 1;
        while (y) {
            if (y & 1) {
                res *= x;
            }
            x *= x;
            y >>= 1;
        }
        return res;
    };

    i64 n = primes.size(), ans = 0;
    i64 up = static_cast<i64>(std::sqrt(x));
    int left = 0, right = n - 1;
    while (left < right) {
        if (1LL * primes[left] * primes[right] <= up) {
            ans += right - left;
            ++left;
        } else {
            --right;
        }
    }

    for (int i = 0; i < n; i++) {
        if (fpow(primes[i], 8) > x) {
            ans += i;
            break;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    euler_sieve();
    solve();

    return 0;
}
