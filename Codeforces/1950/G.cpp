#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0;
	std::cin >> n;

	std::unordered_map<std::string, int> hash_g, hash_w;
	std::vector<std::string> g(n), w(n);
	for (int i = 0; i < n; i++) {
		std::cin >> g[i] >> w[i];
		if (!hash_g.contains(g[i])) {
			int id = hash_g.size();
			hash_g[g[i]] = id;
		}
		if (!hash_w.contains(w[i])) {
			int id = hash_w.size();
			hash_w[w[i]] = id;
		}
	}

	std::vector<int> gi(n), wi(n);
	for (int i = 0; i < n; i++) {
		gi[i] = hash_g[g[i]];
		wi[i] = hash_w[w[i]];
	}

	std::vector<std::vector<int>> dp(n, std::vector<int>(1 << n));
	for (int i = 0; i < n; i++) {
		dp[i][1 << i] = 1;
	}

	for (int i = 0; i < (1 << n); i++) {
		for (int j = 0; j < n; j++) {
			if (!dp[j][i]) {
				continue;
			}
			for (int k = 0; k < n; k++) {
				if ((~i >> k & 1) && (gi[k] == gi[j] || wi[k] == wi[j])) {
					dp[k][i | (1 << k)] = 1;
				}
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (1 << n); j++) {
			if (dp[i][j]) {
				ans = std::max(ans, __builtin_popcount(j));
			}
		}
	}

	std::cout << n - ans << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
