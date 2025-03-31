#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

template <typename T>
class Fenwick {
public:
    explicit Fenwick(size_t n) : _N(n) {
        _Data.resize(n + 1);
    }

    template <typename TData>
    explicit Fenwick(const std::vector<TData> &data) : _N(data.size()) {
        _Data.resize(_N + 1);
        for (int i = 1; i <= _N; i++) {
            _Data[i] += data[i - 1];
            int fa = i + (i & -i);
            if (fa <= _N) {
                _Data[fa] += _Data[i];
            }
        }
    }

    void Add(int x, T k) {
        while (x <= _N) {
            _Data[x] += k;
            x += x & -x;
        }
    }

    T Query(int x) const {
        T ans{};
        while (x) {
            ans += _Data[x];
            x -= x & -x;
        }
        return ans;
    }

private:
    int _N = 0;
    std::vector<T> _Data;
};

void solve() {
    int n = 0, q = 0;
    std::cin >> n >> q;
    std::vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        std::cin >> nums[i];
    }

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int u = 0, v = 0;
        std::cin >> u >> v;
        --u, --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timestamp = 0;
    std::vector<int> in(n), out(n);
    auto dfs = [&](auto &&self, int node, int fa) -> void {
        in[node] = ++timestamp;
        for (auto neighbor : adj[node]) {
            if (neighbor != fa) {
                self(self, neighbor, node);
            }
        }
        out[node] = timestamp;
    };
    dfs(dfs, 0, -1);

    Fenwick<i64> fenwick(n);
    for (int i = 0; i < n; i++) {
        fenwick.Add(in[i], nums[i]);
    }

    int type = 0, s = 0, x = 0;
    for (int i = 0; i < q; i++) {
        std::cin >> type;
        if (type == 1) {
            std::cin >> s >> x;
            auto val = fenwick.Query(in[s - 1]) - fenwick.Query(in[s - 1] - 1);
            fenwick.Add(in[s - 1], x - val);
        } else {
            std::cin >> s;
            int left = in[s - 1], right = out[s - 1];
            std::cout << fenwick.Query(right) - fenwick.Query(left - 1) << '\n';
        }
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
