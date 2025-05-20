#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0;
	std::cin >> n;

	std::vector<std::vector<int>> dist(n, std::vector<int>(n));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> dist[i][j];
		}
	}

	constexpr int inf = 0x3f3f3f3f;
	std::vector<std::vector<int>> dp(n, std::vector<int>(1 << n, inf));
	dp[0][1] = 0;

	for (int i = 1; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (i >> j & 1) {
				for (int k = 0; k < n; k++) {
					if (~i >> k & 1) {
						dp[k][i | (1 << k)] = std::min(dp[k][i | (1 << k)], dp[j][i] + dist[j][k]);
					}
				}
			}
		}
	}

	std::cout << dp[n - 1].back() << '\n';
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
