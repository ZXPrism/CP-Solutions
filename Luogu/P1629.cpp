#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

struct Edge {
	int to;
	int weight;

	bool operator<(const Edge &rhs) const { return weight > rhs.weight; };
};

void solve() {
	int n = 0, m = 0;
	std::cin >> n >> m;

	std::vector<std::vector<Edge>> from(n);
	std::vector<std::vector<Edge>> from_rev(n);
	for (int i = 0; i < m; i++) {
		int u = 0, v = 0, w = 0;
		std::cin >> u >> v >> w;
		--u, --v;
		from[u].push_back({ v, w });
		from_rev[v].push_back({ u, w });
	}

	constexpr int INF = 0x3f3f3f3f;
	std::vector<int> dist(n, INF), dist_rev(n, INF);

	auto dijkstra = [](std::vector<int> &dist, std::vector<std::vector<Edge>> &graph) {
		dist[0] = 0;
		std::priority_queue<Edge> heap;
		heap.push({ 0, 0 });
		while (!heap.empty()) {
			auto [from, d] = heap.top();
			heap.pop();
			if (dist[from] < d) {
				continue;
			}
			for (auto [to, w] : graph[from]) {
				if (d + w < dist[to]) {
					dist[to] = d + w;
					heap.push({ to, dist[to] });
				}
			}
		}
	};

	dijkstra(dist, from);
	dijkstra(dist_rev, from_rev);

	i64 ans = std::reduce(dist.begin(), dist.end(), 0LL) +
	          std::reduce(dist_rev.begin(), dist_rev.end(), 0LL);
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
