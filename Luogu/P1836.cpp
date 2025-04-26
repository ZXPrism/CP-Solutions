#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0;
	std::cin >> n;

	std::string num = std::to_string(n);
	int len = num.size();

	std::vector<std::vector<i64>> memo(len, std::vector<i64>(100, -1));
	auto dfs = [&](auto &&self, int i, i64 sum, bool is_lim, bool leading_zero) -> i64 {
		if (i == len) {
			return sum;
		}
		if (!is_lim && !leading_zero && memo[i][sum] != -1) {
			return memo[i][sum];
		}
		i64 res = 0;
		if (leading_zero) {
			res = self(self, i + 1, 0, false, true);
		}
		int up = (is_lim ? num[i] - '0' : 9);
		for (int d = leading_zero; d <= up; d++) {
			res += self(self, i + 1, sum + d, is_lim && d == up, false);
		}
		if (!is_lim && !leading_zero) {
			memo[i][sum] = res;
		}
		return res;
	};

	std::cout << dfs(dfs, 0, 0, true, true) << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	// std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
