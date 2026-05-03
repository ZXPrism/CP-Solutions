#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0, k = 0;
	std::cin >> n >> k;

	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}

	int curr = v[k - 1];
	std::ranges::sort(v);
	int idx = std::ranges::lower_bound(v, curr) - v.begin();

	int h = 1;
	for (int i = idx + 1; i < n; i++) {
		int delta = v[i] - v[i - 1];
		if (h + delta > v[i - 1] + 1) {
			std::cout << "NO\n";
			return;
		}
		h += delta;
	}

	std::cout << "YES\n";
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
