#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0, k = 0;
	std::cin >> n >> k;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	std::vector<int> b(n);
	for (int i = 0; i < n; i++) {
		std::cin >> b[i];
	}

	bool unique = false;
	int x = 0;
	for (int i = 0; i < n; i++) {
		if (b[i] != -1) {
			unique = true;
			x = a[i] + b[i];
			break;
		}
	}

	if (unique) {
		for (int i = 0; i < n; i++) {
			if (b[i] != -1) {
				if (a[i] + b[i] != x) {
					std::cout << "0\n";
					return;
				}
			} else if (x - a[i] < 0 || x - a[i] > k) {
				std::cout << "0\n";
				return;
			}
		}
		std::cout << "1\n";
	} else {
		auto [min_elem, max_elem] = std::ranges::minmax_element(a);
		std::cout << std::max(0LL, 1LL * *min_elem + k - *max_elem + 1) << '\n';
	}
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
