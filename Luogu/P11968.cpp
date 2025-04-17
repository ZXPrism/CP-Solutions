#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	u64 x = 0, k = 0;
	std::cin >> x >> k;

	auto comb = [](int n, int a) -> u64 {
		if (a > n - a) {
			a = n - a;
		}
		u64 res = 1;
		for (int i = 1; i <= a; i++) {
			res = res * (n - i + 1) / i;
		}
		return res;
	};

	auto kth = [&](int n, int set, u64 id) -> u64 {
		u64 res = 0;
		int cnt[2] = { n - set, set };
		for (int i = n - 1; i >= 0; i--) {
			for (int j = 0; j <= 1; j++) {
				if (!cnt[j]) {
					continue;
				}
				--cnt[j];
				u64 curr = comb(i, cnt[j]);
				if (curr >= id) {
					res |= 1LL * j << i;
					break;
				}
				id -= curr;
				++cnt[j];
			}
		}
		return res;
	};

	u64 left = 0, right = comb(61, k) + 1, mid = 0;
	while (left + 1 < right) {
		mid = (left + right) >> 1;
		if (kth(61, k, mid) <= x) {
			left = mid;
		} else {
			right = mid;
		}
	}

	std::cout << std::min(x - kth(61, k, left),
	                      kth(61, k, left + 1) - x)
	          << '\n';
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
