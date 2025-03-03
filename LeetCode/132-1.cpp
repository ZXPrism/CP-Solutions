class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        std::vector<std::vector<int>> ok(n + 1, std::vector<int>(n + 1));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                ok[i][j] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (i != j && s[i] == s[j]) {
                    ok[i][j] = ok[i - 1][j + 1];
                }
            }
        }

        std::vector<int> dp(n + 1, n + 1);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                if (ok[i][j]) {
                    dp[i + 1] = std::min(dp[i + 1], dp[j] + 1);
                }
            }
        }

        return dp[n] - 1;
    }
};
