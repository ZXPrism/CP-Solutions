#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int V = 0, G = 0;
	std::cin >> V >> G;

	int n = 0;
	std::cin >> n;

	std::vector<int> power(n), volume(n), weight(n);
	for (int i = 0; i < n; i++) {
		std::cin >> power[i] >> volume[i] >> weight[i];
	}

	std::vector<std::vector<i64>> dp(V + 1, std::vector<i64>(G + 1));
	for (int i = 0; i < n; i++) {
		for (int j = V; j >= volume[i]; j--) {
			for (int k = G; k >= weight[i]; k--) {
				dp[j][k] = std::max(dp[j][k], dp[j - volume[i]][k - weight[i]] + power[i]);
			}
		}
	}

	std::cout << dp[V][G] << '\n';
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
