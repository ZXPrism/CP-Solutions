#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0, m = 0;
	std::cin >> n >> m;

	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}

	int hb = std::bit_width(static_cast<unsigned>(n)) - 1;
	std::vector<std::vector<int>> st(hb + 1);
	st[0].swap(v);
	for (int i = 1; i <= hb; i++) {
		int len = n - (1 << i) + 1;
		st[i].resize(len);
		for (int j = 0; j < len; j++) {
			st[i][j] = std::gcd(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
		}
	}

	int l = 0, r = 0;
	for (int i = 0; i < m; i++) {
		std::cin >> l >> r;
		--l, --r;
		int p = std::bit_width(static_cast<unsigned>(r - l + 1)) - 1;
		std::cout << std::gcd(st[p][l], st[p][r - (1 << p) + 1]) << '\n';
	}
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
