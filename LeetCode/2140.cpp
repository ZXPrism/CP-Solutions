class Solution {
public:
    long long mostPoints(vector<vector<int>> &questions) {
        int n = questions.size();
        std::vector<long long> dp(n + 1);
        for (int i = n - 1; i >= 0; i--) {
            dp[i] = std::max(dp[i + 1], dp[std::min(n, i + questions[i][1] + 1)] + questions[i][0]);
        }
        return dp[0];
    }
};
