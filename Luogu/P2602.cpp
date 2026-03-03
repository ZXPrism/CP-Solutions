#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void preprocess() {
}

void solve() {
	i64 a = 0;
	i64 b = 0;
	std::cin >> a >> b;

	std::string sa = std::to_string(a);
	std::string sb = std::to_string(b);
	while (sa.length() != sb.length()) {
		sa = "0" + sa;
	}

	for (int d = 0; d <= 9; d++) {
		std::vector<std::pair<i64, i64>> memo(sb.length(), { -1, -1 });
		auto dfs = [&](this auto &&dfs, int kth_digit, bool leading_zero, bool low_tight, bool up_tight) -> std::pair<i64, i64> {
			if (kth_digit == sb.length()) {
				return { 0, 1 };
			}

			if (!leading_zero && !low_tight && !up_tight && memo[kth_digit].first != -1) {
				return memo[kth_digit];
			}

			int low = (low_tight ? sa[kth_digit] - '0' : 0);
			int up = (up_tight ? sb[kth_digit] - '0' : 9);

			std::pair<i64, i64> res;

			for (int i = low; i <= up; i++) {
				auto next = dfs(kth_digit + 1, leading_zero && i == 0, low_tight && i == low, up_tight && i == up);
				res.first += next.first;
				res.second += next.second;

				if (i == d && (i != 0 || !leading_zero)) {
					res.first += next.second;
				}
			}

			if (!leading_zero && !low_tight && !up_tight) {
				memo[kth_digit] = res;
			}

			return res;
		};

		std::cout << dfs(0, true, true, true).first << ' ';
	}

	std::cout << '\n';
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
