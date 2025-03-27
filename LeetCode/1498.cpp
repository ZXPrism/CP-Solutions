class Solution {
public:
    int numSubseq(vector<int> &nums, int target) {
        constexpr int MOD = 1'000'000'007;
        auto p2 = [](int y) -> int {
            int res = 1, curr = 2;
            while (y) {
                if (y & 1) {
                    res = (1LL * res * curr) % MOD;
                }
                curr = (1LL * curr * curr) % MOD;
                y >>= 1;
            }
            return res;
        };
        std::ranges::sort(nums);
        int n = nums.size(), ans = 0;
        int left = 0, right = n - 1;
        while (left < right) {
            if (nums[left] + nums[right] <= target) {
                ans = (ans + p2(right - left)) % MOD;
                ++left;
            } else {
                --right;
            }
        }
        if (left == right && 2 * nums[left] <= target) {
            ans = (ans + 1) % MOD;
        }
        return ans;
    }
};
