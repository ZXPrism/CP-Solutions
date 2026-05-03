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

	if (k == n) {
		for (int i = 1, j = 1; i < n; i += 2, ++j) {
			if (v[i] != j) {
				std::cout << j << '\n';
				return;
			}
		}
		std::cout << n / 2 + 1 << '\n';
	} else {
		for (int i = 1; i < n; i++) {
			if (v[i] != 1) {
				if (n - i >= k - 1) {
					std::cout << "1\n";
				} else {
					std::cout << "2\n";
				}
				return;
			}
		}
		std::cout << "2\n";
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
