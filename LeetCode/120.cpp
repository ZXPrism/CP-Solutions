class Solution {
public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int m = triangle.size();
        std::vector<int> dp(m);

        for (int i = 0; i < m; i++) {
            int t = 0;
            for (int j = 0; j <= i; j++) {
                int tt = dp[j];
                if (i == 0 && j == 0) {
                    dp[j] = triangle[i][j];
                } else if (j == 0) {
                    dp[j] += triangle[i][j];
                } else if (j == i) {
                    dp[j] = t + triangle[i][j];
                } else {
                    dp[j] = std::min(t, dp[j]) + triangle[i][j];
                }
                t = tt;
            }
        }

        return *std::ranges::min_element(dp);
    }
};
