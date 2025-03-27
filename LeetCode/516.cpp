class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();

        std::vector<int> dp(n);
        for (int i = n - 1; i >= 0; i--) {
            int t = dp[i];
            dp[i] = 1;
            for (int j = i + 1; j < n; j++) {
                int tt = dp[j];
                if (s[i] == s[j]) {
                    dp[j] = t + 2;
                } else {
                    dp[j] = std::max(dp[j], dp[j - 1]);
                }
                t = tt;
            }
        }

        return dp[n - 1];
    }
};
