class Solution {
public:
    int longestSubarray(vector<int> &nums) {
        int n = nums.size(), zero = 0, ans = 0;
        for (int left = 0, right = 0; right < n; right++) {
            zero += 1 - nums[right];
            while (left <= right && zero == 2) {
                zero -= 1 - nums[left++];
            }
            ans = std::max(ans, right - left);
        }
        return ans;
    }
};
