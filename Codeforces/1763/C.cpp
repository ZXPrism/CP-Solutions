#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void preprocess() {
}

void solve() {
	int n = 0;
	std::cin >> n;

	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}

	int max_elem = *std::max_element(a.begin(), a.end());

	if (n >= 4) {
		std::cout << 1LL * max_elem * n << '\n';
	} else if (n == 2) {
		int orig = a[0] + a[1];
		int diff = std::abs(a[0] - a[1]);
		std::cout << std::max(orig, diff * 2) << '\n';
	} else if (n == 3) {
		if (a[0] == max_elem || a[2] == max_elem) {
			std::cout << 1LL * max_elem * 3 << '\n';
		} else {
			i64 orig = 1LL * a[0] + a[1] + a[2];
			int diff = std::abs(a[0] - a[2]);
			int diff_1 = a[1] - a[0];
			int diff_2 = a[1] - a[2];
			std::cout << std::max({
			                 orig,
			                 3LL * diff,
			                 3LL * diff_1,
			                 3LL * diff_2,
			                 3LL * a[0],
			                 3LL * a[2],
			             })
			          << '\n';
			// a M b
			// |a-b| |a-b| |a-b|
			// M-a M-a b
			// a M-b M-b
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	preprocess();

	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
