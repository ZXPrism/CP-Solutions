class Solution {
public:
    int maximumBeauty(vector<int> &nums, int k) {
        int n = nums.size(), ans = 0;
        std::ranges::sort(nums);

        for (int left = 0, right = 0; right < n; right++) {
            while (left <= right && nums[right] - nums[left] > 2 * k) {
                ++left;
            }
            ans = std::max(ans, right - left + 1);
        }

        return ans;
    }
};
