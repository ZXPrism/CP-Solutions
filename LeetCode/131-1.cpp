class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        std::vector<std::vector<std::string>> ans;
        std::vector<std::vector<int>> dp(n, std::vector<int>(n, 1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i][j] = (s[i] == s[j]) && dp[i - 1][j + 1];
            }
        }
        std::vector<std::string> curr;
        auto dfs = [&](this auto &&dfs, int start) {
            if (start == n) {
                ans.push_back(curr);
                return;
            }
            for (int i = start; i < n; i++) {
                if (dp[i][start]) {
                    curr.push_back(s.substr(start, i - start + 1));
                    dfs(i + 1);
                    curr.pop_back();
                }
            }
        };
        dfs(0);
        return ans;
    }
};
