class Solution {
public:
    vector<int> searchRange(vector<int> &nums, int target) {
        int n = nums.size();
        int l = std::ranges::lower_bound(nums, target) - nums.begin();
        int r = std::ranges::upper_bound(nums, target) - nums.begin();
        if (l != n && l != r) {
            return {l, r - 1};
        } else {
            return {-1, -1};
        }
    }
};
