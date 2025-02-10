#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

class DSU {
public:
    explicit DSU(size_t n) {
        _Parent = std::vector<int>(n + 1, -1);
    }

    void Unite(int x, int y) {
        x = Find(x);
        y = Find(y);
        if (x != y) {
            if (_Parent[x] > _Parent[y]) {
                _Parent[y] += _Parent[x];
                _Parent[x] = y;
            } else {
                _Parent[x] += _Parent[y];
                _Parent[y] = x;
            }
        }
    }

    int Find(int x) {
        return (_Parent[x] < 0 ? x : _Parent[x] = Find(_Parent[x]));
    }

    bool Same(int x, int y) {
        return Find(x) == Find(y);
    }

    int Size(int x) {
        return -_Parent[Find(x)];
    }

private:
    std::vector<int> _Parent;
};

void solve() {
    int n = 0, m = 0;
    std::cin >> n >> m;

    DSU dsu(n);
    std::vector<int> extra;
    std::vector<std::pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int u = 0, v = 0;
        std::cin >> u >> v;

        if (dsu.Same(u, v)) {
            extra.push_back(i);
        } else {
            dsu.Unite(u, v);
        }

        edges.push_back({u, v});
    }

    std::map<int, std::vector<int>> cc;
    for (int i = 1; i <= n; i++) {
        cc[dsu.Find(i)].push_back(i);
    }

    std::map<int, std::vector<int>> extra_cc;
    for (auto &edge : extra) {
        auto [u, v] = edges[edge];
        extra_cc[dsu.Find(u)].push_back(edge);
    }

    std::vector<int> reordered_cc;
    for (auto &[id, _] : extra_cc) {
        reordered_cc.push_back(id);
    }
    for (auto &[id, _] : cc) {
        if (!extra_cc.contains(id)) {
            reordered_cc.push_back(id);
        }
    }

    int ccSize = cc.size();
    std::cout << ccSize - 1 << '\n';

    for (int i = 0, j = 1; j < ccSize; i++) {
        for (auto edge : extra_cc[reordered_cc[i]]) {
            if (j < ccSize) {
                std::cout << edge + 1 << ' ' << edges[edge].first << ' '
                          << dsu.Find(reordered_cc[j]) << '\n';
                ++j;
            }
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}
