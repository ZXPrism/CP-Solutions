class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        std::vector<int> dp(n + 1, n + 1);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                int len = i - j + 1;
                bool flag = true;
                for (int k = 0; k < len / 2; k++) {
                    if (s[j + k] != s[i - k]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    dp[i + 1] = std::min(dp[i + 1], dp[j] + 1);
                }
            }
        }

        return dp[n] - 1;
    }
};
