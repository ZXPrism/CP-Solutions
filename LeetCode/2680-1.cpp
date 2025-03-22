class Solution {
public:
    long long maximumOr(vector<int> &nums, int k) {
        int n = nums.size();
        long long ans = 0;

        std::vector<int> pre(n + 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] | nums[i];
        }

        int suf = 0;
        for (int i = n - 1; i >= 0; i--) {
            ans = std::max(ans, pre[i] | (1LL * nums[i] << k) | suf);
            suf |= nums[i];
        }

        return ans;
    }
};
