class Solution {
public:
    long long maxSum(vector<int> &nums, int m, int k) {
        long long ans = 0, sum = 0;
        int n = nums.size();

        int distinct_cnt = 0;
        std::unordered_map<int, int> cnt;

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            if (++cnt[nums[i]] == 1) {
                ++distinct_cnt;
            }
            if (i >= k - 1) {
                if (distinct_cnt >= m) {
                    ans = std::max(ans, sum);
                }
                if (--cnt[nums[i - k + 1]] == 0) {
                    --distinct_cnt;
                }
                sum -= nums[i - k + 1];
            }
        }

        return ans;
    }
};
