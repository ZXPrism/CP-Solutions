class Solution {
public:
    int maximumCount(vector<int> &nums) {
        int pos = std::ranges::upper_bound(nums, 0) - nums.begin();
        int neg = std::ranges::lower_bound(nums, 0) - nums.begin();
        int cnt_pos = nums.size() - pos, cnt_neg = neg;
        return std::max(cnt_pos, cnt_neg);
    }
};
