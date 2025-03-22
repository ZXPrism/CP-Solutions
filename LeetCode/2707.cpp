class Solution {
public:
    int minExtraChar(string s, vector<string> &dictionary) {
        int n = s.size();
        std::vector<int> dp(n + 1);
        std::string_view sv(s);
        for (int i = 0; i < n; i++) {
            dp[i + 1] = dp[i] + 1;
            for (auto &word : dictionary) {
                int len = word.size();
                if (i + 1 >= len && word == sv.substr(i - len + 1, len)) {
                    dp[i + 1] = std::min(dp[i + 1], dp[i + 1 - len]);
                }
            }
        }
        return dp[n];
    }
};
