#include <bits/stdc++.h>

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
