class RangeFreqQuery {
public:
    std::vector<std::vector<int>> _Data;

    RangeFreqQuery(vector<int> &arr) {
        int n = arr.size();
        _Data.resize(10001);
        for (int i = 0; i < n; i++) {
            _Data[arr[i]].push_back(i);
        }
    }

    int query(int left, int right, int value) {
        int a =
            std::lower_bound(_Data[value].begin(), _Data[value].end(), left) - _Data[value].begin();
        int b = std::upper_bound(_Data[value].begin(), _Data[value].end(), right) -
                _Data[value].begin();
        return b - a;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
