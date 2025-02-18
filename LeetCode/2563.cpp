class Solution {
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper) {
        long long ans = 0;
        int n = nums.size();
        std::ranges::sort(nums);
        for (int i = 0; i < n; i++) {
            auto l = std::lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
            auto r = std::upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
            ans += r - l;
        }
        return ans;
    }
};
