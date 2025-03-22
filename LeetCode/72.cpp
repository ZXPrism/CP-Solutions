class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        std::vector<int> dp(n2 + 1);
        for (int j = 0; j < n2; j++) {
            dp[j + 1] = dp[j] + 1;
        }
        for (int i = 0; i < n1; i++) {
            int t = dp[0];
            ++dp[0];
            for (int j = 0; j < n2; j++) {
                int tt = dp[j + 1];
                if (word1[i] == word2[j]) {
                    dp[j + 1] = t;
                } else {
                    dp[j + 1] = std::min({t, dp[j], dp[j + 1]}) + 1;
                }
                t = tt;
            }
        }
        return dp[n2];
    }
};
