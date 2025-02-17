class Solution {
public:
    int maxFrequencyScore(vector<int> &nums, int k) {
        int n = nums.size();
        constexpr long long MOD = 1000'000'007;

        auto FastPow = [](long long x, int y) {
            long long res = 1;
            while (y) {
                if (y & 1) {
                    res = (res * x) % MOD;
                }
                x = (x * x) % MOD;
                y >>= 1;
            }
            return res;
        };

        long long ans = 0, curr = 0;
        std::vector<int> cnt(*std::ranges::max_element(nums) + 1);
        for (int i = 0; i < n; i++) {
            if (cnt[nums[i]]) {
                curr = (curr - FastPow(nums[i], cnt[nums[i]]) + MOD) % MOD;
            }
            ++cnt[nums[i]];
            curr = (curr + FastPow(nums[i], cnt[nums[i]])) % MOD;

            if (i >= k - 1) {
                ans = std::max(ans, curr);
                curr = (curr - FastPow(nums[i - k + 1], cnt[nums[i - k + 1]]) + MOD) % MOD;
                --cnt[nums[i - k + 1]];
                if (cnt[nums[i - k + 1]]) {
                    curr = (curr + FastPow(nums[i - k + 1], cnt[nums[i - k + 1]])) % MOD;
                }
            }
        }

        return ans;
    }
};
