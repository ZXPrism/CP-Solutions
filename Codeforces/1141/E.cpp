#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	i64 hp = 0;
	int n = 0;
	std::cin >> hp >> n;

	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}

	i64 min_pre = std::numeric_limits<i64>::max();
	std::vector<i64> pre(n + 1);
	for (int i = 0; i < n; i++) {
		pre[i + 1] = pre[i] + v[i];
		min_pre = std::min(min_pre, pre[i + 1]);
		if (hp + pre[i + 1] <= 0) {
			std::cout << i + 1 << '\n';
			return;
		}
	}
	if (pre[n] >= 0) {
		std::cout << "-1\n";
		return;
	}

	i64 cnt = (hp + min_pre) / -pre[n], ans = cnt * n;
	hp += cnt * pre[n];
	for (int i = 0; i < 2 * n; i++) {
		if (hp + pre[i % n + 1] + (i >= n ? pre[n] : 0) <= 0) {
			ans += i + 1;
			break;
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
