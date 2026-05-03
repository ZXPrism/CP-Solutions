#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0;
	std::cin >> n;

	std::vector<int> cnt(1001);
	for (int i = 0, x = 0; i < n; i++) {
		std::cin >> x;
		++cnt[x];
	}

	constexpr i64 MOD = 1'000'000'007;
	auto comb = [](int n, int k) -> i64 {
		if (k > n) {
			return 0;
		}
		i64 res = 1;
		for (int i = 1; i <= k; i++) {
			res = (res * (n - i + 1)) % MOD;
		}
		return res;
	};

	i64 ans = 0;
	for (int a = 1; a < 1001; a++) {
		for (int b = 1; b < 1001; b++) {
			if (a == b) {
				ans = (ans + comb(cnt[a], 4)) % MOD;
			} else {
				ans = (ans + comb(cnt[a], 2) * comb(cnt[b], 2)) % MOD;
			}
		}
	}

	std::cout << ans << '\n';
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
