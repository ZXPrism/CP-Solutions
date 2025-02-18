class Solution {
public:
    int searchInsert(vector<int> &nums, int target) {
        return std::ranges::lower_bound(nums, target) - nums.begin();
    }
};
