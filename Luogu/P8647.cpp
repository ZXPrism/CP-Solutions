#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0, k = 0;
	std::cin >> n >> k;

	std::vector<int> h(n), w(n);
	for (int i = 0; i < n; i++) {
		std::cin >> h[i] >> w[i];
	}

	auto check = [&](int x) -> bool {
		i64 tot = 0;
		for (int i = 0; i < n; i++) {
			tot += 1LL * (h[i] / x) * (w[i] / x);
		}
		return tot >= k;
	};

	int left = 1, right = 1'000'01, mid = 0;
	while (left + 1 < right) {
		mid = (left + right) >> 1;
		if (check(mid)) {
			left = mid;
		} else {
			right = mid;
		}
	}

	std::cout << left << '\n';
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
