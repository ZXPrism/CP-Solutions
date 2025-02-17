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
    int n = 0, m = 0;
    std::cin >> n >> m;

    std::vector<std::vector<int>> ma(n, std::vector<int>(m));
    std::unordered_map<int, int, custom_hash> eigen2row_a;
    std::vector<int> row2eigen_a(n);
    for (int i = 0; i < n; i++) {
        int eigen = n * m + 1;
        for (int j = 0; j < m; j++) {
            std::cin >> ma[i][j];
            eigen = std::min(eigen, ma[i][j]);
        }
        eigen2row_a[eigen] = i;
        row2eigen_a[i] = eigen;
    }

    std::vector<std::vector<int>> mb(n, std::vector<int>(m));
    std::unordered_map<int, int, custom_hash> eigen2row_b;
    std::vector<int> row2eigen_b(n);
    for (int i = 0; i < n; i++) {
        int eigen = n * m + 1;
        for (int j = 0; j < m; j++) {
            std::cin >> mb[i][j];
            eigen = std::min(eigen, mb[i][j]);
        }
        eigen2row_b[eigen] = i;
        row2eigen_b[i] = eigen;
    }

    for (int i = 0; i < n; i++) {
        if (eigen2row_a.contains(row2eigen_b[i])) {
            auto row_a = ma[eigen2row_a[row2eigen_b[i]]];
            auto row_b = mb[i];
            std::ranges::sort(row_a);
            std::ranges::sort(row_b);
            if (row_a != row_b) {
                std::cout << "NO\n";
                return;
            }
        } else {
            std::cout << "NO\n";
            return;
        }
    }

    auto S = [&](int col_a, int col_b) {
        for (int i = 0; i < n; i++) {
            std::swap(mb[i][col_a], mb[i][col_b]);
        }
    };

    int ref_row = eigen2row_a[row2eigen_b[0]];
    std::unordered_map<int, int, custom_hash> val2col;
    for (int i = 0; i < m; i++) {
        val2col[mb[0][i]] = i;
    }
    for (int i = 0; i < m; i++) {
        int target = ma[ref_row][i];
        if (target != mb[0][i]) {
            int t = mb[0][i];
            S(i, val2col[target]);
            std::swap(val2col[t], val2col[target]);
        }
    }

    for (int i = 0; i < n; i++) {
        if (ma[eigen2row_a[row2eigen_b[i]]] != mb[i]) {
            std::cout << "NO\n";
            return;
        }
    }

    std::cout << "YES\n";
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
