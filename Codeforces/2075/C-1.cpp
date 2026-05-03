#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0, m = 0;
	std::cin >> n >> m;

	std::vector<int> v(m);
	for (int i = 0; i < m; i++) {
		std::cin >> v[i];
	}

	std::ranges::sort(v);

	std::vector<int> left(m), right(m);
	for (int i = 0; i < m; i++) {
		left[i] = std::min(v[i], n - 1) + 1;
	}
	for (int i = 0; i < m; i++) {
		right[i] = std::max(1, n - v[i]);
	}

	std::vector<i64> pre_left(m + 1);
	for (int i = 0; i < m; i++) {
		pre_left[i + 1] = pre_left[i] + left[i];
	}

	i64 ans = 0;
	int L = 0, R = m - 1;
	while (L < R) {
		int sum = v[L] + v[R];
		if (sum >= n) {
			ans += 2 * (pre_left[R] - pre_left[L] - 1LL * (R - L) * right[R]);
			--R;
		} else {
			++L;
		}
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
