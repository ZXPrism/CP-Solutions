class Solution {
public:
    vector<int> sortedSquares(vector<int> &nums) {
        int n = nums.size();
        int left = 0, right = n - 1, k = n - 1;
        std::vector<int> ans(n);
        while (left <= right) {
            int l = nums[left] * nums[left], r = nums[right] * nums[right];
            if (l >= r) {
                ans[k--] = l;
                ++left;
            } else {
                ans[k--] = r;
                --right;
            }
        }
        return ans;
    }
};
