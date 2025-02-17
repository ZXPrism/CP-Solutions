class Solution {
public:
    int minimumDifference(vector<int> &nums, int k) {
        int n = nums.size();
        std::ranges::sort(nums);
        int ans = nums.back() - nums.front();
        for (int i = 0; i < n; i++) {
            if (i >= k - 1) {
                ans = std::min(ans, nums[i] - nums[i - k + 1]);
            }
        }
        return ans;
    }
};
