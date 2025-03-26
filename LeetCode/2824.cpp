class Solution {
public:
    int countPairs(vector<int> &nums, int target) {
        std::ranges::sort(nums);
        int left = 0, right = nums.size() - 1, ans = 0;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum < target) {
                ans += right - left;
                ++left;
            } else {
                --right;
            }
        }
        return ans;
    }
};
