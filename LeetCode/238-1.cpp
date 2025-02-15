class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();

        std::vector<int> cnt(61);
        for (auto elem : nums) {
            ++cnt[elem + 30];
        }

        auto FastPow = [](long long x, long long y) -> long long {
            long long res = 1;
            while (y) {
                if (y & 1) {
                    res *= x;
                }
                x *= x;
                y >>= 1;
            }
            return res;
        };

        std::vector<int> pre(62, 1);
        for (int i = 0; i < 61; i++) {
            pre[i + 1] = pre[i] * FastPow(i - 30, cnt[i]);
        }
        std::vector<int> suf(63, 1);
        for (int i = 60; i >= 0; i--) {
            suf[i + 1] = suf[i + 2] * FastPow(i - 30, cnt[i]);
        }

        std::vector<int> ans(n, 1);
        for (int i = 0; i < n; i++) {
            ans[i] =
                pre[nums[i] + 30] * suf[nums[i] + 32] * FastPow(nums[i], cnt[nums[i] + 30] - 1);
        }

        return ans;
    }
};
