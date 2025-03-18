class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        std::string sv(s);
        int n = s.size();
        std::vector<int> dp(n + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for (auto &word : wordDict) {
                int len = word.size();
                if (i + 1 >= len && sv.substr(i - len + 1, len) == word) {
                    dp[i + 1] |= dp[i - len + 1];
                }
            }
        }
        return dp[n];
    }
};
