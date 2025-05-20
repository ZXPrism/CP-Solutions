#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0, m = 0;
	std::cin >> n >> m;

	std::vector<int> deg(n);
	std::vector<std::vector<int>> from(n);
	for (int i = 0; i < m; i++) {
		int u = 0, v = 0;
		std::cin >> u >> v;
		--u, --v;
		from[v].push_back(u);
		++deg[u];
	}

	std::queue<int> q;
	std::vector<int> dp(n);
	for (int i = 0; i < n; i++) {
		if (!deg[i]) {
			q.push(i);
			dp[i] = 1;
		}
	}

	int ans = 0;
	constexpr int MOD = 8011'2002;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		if (from[curr].empty()) {
			ans = (ans + dp[curr]) % MOD;
		}
		for (auto adj : from[curr]) {
			dp[adj] = (dp[adj] + dp[curr]) % MOD;
			if (--deg[adj] == 0) {
				q.push(adj);
			}
		}
	}

	std::cout << ans << '\n';
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
