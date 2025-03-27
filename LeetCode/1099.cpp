class Solution {
public:
    int twoSumLessThanK(vector<int> &nums, int k) {
        std::ranges::sort(nums);
        int ans = -1;
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int s = nums[left] + nums[right];
            if (s < k) {
                ans = std::max(ans, s);
                ++left;
            } else {
                --right;
            }
        }
        return ans;
    }
};
