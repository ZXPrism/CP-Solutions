#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0, m = 0;
	std::cin >> n >> m;

	std::vector<int> indeg(n);
	std::vector<std::vector<int>> from(n);
	for (int i = 0; i < m; i++) {
		int u = 0, v = 0;
		std::cin >> u >> v;
		--u, --v;
		from[v].push_back(u);
		++indeg[u];
	}

	std::queue<int> q;
	for (int i = 0; i < n; i++) {
		if (!indeg[i]) {
			q.push(i);
		}
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		for (auto adj : from[node]) {
			if (--indeg[adj] == 0) {
				q.push(adj);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (indeg[i]) {
			++ans;
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
