#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

constexpr int P = 1'000'7;

void solve() {
	int n = 0, m = 0;
	std::cin >> n >> m;

	std::vector<int> nums(n);
	for (int i = 0; i < n; i++) {
		std::cin >> nums[i];
	}

	std::vector<int> colors(n);
	for (int i = 0; i < n; i++) {
		std::cin >> colors[i];
	}

	std::vector<std::vector<int>> groups(m + 1);
	for (int i = 0; i < n; i++) {
		groups[colors[i]].push_back(i);
	}

	int ans = 0;
	for (auto &pos : groups) {
		i64 even = 0, odd = 0;
		i64 even_idx_sum = 0, odd_idx_sum = 0;
		i64 even_num_sum = 0, odd_num_sum = 0;
		int even_cnt = 0, odd_cnt = 0;

		for (auto elem : pos) {
			i64 curr = 1LL * nums[elem] * (elem + 1);
			if (elem % 2 == 0) {
				ans = (ans + odd_cnt * curr + (elem + 1) * odd_num_sum + nums[elem] * odd_idx_sum + odd) % P;
				odd += curr;
				odd_num_sum += nums[elem];
				odd_idx_sum += elem + 1;
				++odd_cnt;
			} else {
				ans = (ans + even_cnt * curr + (elem + 1) * even_num_sum + nums[elem] * even_idx_sum + even) % P;
				even += curr;
				even_num_sum += nums[elem];
				even_idx_sum += elem + 1;
				++even_cnt;
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
