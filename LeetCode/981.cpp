class TimeMap {
public:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> _Data;

    TimeMap() {
    }

    void set(string key, string value, int timestamp) {
        _Data[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {
        if (!_Data.contains(key)) {
            return "";
        } else {
            auto &vec = _Data[key];
            int n = vec.size();
            int left = -1, right = n, mid = 0;
            while (left + 1 < right) {
                mid = (left + right) / 2;
                if (vec[mid].first <= timestamp) {
                    left = mid;
                } else {
                    right = mid;
                }
            }
            return (left == -1 ? "" : vec[left].second);
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
