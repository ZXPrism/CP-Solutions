#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <unordered_map>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void preprocess() {
}

void solve() {
	int n = 0;
	int m = 0;
	std::cin >> n >> m;

	std::vector<std::vector<int>> adj(n);
	for (int i = 0; i < m; i++) {
		int u = 0;
		int v = 0;
		std::cin >> u >> v;
		u--;
		v--;
		adj[v].push_back(u);
	}

	std::vector<int> color(n);
	auto dfs = [&](auto &&self, int node) {
		if (color[node] == 1) {
			return;
		}
		color[node] = 1;
		for (auto neighbor : adj[node]) {
			self(self, neighbor);
		}
	};

	int q = 0;
	std::cin >> q;

	for (int i = 0; i < q; i++) {
		int op = 0;
		int target = 0;
		std::cin >> op >> target;
		target--;

		if (op == 1) {
			dfs(dfs, target);
		} else {
			std::cout << (color[target] == 1 ? "Yes\n" : "No\n");
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	preprocess();

	int t = 1;
	// std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
