#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;

	int used = 0;
	for (auto ch : s) {
		used |= 1 << (ch - 'a');
	}

	std::vector<int> id(26);
	for (int i = 0, j = 0; i < 26; i++) {
		if (used >> i & 1) {
			id[i] = ++j;
		}
	}

	std::vector<int> cirno(11);
	auto Modify = [&](int x) -> void {
		while (x <= 26) {
			--cirno[x];
			x += x & -x;
		}
	};
	auto Qry = [&](int x) -> int {
		int res{};
		while (x) {
			res += cirno[x];
			x &= x - 1;
		}
		return res;
	};

	for (int i = 1; i <= 10; i++) {
		++cirno[i];
		int j = i + (i & -i);
		if (j <= 10) {
			cirno[j] += cirno[i];
		}
	}

	std::vector<int> fac(10, 1);
	for (int i = 1; i < 10; i++) {
		fac[i] = fac[i - 1] * i;
	}

	int ans = 0, n = s.size();
	for (int i = 0; i < n; i++) {
		int curr = id[s[i] - 'a'];
		ans += Qry(curr - 1) * fac[n - i - 1];
		Modify(curr);
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
