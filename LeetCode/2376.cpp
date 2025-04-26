class Solution {
public:
	int countSpecialNumbers(int n) {
		auto num = std::to_string(n);
		int len = num.size();
		std::vector<std::vector<int>> memo(len, std::vector<int>(1 << 10, -1));
		auto dfs = [&](this auto &&dfs, int i, int mask, bool is_lim,
		               bool leading_zero) -> int {
			if (i == len) {
				return !leading_zero;
			}
			if (!is_lim && !leading_zero && memo[i][mask] != -1) {
				return memo[i][mask];
			}

			int res = 0;
			if (leading_zero) {
				res = dfs(i + 1, 0, false, true);
			}
			int up = (is_lim ? num[i] - '0' : 9);
			for (int d = leading_zero; d <= up; d++) {
				if (~mask >> d & 1) {
					res +=
					    dfs(i + 1, mask | (1 << d), is_lim && d == up, false);
				}
			}

			if (!is_lim && !leading_zero) {
				memo[i][mask] = res;
			}

			return res;
		};
		return dfs(0, 0, true, true);
	}
};
