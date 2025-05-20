#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0, m = 0;
	std::cin >> n >> m;

	std::vector<int> fa(n + 2, -1);
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
	auto Unite = [&](int from, int to) -> void {
		from = Find(from);
		to = Find(to);
		if (from != to) {
			fa[from] = to;
		}
	};

	int l = 0, r = 0, curr = n;
	for (int i = 0; i < m; i++) {
		std::cin >> l >> r;
		for (int j = Find(l); j <= r; j = Find(j + 1)) {
			Unite(j, j + 1);
			--curr;
		}
		std::cout << curr << '\n';
	}
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
