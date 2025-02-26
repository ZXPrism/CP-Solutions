class OrderedStream {
public:
    std::vector<std::string> _Data;
    int _Ptr = 1;

    OrderedStream(int n) {
        _Data.resize(n + 2);
    }

    vector<string> insert(int idKey, string value) {
        std::vector<std::string> res;
        _Data[idKey] = value;
        while (!_Data[_Ptr].empty()) {
            res.push_back(_Data[_Ptr]);
            ++_Ptr;
        }
        return res;
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */
