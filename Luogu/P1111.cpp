#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0, m = 0;
	std::cin >> n >> m;

	std::vector<int> time(m);
	std::vector<std::pair<int, int>> road(m);
	for (int i = 0; i < m; i++) {
		std::cin >> road[i].first >> road[i].second >> time[i];
	}
	std::vector<int> idx(m);
	std::iota(idx.begin(), idx.end(), 0);
	std::ranges::sort(idx, {}, [&](int i) -> int { return time[i]; });

	int cnt = n;
	std::vector<int> fa(n + 1, -1);
	auto Find = [&](int x) -> int {
		int root = x;
		while (fa[root] >= 0) {
			root = fa[root];
		}
		while (fa[x] >= 0) {
			int y = fa[x];
			fa[x] = root;
			x = y;
		}
		return root;
	};
	auto Union = [&](int from, int to) -> void {
		from = Find(from);
		to = Find(to);
		if (from != to) {
			fa[from] = to;
			--cnt;
		}
	};

	for (auto i : idx) {
		Union(road[i].first, road[i].second);
		if (cnt == 1) {
			std::cout << time[i] << '\n';
			return;
		}
	}

	std::cout << "-1\n";
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
