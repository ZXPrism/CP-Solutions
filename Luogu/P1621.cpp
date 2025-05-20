#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

constexpr int N = 100'000;
std::vector<int> fac[N + 1];

auto Init = []() {
	for (int i = 2; i <= N; i++) {
		if (fac[i].empty()) {
			for (int j = i; j <= N; j += i) {
				fac[j].push_back(i);
			}
		}
	}
	return 0;
}();

void solve() {
	int a = 0, b = 0, p = 0;
	std::cin >> a >> b >> p;

	int n = b - a + 1;
	std::vector<int> fa(n + b + 1, -1);
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

	for (int i = 0; i < n; i++) {
		for (auto factor : fac[i + a]) {
			if (factor >= p) {
				Unite(i, n + factor);
			}
		}
	}

	std::unordered_set<int> check;
	for (int i = 0; i < n; i++) {
		check.insert(Find(i));
	}

	std::cout << check.size() << '\n';
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
