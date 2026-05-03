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

	int left = 0, ans = 0;
	while (left < n) {
		if (v[left] == 1) {
			++left;
			continue;
		}

		int right = left + 1;
		while (right < n && v[right] == 0) {
			++right;
		}
		ans += (right - left + 1) / (k + 1);

		left = right;
	}

	std::cout << ans << '\n';
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
