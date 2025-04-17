#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0;
	std::cin >> n;
	n = 1 << n;

	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}

	auto Get = [&](auto &&self, int left, int right) -> std::pair<int, int> {
		if (left == right) {
			return { left, left };
		}
		int mid = (left + right) >> 1;
		auto [win_l, lose_l] = self(self, left, mid);
		auto [win_r, lose_r] = self(self, mid + 1, right);
		if (v[win_l] > v[win_r]) {
			return { win_l, win_r };
		}
		return { win_r, win_l };
	};

	std::cout << Get(Get, 0, n - 1).second + 1 << '\n';
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
