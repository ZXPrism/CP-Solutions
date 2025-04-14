#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

// from Codeforces: @neal - https://codeforces.com/blog/entry/62393
struct custom_hash {
    static std::uint64_t splitmix64(std::uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(std::uint64_t x) const {
        static const std::uint64_t FIXED_RANDOM =
            std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

constexpr int V = 1E5;
std::vector<int> factors[V + 1];

void prep() {
    for (int i = 2; i <= V; i++) {
        for (int j = i; j <= V; j += i) {
            factors[j].push_back(i);
        }
    }
}

void solve() {
    int n = 0, q = 0;
    std::cin >> n >> q;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    std::unordered_map<int, std::vector<int>> pos;
    for (int i = 0; i < n; i++) {
        pos[v[i]].push_back(i);
    }

    for (int _ = 0; _ < q; _++) {
        int k = 0, l = 0, r = 0;
        std::cin >> k >> l >> r;
        --l, --r;

        std::vector<int> cand;
        auto Add = [&](int val) -> void {
            auto &vec = pos[val];
            auto x = std::ranges::lower_bound(vec, l) - vec.begin();
            if (x != vec.size() && vec[x] <= r) {
                cand.push_back(vec[x]);
            }
        };

        for (auto fac : factors[k]) {
            Add(fac);
        }

        std::ranges::sort(cand);

        i64 ans = 0;
        int prev = l;
        for (auto elem : cand) {
            if (k % v[elem] == 0) {
                ans += 1LL * (elem - prev) * k;
                while (k % v[elem] == 0) {
                    k /= v[elem];
                }
                prev = elem;
            }
        }
        ans += 1LL * (r + 1 - prev) * k;

        std::cout << ans << '\n';
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    prep();

    int t = 1;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
