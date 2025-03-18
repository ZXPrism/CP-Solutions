class Solution {
public:
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        int n = nums.size(), ans = 0, curr_l = 0, curr_le = 0;
        for (int left_l = 0, left_le = 0, right = 0; right < n; right++) {
            curr_l += nums[right];
            while (left_l <= right && curr_l >= goal) {
                curr_l -= nums[left_l++];
            }
            curr_le += nums[right];
            while (curr_le > goal) {
                curr_le -= nums[left_le++];
            }
            ans += left_l - left_le;
        }
        return ans;
    }
};
