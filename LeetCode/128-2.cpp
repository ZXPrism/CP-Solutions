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
    int Size(int x) {
        return -_Parent[Find(x)];
    }

private:
    std::vector<int> _Parent;
};

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        std::unordered_map<int, int> map;
        int unique = 0;
        for (auto elem : nums) {
            if (!map.contains(elem)) {
                map[elem] = unique++;
            }
        }

        DSU dsu(unique);
        for (auto [val, id] : map) {
            if (map.contains(val - 1)) {
                dsu.Unite(map[val - 1], id);
            }
        }

        int ans = 0;
        for (int i = 0; i < unique; i++) {
            ans = std::max(ans, dsu.Size(i));
        }

        return ans;
    }
};
