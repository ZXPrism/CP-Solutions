#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	i64 n = 0, m = 0, k = 0;
	std::cin >> n >> m >> k;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::ranges::sort(a);

	std::vector<int> b(m);
	for (int i = 0; i < m; i++) {
		std::cin >> b[i];
	}
	std::ranges::sort(b);

	auto check = [&](int x) -> bool {
		i64 cnt = 0;
		int left = 0, right = m - 1;
		while (left < n && right >= 0) {
			int sum = a[left] + b[right];
			if (sum <= x) {
				cnt += right + 1;
				++left;
			} else {
				--right;
			}
		}
		return cnt >= k;
	};

	int left = 1, right = a.back() + b.back() + 1, mid = 0;
	while (left + 1 < right) {
		mid = left + (right - left) / 2;
		if (check(mid)) {
			right = mid;
		} else {
			left = mid;
		}
	}

	std::cout << right << '\n';
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
