class Solution {
public:
    int numberOfSubarrays(vector<int> &nums, int k) {
        int n = nums.size(), ans = 0;
        int left_l = 0, left_le = 0;
        int cnt_l = 0, cnt_le = 0;
        for (int right = 0; right < n; right++) {
            cnt_l += nums[right] & 1;
            while (cnt_l >= k) {
                cnt_l -= nums[left_l++] & 1;
            }

            cnt_le += nums[right] & 1;
            while (cnt_le > k) {
                cnt_le -= nums[left_le++] & 1;
            }
            ans += left_l - left_le;
        }
        return ans;
    }
};
