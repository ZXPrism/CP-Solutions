class Solution {
public:
    int longestOnes(vector<int> &nums, int k) {
        int n = nums.size(), ans = 0, zero = 0;
        for (int left = 0, right = 0; right < n; right++) {
            zero += nums[right] ^ 1;
            while (left <= right && zero > k) {
                zero -= nums[left] ^ 1;
                ++left;
            }
            ans = std::max(ans, right - left + 1);
        }
        return ans;
    }
};
