class NumArray {
public:
    int _N;
    std::vector<int> _Data;

    NumArray(vector<int> &nums) {
        _N = nums.size();
        _Data.resize(_N + 1);
        for (int i = 1; i <= _N; i++) {
            _Data[i] += nums[i - 1];
            int j = i + (i & -i);
            if (j <= _N) {
                _Data[j] += _Data[i];
            }
        }
    }

    int query(int index) {
        int ans = 0;
        while (index) {
            ans += _Data[index];
            index -= index & -index;
        }
        return ans;
    }

    void update(int index, int val) {
        ++index;
        val -= (query(index) - query(index - 1));
        while (index <= _N) {
            _Data[index] += val;
            index += index & -index;
        }
    }

    int sumRange(int left, int right) {
        return query(right + 1) - query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
