template <typename T>
class SegmentTree {
public:
    SegmentTree(size_t N) : _N(N) {
        _Data = std::vector<T>(_N << 2, 0);
        _Tag = std::vector<std::optional<T>>(_N << 2, std::nullopt);
    }

    void Assign(int left, int right, T value) {
        _Assign(left, right, value, 1, _N, 1);
    }

    T Query(int left, int right) {
        return _Query(left, right, 1, _N, 1);
    }

private:
    void _Assign(int left, int right, T value, int segLeft, int segRight, int id) {
        if (left <= segLeft && segRight <= right) {
            _Data[id] = value * (segRight - segLeft + 1);
            _Tag[id] = value;
            return;
        }

        _PushDown(segLeft, segRight, id);

        int mid = (segLeft + segRight) >> 1;
        if (left <= mid) {
            _Assign(left, right, value, segLeft, mid, id << 1);
        }
        if (right > mid) {
            _Assign(left, right, value, mid + 1, segRight, (id << 1) + 1);
        }

        _Data[id] = _Data[id << 1] + _Data[(id << 1) + 1];
    }

    T _Query(int left, int right, int segLeft, int segRight, int id) {
        if (left <= segLeft && segRight <= right) {
            return _Data[id];
        }

        _PushDown(segLeft, segRight, id);

        T ans = 0;
        int mid = (segLeft + segRight) >> 1;
        if (left <= mid) {
            ans += _Query(left, right, segLeft, mid, id << 1);
        }
        if (right > mid) {
            ans += _Query(left, right, mid + 1, segRight, (id << 1) + 1);
        }

        return ans;
    }

    void _PushDown(int segLeft, int segRight, int id) {
        if (_Tag[id].has_value()) {
            int mid = (segLeft + segRight) >> 1;
            _Data[id << 1] = _Tag[id].value() * (mid - segLeft + 1);
            _Data[(id << 1) + 1] = _Tag[id].value() * (segRight - mid);
            _Tag[id << 1] = _Tag[id];
            _Tag[(id << 1) + 1] = _Tag[id];
            _Tag[id].reset();
        }
    }

private:
    size_t _N;
    std::vector<T> _Data;
    std::vector<std::optional<T>> _Tag;
};

class Solution {
public:
    int sumSubarrayMins(vector<int> &arr) {
        int n = arr.size(), ans = 0;
        constexpr int MOD = 1'000'000'007;

        std::stack<int> s;

        SegmentTree<long long> seg_tree(n);
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            int last_less = (s.empty() ? -1 : s.top());
            s.push(i);
            seg_tree.Assign(last_less + 2, i + 1, arr[i]);
            ans = (ans + seg_tree.Query(1, i + 1)) % MOD;
        }

        return ans;
    }
};
