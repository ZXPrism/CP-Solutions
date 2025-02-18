class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size(), ans = n + 1, sum = 0;
        for (int left = 0, right = 0; right < n; right++) {
            sum += nums[right];
            while (left <= right && sum >= target) {
                ans = std::min(ans, right - left + 1);
                sum -= nums[left++];
            }
        }
        return (ans == n + 1 ? 0 : ans);
    }
};
