#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

template <typename T>
class Fenwick {
public:
    explicit Fenwick(int n) : _N(n) {
        _N = n;
        _Data.resize(n + 1);
    }

    explicit Fenwick(const std::vector<T> &v) {
        _N = v.size();
        _Data.resize(_N + 1);
        for (int i = 1, j = 0; i <= _N; i++) {
            _Data[i] += v[i - 1];
            j = i + _Lowbit(i);
            if (j <= _N)
                _Data[j] += _Data[i];
        }
    }

    T QuerySum(int x) {
        T ans{};
        while (x) {
            ans += _Data[x];
            x -= _Lowbit(x);
        }
        return ans;
    }

    T QueryRange(int l, int r) {
        return QuerySum(r) - QuerySum(l - 1);
    }

    void Add(int x, T k) {
        while (x <= _N) {
            _Data[x] += k;
            x += _Lowbit(x);
        }
    }

private:
    inline int _Lowbit(int x) {
        return x & -x;
    }

private:
    int _N;
    std::vector<T> _Data;
};

void solve() {
    int n = 0;
    std::cin >> n;

    std::vector<int> v(n);
    for (int i = 0; i < n; i++) {
        std::cin >> v[i];
    }

    int ans_left = 0, ans_right = 0, ans = n;
    for (int len = 1; len <= n; len++) {
        Fenwick<int> bit(2003);
        for (int i = 0; i < n; i++) {
            bit.Add(v[i], 1);

            if (i >= len - 1) {
                auto &x = v[i - len + 1];
                int a = bit.QuerySum(x - 1), b = bit.QueryRange(x + 1, 2003);
                if (-a + b < ans) {
                    ans = -a + b;
                    ans_left = i - len + 2;
                    ans_right = i + 1;
                }

                bit.Add(x, -1);
            }
        }
    }

    std::cout << ans_left << ' ' << ans_right << '\n';
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
