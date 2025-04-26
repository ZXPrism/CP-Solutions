#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n_v = 0, n = 0;
	std::cin >> n_v >> n;

	std::vector<int> v(n_v);
	for (int i = 0; i < n_v; i++) {
		std::cin >> v[i];
	}

	auto num = std::to_string(n);
	int len = num.size();

	std::vector<int> memo(len, -1);
	auto dfs = [&](this auto &&dfs, int i, bool is_lim, bool zero) -> int {
		if (i == len) {
			return !zero;
		}
		if (!is_lim && !zero && memo[i] != -1) {
			return memo[i];
		}
		int res = 0;
		if (zero) {
			res = dfs(i + 1, false, true);
		}
		int up = (is_lim ? num[i] - '0' : 9);
		for (auto d : v) {
			if (d > up) {
				break;
			}
			res += dfs(i + 1, is_lim && d == up, false);
		}
		if (!is_lim && !zero) {
			memo[i] = res;
		}
		return res;
	};

	std::cout << dfs(0, true, true) << '\n';
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
