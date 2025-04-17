#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

constexpr int MOD = 998'244'353;

void solve() {
	int n = 0;
	std::cin >> n;

	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}

	std::vector<int> factorial(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		factorial[i] = (1LL * factorial[i - 1] * i) % MOD;
	}

	int ans = 1, cnt = n;
	std::vector<int> fenwick(n + 1);

	auto Add = [&](int x) -> void {
		while (x <= n) {
			++fenwick[x];
			x += x & -x;
		}
	};

	auto Qry = [&](int x) -> int {
		int res{};
		while (x) {
			res += fenwick[x];
			x &= x - 1;
		}
		return res;
	};

	for (int i = 0; i < n - 1; i++) {
		ans = (ans + 1LL * (v[i] - 1 - Qry(v[i] - 1)) * factorial[cnt - 1]) % MOD;
		Add(v[i]);
		--cnt;
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
