class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        std::vector<int> dp(n2 + 1);
        for (int i = 0; i < n1; i++) {
            int t = 0;
            for (int j = 0; j < n2; j++) {
                int tt = dp[j + 1];
                if (text1[i] == text2[j]) {
                    dp[j + 1] = t + 1;
                } else {
                    dp[j + 1] = std::max(dp[j + 1], dp[j]);
                }
                t = tt;
            }
        }
        return dp[n2];
    }
};
