class Solution {
public:
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        int n = nums.size();
        int ans_le = 0, curr = 0;
        for (int left = 0, right = 0; right < n; right++) {
            curr += nums[right];
            while (curr > goal) {
                curr -= nums[left++];
            }
            ans_le += right - left + 1;
        }
        int ans_l = 0;
        curr = 0;
        for (int left = 0, right = 0; right < n; right++) {
            curr += nums[right];
            while (left <= right && curr >= goal) {
                curr -= nums[left++];
            }
            ans_l += right - left + 1;
        }
        return ans_le - ans_l;
    }
};
