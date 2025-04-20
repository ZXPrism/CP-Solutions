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

	i64 pre = 0, pre_min = std::numeric_limits<i64>::max();
	for (int i = 0; i < n; i++) {
		pre += v[i];
		if (hp + pre <= 0) {
			std::cout << i + 1 << '\n';
			return;
		}
		pre_min = std::min(pre_min, pre);
	}

	if (pre >= 0) {
		std::cout << "-1\n";
		return;
	}

	// hp + k * pre + pre_min <= 0
	// k * pre <= -hp - pre_min
	// k >= (hp + pre_min) / pre
	i64 cnt = (hp + pre_min - pre - 1) / -pre;
	hp += cnt * pre;
	i64 curr = 0;
	for (int i = 0; i < n; i++) {
		curr += v[i];
		if (hp + curr <= 0) {
			std::cout << cnt * n + i + 1 << '\n';
			return;
		}
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
