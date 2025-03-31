class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), maxlen = 1, start = 0;
        std::vector<std::vector<int>> dp(n, std::vector<int>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                dp[i][j] = (s[i] == s[j] ? dp[i - 1][j + 1] + 2 : -n - 1);
                if (dp[i][j] > maxlen) {
                    maxlen = dp[i][j];
                    start = j;
                }
            }
        }
        return s.substr(start, maxlen);
    }
};
