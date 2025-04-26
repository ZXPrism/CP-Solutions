class Solution {
public:
	int countLargestGroup(int n) {
		auto num = std::to_string(n);
		int len = num.size();

		std::vector<std::vector<int>> memo(len,
		                                   std::vector<int>(len * 9 + 1, -1));

		auto dfs = [&](this auto &&dfs, int i, int remain, bool is_lim) -> int {
			if (i == len) {
				return remain == 0;
			}
			if (!is_lim && memo[i][remain] != -1) {
				return memo[i][remain];
			}
			int res = 0;
			int up = (is_lim ? num[i] - '0' : 9);
			for (int d = 0; d <= std::min(remain, up); d++) {
				res += dfs(i + 1, remain - d, is_lim && d == up);
			}
			if (!is_lim) {
				memo[i][remain] = res;
			}
			return res;
		};

		int ans = 0, max_size = 0;
		for (int i = 1; i <= len * 9; i++) {
			int curr = dfs(0, i, true);
			if (curr > max_size) {
				max_size = curr;
				ans = 1;
			} else if (curr == max_size) {
				++ans;
			}
		}

		return ans;
	}
};
