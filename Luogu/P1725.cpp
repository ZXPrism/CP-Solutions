#include "bits/stdc++.h"

using u64 = unsigned long long;
using i64 = long long;

constexpr int INF = 0x3f3f3f3f;

void solve() {
	int n = 0, l = 0, r = 0;
	std::cin >> n >> l >> r;

	std::vector<int> v(n + 1);
	for (int i = 0; i < n + 1; i++) {
		std::cin >> v[i];
	}

	std::vector<int> dp(n + 1, -INF);
	dp[0] = 0;
	std::deque<int> deq;
	for (int i = 1; i <= n; i++) {
		if (i >= l) {
			while (!deq.empty() && dp[i - l] >= dp[deq.back()]) {
				deq.pop_back();
			}
			deq.push_back(i - l);
			dp[i] = dp[deq.front()] + v[i];
		}
		if (i >= r) {
			while (!deq.empty() && deq.front() <= i - r) {
				deq.pop_front();
			}
		}
	}

	std::cout << *std::max_element(dp.begin() + n + 1 - r, dp.end()) << '\n';
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
