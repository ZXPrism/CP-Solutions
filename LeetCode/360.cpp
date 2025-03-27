class Solution {
public:
    vector<int> sortTransformedArray(vector<int> &nums, int a, int b, int c) {
        int n = nums.size();
        std::vector<int> ans(n);
        auto F = [&](int x) -> int { return a * x * x + b * x + c; };
        int left = 0, right = n - 1;
        if (a >= 0) {
            int k = n - 1;
            while (left <= right) {
                int l = F(nums[left]), r = F(nums[right]);
                if (l >= r) {
                    ans[k--] = l;
                    ++left;
                } else {
                    ans[k--] = r;
                    --right;
                }
            }
        } else {
            int k = 0;
            while (left <= right) {
                int l = F(nums[left]), r = F(nums[right]);
                if (l <= r) {
                    ans[k++] = l;
                    ++left;
                } else {
                    ans[k++] = r;
                    --right;
                }
            }
        }
        return ans;
    }
};
