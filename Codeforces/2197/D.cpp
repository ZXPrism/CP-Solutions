#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void preprocess() {
}

void solve() {
	// ai * aj = j - i < n
	//
	// 4 cases: decompose by VALUE
	// ai < csqrt(n) & aj < csqrt(n)
	// ai < csqrt(n) & aj >= csqrt(n)
	// ai >= csqrt(n) & aj >= csqrt(n) ---> INVALID
	// ai >= csqrt(n) & aj < csqrt(n)
	//
	// if ai or aj is large, we don't need to check many steps
	// j = i + k * aj -> i = j - k * aj, at most csqrt(n) steps
	// j = i + ai * k, at most csqrt(n) steps
	//
	// if both ai and aj is small, we can check them by brute force: at most csqrt(n) steps

	int n = 0;
	std::cin >> n;

	const int csqrtn = static_cast<int>(std::ceil(std::sqrt(static_cast<double>(n))));

	std::vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
	}

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int aj = 1; aj < csqrtn; aj++) {
			i64 j = i + 1LL * a[i] * aj;
			if (j > n) {
				break;
			}
			if (a[j] == aj) {
				++ans;
			}
		}
	}

	for (int j = 1; j <= n; j++) {
		if (a[j] >= csqrtn) {
			for (int ai = 1; ai < csqrtn; ai++) {
				i64 i = j - 1LL * ai * a[j];
				if (i <= 0) {
					break;
				}
				if (a[i] == ai) {
					++ans;
				}
			}
		}
	}

	std::cout << ans << '\n';
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
