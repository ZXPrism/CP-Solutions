#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0, x = 0;
	std::cin >> n >> x;

	if (n == 1 && x == 0) {
		std::cout << "-1\n";
		return;
	}

	if (x == 0) {
		if (n & 1) {
			std::cout << n + 3 << '\n';
		} else {
			std::cout << n << '\n';
		}
	} else {
		int cnt = __builtin_popcount(x);
		if (n >= cnt) {
			int remain = n - cnt;
			if (remain % 2 == 0) {
				std::cout << x + remain << '\n';
			} else if (cnt == 1) {
				if (x == 1) {
					std::cout << x + remain + 3 << '\n';
				} else {
					std::cout << x + remain + 1 << '\n';
				}

			} else {
				std::cout << x + remain + 1 << '\n';
			}
		} else {
			std::cout << x << '\n';
		}
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
