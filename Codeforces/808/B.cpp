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

	i64 tot = 0, curr = 0;
	for (int i = 0; i < n; i++) {
		curr += v[i];
		if (i >= k - 1) {
			tot += curr;
			curr -= v[i - k + 1];
		}
	}

	std::cout << std::format("{:.8f}", 1.0 * tot / (n - k + 1)) << '\n';
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
