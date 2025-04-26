#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

constexpr int MOD = 1'000'000'7;

void solve() {
	i64 n = 0;
	std::cin >> n;

	auto num = std::format("{:b}", n);
	int len = num.size();

	std::vector<std::vector<int>> memo(len, std::vector<int>(len, -1));
	auto dfs = [&](auto &&self, int i, int sum, bool is_lim) -> int {
		if (i == len) {
			return std::max(1, sum);
		}
		if (!is_lim && memo[i][sum] != -1) {
			return memo[i][sum];
		}
		int res = 1;
		int up = (is_lim ? num[i] - '0' : 1);
		for (int d = 0; d <= up; d++) {
			res = (1LL * res * self(self, i + 1, sum + d, is_lim && d == up)) % MOD;
		}
		if (!is_lim) {
			memo[i][sum] = res;
		}
		return res;
	};

	std::cout << dfs(dfs, 0, 0, true) << '\n';
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
