class Solution {
public:
    int maxAbsoluteSum(vector<int> &nums) {
        int n = nums.size(), ans = 0;
        int a = 0, b = 0;
        for (int i = 0; i < n; i++) {
            a = std::max(a + nums[i], nums[i]);
            b = std::min(b + nums[i], nums[i]);
            ans = std::max({ans, std::abs(a), std::abs(b)});
        }
        return ans;
    }
};
