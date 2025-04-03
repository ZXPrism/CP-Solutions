class Fenwick {
public:
    explicit Fenwick(size_t n) : _N(n) {
        _Data.resize(_N + 1);
    }
    void Add(int i, int x) {
        while (i <= _N) {
            _Data[i] += x;
            i += i & -i;
        }
    }
    int Query(int i) {
        int ans = 0;
        while (i) {
            ans += _Data[i];
            i -= i & -i;
        }
        return ans;
    }

private:
    int _N;
    std::vector<int> _Data;
};

class Solution {
public:
    vector<int> resultArray(vector<int> &nums) {
        int n = nums.size();

        std::vector<int> id(n);
        std::vector<int> tmp = nums;
        std::ranges::sort(tmp);
        tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());
        for (int i = 0; i < n; i++) {
            id[i] = (std::ranges::lower_bound(tmp, nums[i]) - tmp.begin()) + 1;
        }

        Fenwick fa(n), fb(n);
        std::vector<int> a(1, nums[0]);
        std::vector<int> b(1, nums[1]);
        fa.Add(id[0], 1);
        fb.Add(id[1], 1);
        for (int i = 2; i < n; i++) {
            int ga = fa.Query(n) - fa.Query(id[i]);
            int gb = fb.Query(n) - fb.Query(id[i]);
            if (ga > gb) {
                a.push_back(nums[i]);
                fa.Add(id[i], 1);
            } else if (ga < gb) {
                b.push_back(nums[i]);
                fb.Add(id[i], 1);
            } else {
                if (a.size() <= b.size()) {
                    a.push_back(nums[i]);
                    fa.Add(id[i], 1);
                } else if (a.size() > b.size()) {
                    b.push_back(nums[i]);
                    fb.Add(id[i], 1);
                }
            }
        }

        for (auto elem : b) {
            a.push_back(elem);
        }
        return a;
    }
};
