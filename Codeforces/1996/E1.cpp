#include <iostream>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	std::string s;
	std::cin >> s;

	constexpr i64 MOD = 1'000'000'007;
	i64 ans = 0;

	int n = s.size();
	std::vector<int> cnt(2 * n + 2);
	for (int i = 0, pre = 0; i < n; i++) {
		ans = (ans + 1LL * (n - i) * cnt[2 * (pre + (s[i] == '0')) - (i + 1) + n]) % MOD;
		auto &x = cnt[2 * pre - i + n];
		x = (x + i + 1) % MOD;
		pre += (s[i] == '0');
	}

	std::cout << ans << '\n';
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
