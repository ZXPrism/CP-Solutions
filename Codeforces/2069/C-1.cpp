#include <iostream>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void solve() {
	int n = 0;
	std::cin >> n;

	std::vector<int> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i];
	}

	std::vector<int> pre(n + 1);
	for (int i = 0; i < n; i++) {
		pre[i + 1] = pre[i] + (v[i] == 2);
	}

	constexpr i64 MOD = 998'244'353;
	std::vector<int> pwr2(n + 1, 1);
	for (int i = 1; i < n; i++) {
		pwr2[i] = 1LL * pwr2[i - 1] * 2 % MOD;
	}

	i64 ans = 0;
	i64 prev_term = 0;
	int last_3 = 0;
	int cnt3 = 0;
	for (int left = 0, right = 0; right < n; right++) {
		if (v[right] == 3) {
			i64 curr_term = prev_term * pwr2[pre[right] - pre[last_3]] % MOD;
			while (left <= right) {
				if (v[left] == 1) {
					curr_term = (curr_term + pwr2[pre[right] - pre[left]]) % MOD;
				}
				++left;
			}
			ans = (ans + curr_term) % MOD;

			++cnt3;
			last_3 = right;
			prev_term = curr_term;

			int cnt1 = right + 1 - cnt3 - pre[right + 1];
			ans = (ans - cnt1 + MOD) % MOD;
		}
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
