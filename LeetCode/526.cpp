class Solution {
public:
	int countArrangement(int n) {
		std::vector<int> dp(1 << n);

		dp[0] = 1;
		for (int i = 1; i < (1 << n); i++) {
			int k = __builtin_popcount(i);
			for (int j = 1; j <= n; j++) {
				if ((i >> (j - 1) & 1) && (j % k == 0 || k % j == 0)) {
					dp[i] += dp[i ^ (1 << (j - 1))];
				}
			}
		}

		return dp.back();
	}
};
