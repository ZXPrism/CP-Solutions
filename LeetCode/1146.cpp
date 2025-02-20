class SnapshotArray {
public:
    int _SnapID = 0;
    std::vector<std::vector<std::pair<int, int>>> _Data;

    SnapshotArray(int length) {
        _Data.resize(length);
    }

    void set(int index, int val) {
        if (_Data[index].empty() || _Data[index].back().first != _SnapID) {
            _Data[index].push_back({_SnapID, val});
        } else {
            _Data[index].back().second = val;
        }
    }

    int snap() {
        return _SnapID++;
    }

    int get(int index, int snap_id) {
        auto &history = _Data[index];
        int left = -1, right = history.size(), mid = 0;
        while (left + 1 < right) {
            mid = (left + right) / 2;
            if (history[mid].first <= snap_id) {
                left = mid;
            } else {
                right = mid;
            }
        }
        return (left == -1 ? 0 : history[left].second);
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
