#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

constexpr int N = 200'000;
std::vector<int> notPrime(N + 1);
std::vector<int> minp(N + 1);
std::vector<int> primes;

void euler_sieve() {
    notPrime[0] = 1;
    notPrime[1] = 1;

    for (int i = 2; i <= N; i++) {
        if (!notPrime[i]) {
            primes.push_back(i);
            minp[i] = i;
        }

        for (auto p : primes) {
            if (1LL * i * p > N) {
                break;
            }

            minp[i * p] = p;
            notPrime[i * p] = 1;

            if (i % p == 0) {
                break;
            }
        }
    }
}

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    i64 ans = 0, primeCnt = 0;
    std::vector<int> cnt(n + 1);
    std::map<int, std::vector<int>> semiprimes;
    for (auto elem : v) {
        if (!notPrime[elem]) {
            ++primeCnt;
        }
        ++cnt[elem];

        if (!notPrime[elem]) {
            ans += primeCnt - cnt[elem];
            ans += semiprimes[elem].size();
        } else {
            int a = minp[elem], b = elem / a;
            if (b == minp[b]) {
                if (a == b) {
                    ans += cnt[a] + cnt[elem];
                    semiprimes[a].push_back(elem);
                } else {
                    ans += cnt[a] + cnt[b] + cnt[elem];
                    semiprimes[a].push_back(elem);
                    semiprimes[b].push_back(elem);
                }
            }
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    euler_sieve();

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
