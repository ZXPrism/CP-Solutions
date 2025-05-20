class Solution {
public:
	int findMinimumTime(vector<int> &strength, int k) {
		int n = strength.size();
		std::vector<int> dp(1 << n, 0x3f3f3f3f);
		dp[0] = 0;
		for (int i = 1; i < (1 << n); i++) {
			int cnt = __builtin_popcount(i) - 1;
			int curr = 1 + cnt * k;
			for (int j = 0; j < n; j++) {
				if (i >> j & 1) {
					dp[i] = std::min(dp[i], dp[i ^ (1 << j)] +
					                            (strength[j] + curr - 1) / curr);
				}
			}
		}
		return dp.back();
	}
};
