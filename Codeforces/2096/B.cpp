#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0, k = 0;
	std::cin >> n >> k;

	std::vector<int> l(n), r(n);
	for (int i = 0; i < n; i++) {
		std::cin >> l[i];
	}
	for (int i = 0; i < n; i++) {
		std::cin >> r[i];
	}

	i64 ans = 1;
	std::vector<int> remain(n);
	for (int i = 0; i < n; i++) {
		if (l[i] >= r[i]) {
			ans += l[i];
			remain[i] = r[i];
		} else {
			ans += r[i];
			remain[i] = l[i];
		}
	}

	std::ranges::sort(remain, std::greater<>());
	if (k > 1) {
		ans += std::reduce(remain.begin(), remain.begin() + k - 1, 0LL);
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
