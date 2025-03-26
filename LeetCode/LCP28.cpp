class Solution {
public:
    int purchasePlans(vector<int> &nums, int target) {
        constexpr int MOD = 1'000'000'007;
        std::ranges::sort(nums);
        int left = 0, right = nums.size() - 1;
        int ans = 0;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum <= target) {
                ans = (ans + right - left) % MOD;
                ++left;
            } else {
                --right;
            }
        }
        return ans;
    }
};
