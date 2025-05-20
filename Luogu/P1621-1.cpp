#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int a = 0, b = 0, p = 0;
	std::cin >> a >> b >> p;

	int n = b - a + 1;
	std::vector<int> fa(n, -1);
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

	int ans = n;
	auto Unite = [&](int from, int to) -> void {
		from = Find(from);
		to = Find(to);
		if (from != to) {
			fa[from] = to;
			--ans;
		}
	};

	std::vector<int> vis(b + 1);
	for (int i = 2; i <= b; i++) {
		if (!vis[i]) {
			for (int j = i; j <= b; j += i) {
				vis[j] = 1;
				if (i >= p && j >= a && j + i <= b) {
					Unite(j - a, j + i - a);
				}
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
