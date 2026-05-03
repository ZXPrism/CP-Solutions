#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void preprocess() {
}

void solve() {
	int n = 0;
	int m = 0;
	std::cin >> n >> m;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	const int csqrt = static_cast<int>(std::ceil(std::sqrt(static_cast<double>(n))));

	std::vector<std::vector<int>> lut(csqrt + 1, std::vector<int>(csqrt + 1));
	for (int i = 1; i <= csqrt; i++) {
		for (int j = 0; j < i; j++) {
			int start = (j == 0 ? i : j);
			for (int k = start; k <= n; k += i) {
				lut[i][j] += a[k];
			}
		}
	}

	for (int _ = 0; _ < m; _++) {
		char cmd = 0;
		int x = 0;
		int y = 0;

		std::cin >> cmd >> x >> y;
		if (cmd == 'A') {
			int res = 0;
			if (x > csqrt) {
				int start = (y == 0 ? x : y);
				for (int i = start; i <= n; i += x) {
					res += a[i];
				}
			} else {
				res = lut[x][y];
			}
			std::cout << res << '\n';
		} else {
			for (int i = 1; i <= csqrt; i++) {
				lut[i][x % i] += y - a[x];
			}
			a[x] = y;
		}
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
