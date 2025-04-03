class Solution {
public:
    long long maximumTripletValue(vector<int> &nums) {
        int n = nums.size();
        long long ans = 0;
        int pre_max = std::max(nums[0], nums[1]), left = nums[0] - nums[1];
        for (int i = 2; i < n; i++) {
            ans = std::max(ans, 1LL * left * nums[i]);
            left = std::max(left, pre_max - nums[i]);
            pre_max = std::max(pre_max, nums[i]);
        }
        return ans;
    }
};
