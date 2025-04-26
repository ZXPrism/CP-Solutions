class Solution {
public:
	int longestValidParentheses(string s) {
		int n = s.size(), ans = 0;
		std::vector<int> dp(n + 1);
		for (int i = 1; i < n; i++) {
			if (s[i] == ')') {
				if (s[i - 1] == '(') {
					dp[i + 1] = dp[i - 1] + 2;
				} else {
					if (i - 1 - dp[i] >= 0 && s[i - 1 - dp[i]] == '(') {
						dp[i + 1] = dp[i] + 2 + dp[i - 1 - dp[i]];
					}
				}
				ans = std::max(ans, dp[i + 1]);
			}
		}
		return ans;
	}
};
