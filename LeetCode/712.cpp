class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n1 = s1.size(), n2 = s2.size();
        std::vector<int> dp(n2 + 1);
        for (int i = 0; i < n2; i++) {
            dp[i + 1] = dp[i] + s2[i];
        }
        for (int i = 0; i < n1; i++) {
            int t = dp[0];
            dp[0] += s1[i];
            for (int j = 0; j < n2; j++) {
                int tt = dp[j + 1];
                if (s1[i] == s2[j]) {
                    dp[j + 1] = t;
                } else {
                    dp[j + 1] = std::min(dp[j] + s2[j], dp[j + 1] + s1[i]);
                }
                t = tt;
            }
        }
        return dp[n2];
    }
};
