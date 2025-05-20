#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0, m = 0, k = 0;
	std::cin >> n >> m >> k;

	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		int t = 0;
		for (int j = 0; j < k; j++) {
			std::cin >> t;
			v[i] |= 1 << (t - 1);
		}
	}

	std::vector<int> dp(1 << m, n + 1);
	dp[0] = 0;
	for (int i = 0; i < (1 << m); i++) {
		if (dp[i] != n + 1) {
			for (int j = 0; j < n; j++) {
				dp[i | v[j]] = std::min(dp[i | v[j]], dp[i] + 1);
			}
		}
	}

	std::cout << (dp.back() == n + 1 ? -1 : dp.back()) << '\n';
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
