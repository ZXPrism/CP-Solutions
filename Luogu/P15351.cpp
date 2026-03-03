#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void preprocess() {
}

void solve() {
	int n = 0;
	int q = 0;
	std::cin >> n >> q;

	i64 max_l = 0;
	i64 max_r = 0;

	i64 min_l = 0;
	i64 min_mid = 0;
	i64 min_r = 0;

	for (int i = 0; i < q; i++) {
		char s = 0;
		int x = 0;
		std::cin >> s >> x;

		if (s == 'L') {
			max_l += x;
			if (n % 2 == 1) {
				if (x == n / 2) {
					min_l += 1;
				} else if (x == (n + 1) / 2) {
					min_l += 2;
					min_mid++;
				}
			} else {
				min_l += static_cast<int>(x == n / 2);
			}
		} else if (s == 'R') {
			max_r += x;
			if (n % 2 == 1) {
				if (x == n / 2) {
					min_r += 1;
				} else if (x == (n + 1) / 2) {
					min_r += 2;
					min_mid++;
				}
			} else {
				min_r += static_cast<int>(x == n / 2);
			}
		} else {
			max_l += x;
			max_r += x;
			min_l += static_cast<int>(x == n);
			min_r += static_cast<int>(x == n);
			min_mid += static_cast<int>(x == n);
		}
	}

	if (n == 1) {
		std::cout << "0\n";
	} else {
		i64 max = std::max(max_l, max_r);
		i64 min = std::min({ min_l, min_r });
		if (n % 2 == 1) {
			min = std::min(min, min_mid);
		}
		std::cout << max - min << '\n';
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	preprocess();

	int t = 1;
	// std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
