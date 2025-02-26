class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int> &vals) {
        std::vector<int> value(26);
        std::iota(value.begin(), value.end(), 1);
        for (int i = 0; auto ch : chars) {
            value[ch - 'a'] = vals[i++];
        }
        int n = s.size(), ans = 0;
        std::vector<int> dp(n + 1);
        for (int i = 0; i < n; i++) {
            int v = value[s[i] - 'a'];
            dp[i + 1] = std::max(dp[i] + v, v);
            ans = std::max(ans, dp[i + 1]);
        }
        return ans;
    }
};
