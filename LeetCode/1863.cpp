class Solution {
public:
    int subsetXORSum(vector<int> &nums) {
        int n = nums.size();
        int or_all = 0;
        for (auto elem : nums) {
            or_all |= elem;
        }
        return or_all << (n - 1);
    }
};
