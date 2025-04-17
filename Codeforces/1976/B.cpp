#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> b(n + 1);
	for (int i = 0; i < n + 1; i++) {
		std::cin >> b[i];
	}

	i64 ans = 0;
	for (int i = 0; i < n; i++) {
		ans += std::abs(a[i] - b[i]);
	}

	int dist = std::numeric_limits<int>::max();
	for (int i = 0; i < n; i++) {
		if ((a[i] <= b.back() && b.back() <= b[i]) ||
		    (b[i] <= b.back() && b.back() <= a[i])) {
			std::cout << ans + 1 << '\n';
			return;
		} else if (a[i] <= std::min(b[i], b.back()) || a[i] >= std::max(b[i], b.back())) {
			dist = std::min(dist, std::abs(b[i] - b.back()));
		} else {
			dist = std::min(dist, std::abs(a[i] - b.back()));
		}
		// ai target bi -> 0
		// bi target ai -> 0
		// target bi ai -> bi - target
		// target ai bi -> ai - target
		// ai bi target -> target - bi
		// bi ai target -> target - ai
	}

	std::cout << ans + 1 + dist << '\n';
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
