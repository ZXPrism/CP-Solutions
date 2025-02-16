class Solution {
public:
    long long maximumSubarraySum(vector<int> &nums, int k) {
        long long ans = 0, sum = 0;

        int n = nums.size();
        std::vector<int> cnt(*std::ranges::max_element(nums) + 1);
        int unique_cnt = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (++cnt[nums[i]] == 1) {
                ++unique_cnt;
            }
            if (i >= k - 1) {
                if (unique_cnt == k) {
                    ans = std::max(ans, sum);
                }
                if (--cnt[nums[i - k + 1]] == 0) {
                    --unique_cnt;
                }
                sum -= nums[i - k + 1];
            }
        }

        return ans;
    }
};
