#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0, m = 0;
	std::cin >> n >> m;

	std::vector<std::vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u = 0, v = 0;
		std::cin >> u >> v;
		--u, --v;
		adj[u].push_back(v);
	}

	std::vector<int> color(n);
	auto dfs = [&](auto &&self, int node) -> bool {
		if (color[node]) {
			return color[node] == 1;
		}
		color[node] = 1;
		for (auto neighbor : adj[node]) {
			if (self(self, neighbor)) {
				return true;
			}
		}
		color[node] = 2;
		return false;
	};

	for (int i = 0; i < n; i++) {
		dfs(dfs, i);
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		ans += (color[i] == 1);
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
