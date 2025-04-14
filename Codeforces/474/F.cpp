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

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    std::unordered_map<int, std::vector<int>, custom_hash> pos;
    for (int i = 0; i < n; i++) {
        pos[v[i]].push_back(i);
    }

    int hb = 31 - __builtin_clz(n);
    std::vector<std::vector<int>> st(hb + 1);
    st[0] = v;
    for (int i = 1; i <= hb; i++) {
        st[i] = std::vector<int>(n - (1 << i) + 1);
        for (int j = 0; j + (1 << i) <= n; j++) {
            st[i][j] = std::gcd(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
    }

    auto query = [&](int l, int r) -> int {
        int hb = 31 - __builtin_clz(r - l + 1);
        return std::gcd(st[hb][l], st[hb][r - (1 << hb) + 1]);
    };

    int q = 0;
    std::cin >> q;
    for (int i = 0; i < q; i++) {
        int l = 0, r = 0;
        std::cin >> l >> r;
        --l, --r;
        int x = query(l, r);
        std::cout << r - l + 1 -
                         (std::ranges::upper_bound(pos[x], r) - std::ranges::lower_bound(pos[x], l))
                  << '\n';
    }
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
