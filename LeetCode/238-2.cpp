class Solution {
public:
    vector<int> productExceptSelf(vector<int> &nums) {
        int n = nums.size();
        std::vector<int> ans(n, 1);
        for (int i = n - 2; i >= 0; i--) {
            ans[i] = ans[i + 1] * nums[i + 1];
        }
        int pre = 1;
        for (int i = 0; i < n; i++) {
            ans[i] *= pre;
            pre *= nums[i];
        }
        return ans;
    }
};
