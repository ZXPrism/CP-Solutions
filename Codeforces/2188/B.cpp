#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <unordered_map>
#include <vector>

using u64 = unsigned long long;
using i64 = long long;

void preprocess() {
}

void solve() {
	int n = 0;
	std::cin >> n;

	std::string s;
	std::cin >> s;

	int ans = 0;
	for (auto ch : s) {
		if (ch == '1') {
			++ans;
		}
	}

	std::vector<int> dp(n);
	for (int i = 3; i < n; i++) {
		dp[i] = 1 + std::min(dp[i - 2], dp[i - 3]);
	}

	auto get_2 = [&](int x) -> int {
		if (x > 2) {
			return 1 + std::min(dp[x - 1], dp[x - 2]);
		} else if (x == 2) {
			return 1;
		}
		return 0;
	};

	int left = 0;
	while (left < n) {
		if (s[left] == '1') {
			++left;
			continue;
		}
		int right = left + 1;
		while (right < n && s[right] == '0') {
			++right;
		}

		int len = right - left;
		if (left == 0 && right == n) {
			// 1?
			// 01?
			// A -> B
			if (len > 1) {
				ans += 1 + std::min(get_2(len - 1), get_2(len - 2));
			} else {
				++ans;
			}
		} else if (left == 0 || right == n) {  // B
			ans += get_2(len);
		} else if (len > 2) {
			// 101...1
			// 1001...1
			// 1 + min(x_{len-2}, x_{len-3})
			//
			ans += dp[len];
		}

		left = right;
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
