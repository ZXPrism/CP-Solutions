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
	std::cin >> n;

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	const int sqrtn = static_cast<int>(std::sqrt(static_cast<double>(n)));
	// dp[k][p]: how many steps needed if starting from p with param k
	std::vector<std::vector<int>> dp(sqrtn + 1, std::vector<int>(n + 1));
	for (int k = 1; k <= sqrtn; k++) {
		for (int p = n; p >= 1; p--) {
			int next = p + a[p] + k;
			if (next > n) {
				dp[k][p] = 1;
			} else {
				dp[k][p] = 1 + dp[k][next];
			}
		}
	}

	int q = 0;
	std::cin >> q;

	for (int i = 0; i < q; i++) {
		int p = 0;
		int k = 0;
		std::cin >> p >> k;

		if (k <= sqrtn) {
			std::cout << dp[k][p] << '\n';
		} else {
			int res = 0;
			while (p <= n) {
				p += a[p] + k;
				++res;
			}
			std::cout << res << '\n';
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
