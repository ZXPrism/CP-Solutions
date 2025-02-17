#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

class DSU {
public:
    explicit DSU(size_t n) {
        _Parent = std::vector<int>(n + 1, -1);
    }

    int Find(int x) {
        return (_Parent[x] < 0 ? x : _Parent[x] = Find(_Parent[x]));
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

    bool Same(int x, int y) {
        return Find(x) == Find(y);
    }

    int GetSize(int x) {
        return -_Parent[Find(x)];
    }

private:
    std::vector<int> _Parent;
};

void solve() {
    int n = 0, m = 0;
    std::cin >> n >> m;

    DSU dsu(n);
    for (int i = 0; i < m; i++) {
        int z = 0, x = 0, y = 0;
        std::cin >> z >> x >> y;
        if (z == 1) {
            dsu.Unite(x, y);
        } else {
            std::cout << (dsu.Same(x, y) ? "Y" : "N") << '\n';
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();

    return 0;
}
