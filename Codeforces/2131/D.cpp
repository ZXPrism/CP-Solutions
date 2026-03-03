#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void preprocess() {
}

void solve() {
	int n = 0;
	std::cin >> n;

	std::vector<int> deg(n + 1);
	std::vector<std::vector<int>> adj(n + 1);
	for (int i = 0; i < n - 1; i++) {
		int u = 0;
		int v = 0;
		std::cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		++deg[u];
		++deg[v];
	}

	if (n == 2) {
		std::cout << "0\n";
	} else {
		int leave_cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (deg[i] == 1) {
				++leave_cnt;
			}
		}

		int ans = n + 1;
		for (int i = 1; i <= n; i++) {
			int curr = leave_cnt;
			if (adj[i].size() == 1) {
				--curr;
			}
			for (auto child : adj[i]) {
				if (adj[child].size() == 1) {
					--curr;
				}
			}
			ans = std::min(ans, curr);
		}

		std::cout << ans << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	preprocess();

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
