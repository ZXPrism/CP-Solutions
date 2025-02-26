#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

template <size_t MOD>
class ModInt {
public:
    ModInt(unsigned val) : _Data(val) {
    }

    friend ModInt operator+(ModInt lhs, ModInt rhs) {
        return (lhs._Data + rhs._Data) % MOD;
    }

    friend ModInt operator-(ModInt lhs, ModInt rhs) {
        return (lhs._Data - rhs._Data + MOD) % MOD;
    }

    friend ModInt operator*(ModInt lhs, ModInt rhs) {
        return (1LL * lhs._Data * rhs._Data) % MOD;
    }

    friend ModInt Pow(ModInt lhs, ModInt rhs) {
        auto x = lhs._Data, y = rhs._Data;
        unsigned res = 1;
        while (y) {
            if (y & 1) {
                res = (1LL * res * x) % MOD;
            }
            x = (1LL * x * x) % MOD;
            y >>= 1;
        }
        return res;
    }

    unsigned Val() const {
        return _Data;
    }

private:
    unsigned _Data;
};

using X = ModInt<1'000'000'007>;
using Y = ModInt<998'244'353>;

void solve() {
    int a = 0, b = 0;
    std::cin >> a >> b;

    X ax = a, bx = b;
    std::cout << Pow(ax, bx).Val() << '\n';
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
