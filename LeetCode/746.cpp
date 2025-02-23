class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        // dp[n] = min(dp[n - 2] + cost[n - 2], dp[n - 1] + cost[n - 1])
        // dp[0] = 0, dp[1] = 0
        int n = cost.size();

        std::vector<int> dp(n + 1);

        for (int i = 2; i <= n; i++) {
            dp[i] = std::min(dp[i - 2] + cost[i - 2], dp[i - 1] + cost[i - 1]);
        }

        return dp[n];
    }
};
