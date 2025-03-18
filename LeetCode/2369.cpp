class Solution {
public:
    bool validPartition(vector<int> &nums) {
        int n = nums.size();
        std::vector<int> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            if (i >= 1) {
                if (nums[i - 1] == nums[i]) {
                    dp[i + 1] |= dp[i - 1];
                    if (i >= 2) {
                        if (nums[i - 2] == nums[i - 1]) {
                            dp[i + 1] |= dp[i - 2];
                        }
                    }
                }
                if (i >= 2) {
                    if (nums[i - 2] + 1 == nums[i - 1] && nums[i - 1] + 1 == nums[i]) {
                        dp[i + 1] |= dp[i - 2];
                    }
                }
            }
        }
        return dp[n];
    }
};
