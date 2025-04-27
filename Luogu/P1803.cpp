#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0;
	std::cin >> n;

	std::vector<std::pair<int, int>> segments(n);
	for (int i = 0; i < n; i++) {
		std::cin >> segments[i].first >> segments[i].second;
	}

	std::ranges::sort(segments, {}, [](auto &i) { return i.second; });

	int last_right = -1, ans = 0;
	for (int i = 0; i < n; i++) {
		if (segments[i].first >= last_right) {
			++ans;
			last_right = segments[i].second;
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
