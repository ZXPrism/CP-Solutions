class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size(), max_len = 1, start = 0;
		std::vector<int> dp(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (s[i] == s[j]) {
					dp[j] = dp[j + 1] + 2;
				} else {
					dp[j] = -n - 1;
				}
				if (dp[j] > max_len) {
					max_len = dp[j];
					start = j;
				}
			}
			dp[i] = 1;
		}
		return s.substr(start, max_len);
	}
};
