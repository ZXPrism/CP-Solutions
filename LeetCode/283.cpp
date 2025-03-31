class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int k = 0;
        for (auto &elem : nums) {
            if (elem) {
                std::swap(nums[k], elem);
                ++k;
            }
        }
    }
};
