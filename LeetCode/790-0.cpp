class Solution {
public:
	int numTilings(int n) {
		constexpr int MOD = 1'000'000'007;
		std::vector<int> dp(n + 1);
		dp[0] = 1;
		int pre = 1;
		for (int i = 0; i < n; i++) {
			dp[i + 1] = dp[i];
			if (i > 0) {
				dp[i + 1] = (dp[i + 1] + dp[i - 1]) % MOD;
			}
			if (i > 1) {
				dp[i + 1] =
				    (dp[i + 1] + 2LL * (pre - dp[i] - dp[i - 1]) + 4LL * MOD) %
				    MOD;
			}
			pre = (pre + dp[i + 1]) % MOD;
		}
		return dp[n];
	}
};
