class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        std::vector<int> pre(n + 1, 1);
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] * nums[i];
        }

        int suf = 1;
        std::vector<int> ans(n);
        for (int i = n - 1; i >= 0; i--) {
            ans[i] = pre[i] * suf;
            suf *= nums[i];
        }

        return ans;
    }
};
