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
