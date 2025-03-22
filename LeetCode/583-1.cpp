class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        std::vector<std::vector<int>> dp(n1 + 1, std::vector<int>(n2 + 1));
        for (int i = 0; i < n1; i++) {
            dp[i + 1][0] = i + 1;
        }
        for (int i = 0; i < n2; i++) {
            dp[0][i + 1] = i + 1;
        }
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (word1[i] == word2[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    dp[i + 1][j + 1] =
                        std::min(dp[i][j] + 2, std::min(dp[i + 1][j], dp[i][j + 1]) + 1);
                }
            }
        }
        return dp[n1][n2];
    }
};
