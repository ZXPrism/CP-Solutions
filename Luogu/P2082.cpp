#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0;
	std::cin >> n;

	std::vector<std::pair<i64, i64>> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i].first >> v[i].second;
	}

	std::ranges::sort(v);

	i64 ans = 0;
	int left = 0;
	while (left < n) {
		int right = left + 1;
		i64 max_end = v[left].second;
		while (right < n && v[right].first <= max_end) {
			max_end = std::max(max_end, v[right].second);
			++right;
		}
		ans += max_end - v[left].first + 1;
		left = right;
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
